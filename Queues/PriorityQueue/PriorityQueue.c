#include <stdio.h>
#include "PriorityQueue.h"

int compPR(HData d1, HData d2) /* function that produces priority comparing two HDatas */
{
    return d1 <= d2 ? 1 : 0;
}

void InitPrQ(PrQueue *q) /* function that initializes Priority Queue */
{
    InitHeap(&(q->hp), compPR);
}

void Enqueue(PrQueue *q, HData data) /* function that enqueues data */
{
    HInsert(&(q->hp), data);
}

HData Dequeue(PrQueue *q) /* function that dequeues data */
{
    return HDelete(&(q->hp));
}

void PrintPrQ(PrQueue *q) /* function that prints the priority queue */
{
    PrintHeap(&(q->hp));
}

int IsEmpty(PrQueue *q) /* function that indicates whether the queue is empty */
{
  if(q->hp.numofData <= 0){
    return TRUE;
  }
  return FALSE;
}

int IsFull(PrQueue *q) /* function that indicates whether the queue is full */
{
  if(q->hp.numofData >= MAXNUM){
    return TRUE;
  }
  return FALSE;
}

void Clear(PrQueue *q) /* function that clears all datas and itself */
{
  while(q->hp.numofData > 0){
    Dequeue(q);
  }
}