#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

typedef struct __node /* structure of the node */
{
    int data;
    struct __node *next;
} Node;

typedef struct __linkedlist /* structure of the LilnkedList */
{
    Node *head; /* node that points the head of linkedlist */
    Node *curt; /* node that points the current node of linkedlist; it is renewed consistently by insert and removal */
} LinkedList;

typedef LinkedList Llist; /* rename the LinkedList as List */

void InitList(Llist *list); /* function that initializes the linkedlist */

Node *SetNode(const int data, Node *next); /* function that allocates and makes new node and points to next node */

void InsertFront(Llist *list, const int data); /* function that insert the new node at head of linkedlist */

void InsertRear(Llist *list, const int data); /* function that inserts the new node at tail of linkedlist */

int RemoveFront(Llist *list); /* function that removes a node at head of linkedlist */

int RemoveRear(Llist *list); /* function that removes a node at tail of linkedlist */

int RemoveCur(Llist *list); /* function that removes a node that Node curt points */

int Search(Llist *list, const int data); /* function that finds a node which data is same as the input data by using function compare*/

void Clear(Llist *list); /* function that deletes all nodes */

void PrintList(const Llist *list); /* function that prints the whole datas of the linkedlist */

#endif