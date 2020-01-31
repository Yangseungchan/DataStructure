#ifndef __CURSOR_LIST_H__
#define __CURSOR_LIST_H__

#define MAX 500  /* maximum size of array(CursorList) */
#define EMPTY -2 /* indicating that it is empty */
#define END -1   /* indicating that it is end of the array */

typedef int Index;

typedef struct __node
{
    char data[20]; /* string data */
    Index next;    /* Index which points the next node in the cursorlist */
    Index Dnext;   /* Index that points the next node in the freelist */
} Node;

typedef struct __cursorlist
{
    Node *nrr;     /* Node type Array */
    Index head;    /* Index that points the head of the cursorlist */
    Index curt;    /* Index that points the current node's index of the cursorlist */
    Index max;     /* Index that indicates how many datas can be contained in the Cursorlist */
    Index deleted; /* Index that points the head of the freelist */
} CursorList;

typedef CursorList CList; /* rename CursorList as CList */

void Initialize(CList *Clist); /* function that initializes the cursorlist */

void InitNodearr(Node *n); /* function that initializes Node type arr in cursorlist */

int GetIndex(CList *Clist); /* function that finds the appropriate index to put data in array */

void SetNode(Node *nde, const char *data, Index next); /* function that sets the data, next, Dnext of the Node nde in Node type array when nde is inserted */

void InsertFront(CList *Clist, const char *data); /* function that inserts the input data into front node */

void InsertRear(CList *Clist, const char *data); /* function that inserts the input data into tail node */

void DeleteIndex(CList *Clist, Index target); /* function that adjusts the deleted when deleting has been executed */

int DeleteFront(CList *Clist); /* function that deletes the front node in the cursorlist */

int DeleteRear(CList *Clist); /* function that deletes the tail node in the cursorlist */

int DeleteCurt(CList *Clist); /* function that deletes the curt node in the cursorlist */

int Search(CList *Clist, char *data); /* function that finds that input data exists in the cursorlist */

void PrintCurt(CList *Clist); /* function that prints the curt node in the cursorlist */

void PrintList(CList *Clist); /* function that prints the whole nodes in the cursorlist */

void Clear(CList *Clist); /* function that clears all nodes in the cursorlist */

#endif