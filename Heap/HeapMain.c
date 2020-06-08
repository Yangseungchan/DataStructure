#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"

int main(void){

  Heap hp;
  InitHeap(&hp);
  HInsert(&hp, 'A', 1);
  HInsert(&hp, 'B', 3);


  return 0;
}