#ifndef __PRIORITYQUEUE_H__
#define __PRIORITYQUEUE_H__

#include "Heap.h"

typedef struct __prqueue
{
    Heap hp;
} PrQueue;

int compPR(HData d1, HData d2); /* function that produces priority comparing two HDatas */

void InitPrQ(PrQueue *q); /* function that initializes Priority Queue */

void Enqueue(PrQueue *q, HData data); /* function that enqueues data */

HData Dequeue(PrQueue *q); /* function that dequeues data */

int IsEmpty(PrQueue *q); /* function that indicates whether the queue is empty */

int IsFull(PrQueue *q); /* function that indicates whether the queue is full */

void Clear(PrQueue *q); /* function that clears all datas and itself */

void PrintPrQ(PrQueue *q); /* function that prints the priority queue */

#endif