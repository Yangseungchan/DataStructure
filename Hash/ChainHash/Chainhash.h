#ifndef __CHAINHASH_H__
#define __CHAINHASH_H__

#include "Member.h"

typedef struct __node
{
  Member member;
  struct __node *next;
} Node;

typedef struct __chainhash
{
  int size;
  Node **ChainNode; /* Node Pointer Array; Each element contains Node Pointer that's why it is set as double pointer */
} ChainHash;

void Initialize(ChainHash *chain, int size); /* function that initializes the hashtable including allocation, setting size of table */

Node *SetNodeInfo(Member mem, Node *next); /* function that sets the information of the Node */

int HashFunc(int no, ChainHash *chain); /* function that gives the hash key using the member no */

int Add(ChainHash *chain, Member data); /* function that adds the new node to hash table */

int Delete(ChainHash *chain, Member data);

void PrintHash(ChainHash *chain); /* function that prints the all nodes in hashtable in order of the keys */

#endif