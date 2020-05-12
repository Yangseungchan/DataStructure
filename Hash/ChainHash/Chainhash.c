#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Member.h"
#include "Chainhash.h"

void Initialize(ChainHash *chain, int size)
{
  chain->ChainNode = calloc(size, sizeof(Node *));
  for (int i = 0; i < size; i++)
  {
    chain->ChainNode[i] = NULL;
  }
  chain->size = size;
}

int HashFunc(char *name, ChainHash *chain)
{
  int sum = 0;
  int len = strlen(name);
  for (int i = 0; i < len; i++)
  {
    sum += (int)name[i];
  }
  return sum % chain->size;
}

Node *SetNodeInfo(Member data, Node *next)
{
  Node *nde = calloc(1, sizeof(Node)); /* allocation of new node */

  nde->member.no = data.no; /* setting member's no and name */
  strcpy(nde->member.name, data.name);

  /* Are these two sentences can be replaced with "nde->member = data"? */

  nde->next = next; /* setting new node */

  return nde;
}

int Add(ChainHash *chain, Member data)
{
  int key = HashFunc(data.name, chain);
  Node *tmp;
  Node *new_nde = SetNodeInfo(data, NULL); /* Those jobs are done by this func : allocation, setting node's values, setting next pointer */

  if (!chain->ChainNode[key])
  {
    chain->ChainNode[key] = new_nde;
  }
  else
  {
    tmp = chain->ChainNode[key];
    do
    {
      if (cmpMemberName(&tmp->member, &data) == 0 || cmpMemberNo(&tmp->member, &data) == 0) /* When two member's name or no are same */
      {
        return -1;
      }
      if (!(tmp->next))
      { /*this roop is repeated until the next node is NULL */
        break;
      }
      tmp = tmp->next;
    } while (1);
    tmp->next = new_nde; /* connecting the node in the assigned key with new added node */
  }
  return 0;
}

int Delete(ChainHash *chain, char *name) /* function that deletes the node which has same name with input in hashtable */
{
  int key = HashFunc(name, chain);
  Node *tmp = chain->ChainNode[key];
  Node *prev = NULL;
  while (tmp)
  {
    if (!strcmp(tmp->member.name, name))
    {
      if (prev)
      { /* when prev is not NULL */
        prev->next = tmp->next;
      }
      else
      { /* when prev is NULL = tmp is just the node that is pointed by chain->ChainNode[key] */
        chain->ChainNode[key] = tmp->next;
      }
      tmp->next = NULL;
      free(tmp);
      return 0;
    }
    prev = tmp;
    tmp = tmp->next;
  }
  return -1;
}

int Search(ChainHash *chain, char *name) /* function that finds the node in hashtable using name */
{
  int key = HashFunc(name, chain);
  Node *tmp = chain->ChainNode[key];
  while (tmp)
  {
    if (!strcmp(tmp->member.name, name))
    {
      return key;
    }
    tmp = tmp->next;
  }
  return -1;
}

void Terminate(ChainHash *chain)
{ /* function that deallocates the hashtable */
  Node *ptr;
  Node *next;
  for (int i = 0; i < chain->size; i++)
  { /* On each key index */
    ptr = chain->ChainNode[i];
    while (ptr)
    { /* disallocation of each node is done until all of them are disallocated*/
      next = ptr->next;
      ptr->next = NULL;
      free(ptr);
      ptr = next;
    }
    free(chain->ChainNode[i]);
  }
}

void PrintHash(ChainHash *chain)
{
  int i, size;
  size = chain->size;
  Node *ptr;
  printf("====================<Printing HashTable>====================\n");
  for (i = 0; i < size; i++)
  {
    printf("    [%2d] -> ", i);
    ptr = chain->ChainNode[i];
    if (!ptr)
    { /* when ptr points nothing(NULL) */
      printf("[NULL]\n");
    }
    else
    {
      while (ptr->next)
      {
        PrintMember(&ptr->member);
        printf(" -> ");
        ptr = ptr->next;
      }
      PrintMemberln(&ptr->member);
    }
  }
  printf("=============================================================\n\n\n");
}