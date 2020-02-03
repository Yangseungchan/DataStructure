#ifndef __DOUBLE_CIRCULAR_LIST_H__
#define __DOUBLE_CIRCULAR_LIST_H__

#define TRUE 0
#define FALSE -1
#define Null -2

typedef struct __node
{
    struct __node *prev;
    struct __node *next;
    int data;
} Node;

typedef struct __circulardoublelist
{
    Node *head;
    Node *curt;
} CircularDoubleList;

typedef CircularDoubleList CDList;

void Initialize(CDList *cdlist); /* It is the function that initializes the CDList */

Node *SetNode(int data, Node *prev, Node *next); /* It is the function that allocates new node and sets the data, prev and next of the new node */

void InsertAfter(CDList *cdlist, int data, Node *p); /* It is the function that inserts new node right after Node p */

void InsertFront(CDList *cdlist, int data); /* It is the function that inserts new node at head node of the CDList */

void InsertRear(CDList *cdlist, int data); /* It is the function that inserts new node at tail node of the CDList */

int Delete(CDList *cdlist, Node *target); /* It is the function that deletes the target node at the CDList */

int DeleteFront(CDList *cdlist); /* It is the function that deletes the head node of the CDList */

int DeleteRear(CDList *cdlist); /* It is the function that deletes the tail node of the CDList */

int DeleteCurt(CDList *cdlist); /* It is the function that deltes the curt node of the CDList */

int Search(CDList *cdlist, int data); /* It is the function that searches the node which is same as the input data */

void PrintCurt(CDList *cdlist); /* It is the function that prints the curt node in the CDList */

void PrintList(CDList *cdlist); /* It is the function that prints the all nodes in the CDList */

void Clear(CDList *cdlist); /* It is the function that clears the CDList by clearing all nodes */

#endif