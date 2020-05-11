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

void Initialize(ChainHash *chain, int size);

Node *SetNodeInfo(Member mem, Node *next);

int HashFunc(int no, ChainHash *chain);

int Add(ChainHash *chain, Member data);

int Delete(ChainHash *chain, Member data);

#endif __CHAINHASH_H__