#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"

int compPR(HData d1, HData d2)
{
  return d1 <= d2 ? 1 : 0;
}

int main(void)
{

  Heap hp;
  InitHeap(&hp, compPR);
  HInsert(&hp, 'K');
  PrintHeap(&hp);
  printf("\n\n\n");
  HInsert(&hp, 'C');
  PrintHeap(&hp);
  printf("\n\n\n");
  HInsert(&hp, 'Z');
  PrintHeap(&hp);
  printf("\n\n\n");
  HInsert(&hp, 'Y');
  PrintHeap(&hp);
  printf("\n\n\n");
  HInsert(&hp, 'A');
  PrintHeap(&hp);
  printf("\n\n\n");

  printf("===DELETE===\n\n\n");
  printf("DELETE : %c\n", HDelete(&hp));
  printf("DELETE : %c\n", HDelete(&hp));
  printf("DELETE : %c\n", HDelete(&hp));
  printf("DELETE : %c\n", HDelete(&hp));
  printf("DELETE : %c\n", HDelete(&hp));
  return 0;
}