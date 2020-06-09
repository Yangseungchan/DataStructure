#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

void InitQueue(Queue *q) /* function that initializes the queue */
{
    q->arr = calloc(MAX, sizeof(int));
    q->max = MAX;
    q->num = 0;
    q->front = q->rear = 0;
}

void Enqueue(Queue *q, int data) /* function that enqueues the data */
{
    if (q->num < q->max)
    {
        q->arr[q->rear++] = data;
        if (q->rear >= q->max)
        {
            q->rear -= q->max;
        }
        q->num++;
    }
}

void Dequeue(Queue *q) /* function that dequeues the first input data */
{
    if (q->num > 0)
    {
        q->arr[q->front++] = 0;
        if (q->front >= q->max)
        {
            q->front -= q->max;
        }
        q->num--;
    }
}

int Search(Queue *q, int target) /* function that searches the data which is same as input data */
{
    int count = 0;
    for (size_t i = q->front; count < q->num; i++, count++)
    {
        if (i >= q->max)
        {
            i -= q->max;
        }
        if (q->arr[i] == target)
        {
            return i;
        }
    }
    return FALSE;
}

int IsEmpty(Queue *q) /* function that indicates whether it is empty Queue */
{
    if ((q->front == q->rear) && (q->num == 0))
    {
        return TRUE;
    }
    return FALSE;
}

int IsFull(Queue *q) /* function that indicates whether it is full Queue */
{
    if ((q->front == q->rear) && (q->num == q->max))
    {
        return TRUE;
    }
    return FALSE;
}

void Clear(Queue *q) /* function that clears all datas in Queue */
{
    while (q->num > 0)
    {
        Dequeue(q);
    }
}

void PrintQueue(Queue *q) /* function that prints all datas in Queue */
{
    int count = 0;
    for (size_t i = q->front; count < q->num; i++, count++)
    {
        if (i >= q->max)
        {
            i -= q->max;
        }
        printf("%d ", q->arr[i]);
    }
    putchar('\n');
}
