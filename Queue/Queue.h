#ifndef __QUEUE_H__
#define __QUEUE_H__

#define TRUE 1
#define FALSE -1
#define MAX 10

typedef struct __Queue{
    int *arr;  /* array that contains datas*/
    int max;   /* maximum number of array space*/
    int num;   /* current number of datas in Queue */
    int front; /* front index */
    int rear;  /* rear index */
}Queue;

void InitQueue(Queue *q);   /* function that initializes the queue */

void Enqueue(Queue *q, int data);   /* function that enqueues the data */

void Dequeue(Queue *q);             /* function that dequeues the first input data */

int Search(Queue *q, int target);   /* function that searches the data which is same as input data */

int IsEmpty(Queue *q);  /* function that indicates whether it is empty Queue */

int IsFull(Queue *q);   /* function that indicates whether it is full Queue */

void Clear(Queue *q);   /* function that clears all datas in Queue */

void PrintQueue(Queue *q);  /* function that prints all datas in Queue */


#endif