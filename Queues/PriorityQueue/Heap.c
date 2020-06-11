#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"

void InitHeap(Heap *hp, PRComp prc) /* function that initializes the Heap */
{
  hp->cmp = prc;
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
    return hp->cmp(hp->HNArr[leftchildidx].data, hp->HNArr[rightchildidx].data) == 1 ? leftchildidx : rightchildidx;
    /* return the index of the child node which has higher priority(=lower priority value) */
  }
}

void HInsert(Heap *hp, HData data)
{
  HNode nde;

  int parentidx, childidx;

  childidx = hp->numofData + 1;
  if (hp->numofData >= 2) /* below processes are done only if the numofdata is more than 1 */
  {
    parentidx = GetParentIdx(childidx);
    while (hp->cmp(data, hp->HNArr[parentidx].data)) /* repeated until new inserted node's pr is higher than parent node; remember that the higher the prioirty, the lower the pr value is */
    {
      hp->HNArr[childidx] = hp->HNArr[parentidx]; /* change the node at childidx as the node at parentidx */
      childidx = parentidx;
      parentidx = GetParentIdx(childidx);
      if (parentidx <= 0)
      {
        break;
      }
    }
  }
  nde.data = data;
  hp->HNArr[childidx] = nde;
  hp->numofData++;
}

HData HDelete(Heap *hp)
{
  int parentidx, childidx;
  HData retData = hp->HNArr[1].data;

  parentidx = 1;
  hp->numofData--;                          /* numofData should be decreased by 1 as it affects the function GetHighPrChIdx */
  childidx = GetHighPrChIdx(hp, parentidx); /* child node index which has the highest priority */

  while (childidx = GetHighPrChIdx(hp, parentidx))
  /* why childidx should not be 0?-> as func GetHighPrChIdx returns 0 when it has no left child of given index's node*/
  {
    if (hp->cmp(hp->HNArr[hp->numofData].data, hp->HNArr[childidx].data)) /* should be repeated until parent node's priority is lower than the highest child node's priority */
    {
      break;
    }
    hp->HNArr[parentidx] = hp->HNArr[childidx];
    parentidx = childidx;
  }
  hp->HNArr[parentidx].data = hp->HNArr[hp->numofData + 1].data;

  return retData;
}

void PrintHeap(const Heap *hp) /* function that prints the heap in array */
{
  if (hp->numofData <= 0)
  {
    printf("EMPTY\n");
  }
  else
  {
    for (int i = 1; i <= hp->numofData; i++)
    {
      printf("%c ", hp->HNArr[i].data);
    }
    putchar('\n');
  }
}