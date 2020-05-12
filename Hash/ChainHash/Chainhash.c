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

int HashFunc(int no, ChainHash *chain)
{
  return no % chain->size;
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
  int key = HashFunc(data.no, chain);
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
    }while (1);
    tmp->next = new_nde; /* connecting the node in the assigned key with new added node */
  }
  return 0;
}

int Delete(ChainHash *chain, Member data){
  
}

void PrintHash(ChainHash *chain){
  int i, size;
  size = chain->size;
  Node *ptr;
  printf("====================<Printing HashTable>====================\n");
  for(i=0; i<size; i++){
    printf("    [%2d] -> ", i);
    ptr = chain->ChainNode[i];
    if(!ptr){ /* when ptr points nothing(NULL) */
      printf("[NULL]\n");
    }
    else{
      while(ptr->next){
         PrintMember(&ptr->member);
         printf(" -> ");
         ptr = ptr->next;
      }
      PrintMemberln(&ptr->member);
    }
  }
  printf("=============================================================\n\n\n");
}