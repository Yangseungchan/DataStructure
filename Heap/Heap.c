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

int GetHighPrChIdx(Heap *hp, int idx) /* function that returns child node index which has high priority;this function is used to delete a node */
{
  int rightchildidx;
  int leftchildidx = GetLChildIdx(idx);

  if (leftchildidx > hp->numofData) /* leftchild index is bigger than the number of datas = there is no child node */
  {
    return 0;
  }
  else if (leftchildidx == hp->numofData) /* only left-child node exists */
  {
    return leftchildidx;
  }
  else /* left and right child node exists */
  {
    rightchildidx = GetRChildIdx(idx);
    return hp->HNArr[leftchildidx].pr <= hp->HNArr[rightchildidx].pr ? leftchildidx : rightchildidx;
    /* return the index of the child node which has higher priority(=lower priority value) */
  }
}

int HInsert(Heap *hp, HData data, Priority pr)
{
  HNode nde;

  int parentidx, childidx;

  childidx = hp->numofData + 1;
  if(hp->numofData >= 2){ /* below processes are done only if the numofdata is more than 1 */
    parentidx = GetParentIdx(childidx);
    while (pr <= hp->HNArr[parentidx].pr) /* repeated until new inserted node's pr is higher than parent node; remember that the higher the prioirty, the lower the pr value is */
    {
      hp->HNArr[childidx] = hp->HNArr[parentidx]; /* reset the node in childidx with the node in parentidx */
      childidx = parentidx;
      parentidx = GetParentIdx(childidx);
      if(parentidx <= 0){
        break;
      }
    }
  }
  nde.data = data;
  nde.pr = pr;
  hp->HNArr[childidx] = nde;
  hp->numofData++;
  return 0;
}

HData HDelete(Heap *hp)
{
  if(hp->numofData < 1){
    return -1;
  }
  
  int parentidx, childidx;
  Priority pr = hp->HNArr[hp->numofData].pr; /* priortiy of the node which is positioned at the right-lowest node */
  HData retData = hp->HNArr[1].data;

  parentidx = 1;
  hp->numofData--;                          /* numofData should be decreased by 1 as it affects the function GetHighPrChIdx */
  childidx = GetHighPrChIdx(hp, parentidx); /* child node index which has the highest priority */
  while (pr >= hp->HNArr[childidx].pr && childidx > 0)     
   /* repeated until parent node's priority is lower than the highest child node's priority */
   /* why childidx should be bigger than 0?-> as func GetHighPrChIdx returns 0 when it has no left child of given index's node*/
  {
    hp->HNArr[parentidx] = hp->HNArr[childidx];
    parentidx = childidx;
    childidx = GetHighPrChIdx(hp, parentidx);
  }
  hp->HNArr[parentidx].data = hp->HNArr[hp->numofData + 1].data;
  hp->HNArr[parentidx].pr = pr;

  return retData;
}

void PrintHeap(const Heap *hp) /* function that prints the heap in array */
{
  for(int i=1; i <= hp->numofData; i++){
    printf("%c ", hp->HNArr[i].data);
  }
  putchar('\n');
}