#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"

void InitHeap(Heap *hp) /* function that initializes the Heap */
{
  hp->numofData = 0;
}

int GetParentIdx(int idx) /* function that returns the parents' index using given idx */
{
  return idx / 2; 
}

int GetLChildIdx(int idx) /* function that returns the left child's index using given idx */
{
  return idx * 2;
}

int GetRChildIdx(int idx) /* function that returns the right child's index using given idx */
{
  return (2 * idx) + 1;
}

int GetHighPrChIdx(Heap *hp, int idx) /* function that returns child node index which has high priority;  this function is used to delete a node */
{
  int rightchildidx;
  int leftchildidx = GetLChildIdx(idx); 

  if(leftchildidx > hp->numofData)
  {
    return 0;
  }
  else if(leftchildidx == hp->numofData)
  {
    return leftchildidx;
  }
  else
  {
    rightchildidx = GetRChildIdx(idx);
    return hp->HNArr[leftchildidx].pr <= hp->HNArr[rightchildidx].pr ? rightchildidx : leftchildidx;
  }
}

int HInsert(Heap *hp, HData data, Priority pr){
  return 0; 
}

int HDelete(Heap *hp){
  return 0;
}