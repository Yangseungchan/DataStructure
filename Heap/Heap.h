#ifndef __HEAP_H__
#define __HEAP_H__

#define MAXNUM 100

typedef char HData;
typedef int Priority;

typedef struct __heapnode
{
    HData data;  /* data */
    Priority pr; /* node's priority; the lower pr is, the higher the real priority is */
} HNode;

typedef struct __heap
{
    int numofData;       /* number of datas that is contained by the Heap array = index of last node */
    HNode HNArr[MAXNUM]; /* array that contains HNode; its index is started from 1; 0 should be empty */
} Heap;

void InitHeap(Heap *hp); /* function that initializes the Heap */

int GetParentIdx(int idx); /* function that returns the parents' index using given idx */

int GetLChildIdx(int idx); /* function that returns the left child's index using given idx */

int GetRChildIdx(int idx); /* function that returns the right child's index using given idx */

int GetHighPrChIdx(Heap *hp, int idx); /* function that returns child node index which has high priority; this function is used to delete a node */

int HInsert(Heap *hp, HData data, Priority pr); /* function that inserts new data into heap */

HData HDelete(Heap *hp); /* function that deletes a node which has the highest priority */

void PrintHeap(const Heap *hp); /* function that prints the heap in array */

#endif