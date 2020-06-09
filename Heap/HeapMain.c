#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"

int main(void){

  Heap hp;
  InitHeap(&hp);
  HInsert(&hp, 'A', 20);
  PrintHeap(&hp); printf("\n\n\n");
  HInsert(&hp, 'B', 5);
  PrintHeap(&hp); printf("\n\n\n");
  HInsert(&hp, 'K', 2);
  PrintHeap(&hp); printf("\n\n\n");
  HInsert(&hp, 'M', 1);
  PrintHeap(&hp); printf("\n\n\n");
  HInsert(&hp, 'X', 50);
  PrintHeap(&hp); printf("\n\n\n");

  printf("===DELETE===\n\n\n");
  printf("DELETE : %c\n", HDelete(&hp));
  printf("DELETE : %c\n", HDelete(&hp));
  printf("DELETE : %c\n", HDelete(&hp));
  printf("DELETE : %c\n", HDelete(&hp));
  printf("DELETE : %c\n", HDelete(&hp));
  return 0;
}