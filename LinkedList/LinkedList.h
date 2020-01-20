#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

typedef struct __node
{ /* structure of the node */
    int data;
    struct __node *next;
} Node;

typedef struct __linkedlist
{ /* structure of the LilnkedList */
    Node *head;
    Node *tail;
    int count;

} LinkedList;

typedef LinkedList LList; /* rename the LinkedList as List */

Node *InitNode(); /* function that initializes the Node */

void InitList(LList *llist); /* function that initializes the List */

int InsertData(LList *llist, int data); /* function that inserts a new data */

int DeleteData(LList *llist, int data); /* function that deletes the selected component in list */

int SearchData(LList *llist, int data); /* function that finds the data whether it is in list */

int ListCount(LList *llist); /* function that returns the number of data in list */

void PrintList(LList *llist); /* function that prints the whole datas of the list */

#endif