#ifndef __CHAINHASH_H__
#define __CHAINHASH_H__

typedef struct __node{
  Member member;
  struct __node *next;
}Node;

typedef struct __chainhash{
  int size;
  Node **ChainNode;
}ChainHash;

void Initialize(ChainHash *chain, int size);

int HashFunc(int no, ChainHash *chain);

int Add(ChainHash *chain, Member data);

int Delete(ChainHash *chain, Member data);

#endif __CHAINHASH_H__