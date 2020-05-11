#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "Chainhash.h"

void Initialize(ChainHash *chain, int size){
  chain->ChainNode = calloc(size, sizeof(Node *));
  chain->size = size;
}

int HashFunc(int no, ChainHash *chain){
  return no % chain->size;
}

int Add(ChainHash *chain, Member data){
  int key = HashFunc(data.no, chain);
  while(cmpMemberNo(&data, &chain->ChainNode[key]->member) || cmpMemberName(&data,  &chain->ChainNode[key]->member)){
  
  

  }
}

int Delete(ChainHash *chain, Member data);