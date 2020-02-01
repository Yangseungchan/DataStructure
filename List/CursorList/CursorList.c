#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CursorList.h"

void Initialize(CList *Clist) /* function that initializes the cursorlist */
{
    Clist->head = Clist->curt = Clist->max = END; /* initializes the head, curt and max as -1(END) */
    Clist->deleted = EMPTY;                       /* initializes the deleted index as -2(EMPTY) */
    Clist->nrr = calloc(MAX, sizeof(Node));       /* allocates Nodes */
    InitNodearr(Clist->nrr);                      /* initializes nodes in cursorlist */
}

void InitNodearr(Node *n) /* function that initializes Node type arr in cursorlist */
{
    for (size_t i = 0; i < MAX; i++)
    {
        n[i].next = n[i].Dnext = EMPTY; /* set next, Dnext indexes as -2(EMPTY) in cursorlist */
    }
}

void SetNode(Node *nde, const char *data, Index next)
{
    strcpy(nde->data, data); /* set the nde's data as input data */
    nde->next = next;        /* set the nde's next index as input next index */
    nde->Dnext = EMPTY;      /* set the nde's Dnext index as EMPTY(because setNode is one of the insert processes!) */
}

void InsertFront(CList *Clist, const char *data) /* function that inserts the input data into front node */
{
    int index = GetIndex(Clist);                      /* get appropriate index from function getindex */
    SetNode(&(Clist->nrr[index]), data, Clist->head); /* insert data, next index and Dnext index into Node type array */
    Clist->head = Clist->curt = index;                /* renew head, curt index as inserted index */
}

void InsertRear(CList *Clist, const char *data) /* function that inserts the input data into tail node */
{
    if (Clist->head == END) /* In case that head's value is -1(END) which means that CursorList is empty */
    {
        InsertFront(Clist, data);
    }
    else
    {
        int index = GetIndex(Clist); /* get appropriate index from function getindex */
        int tail = Clist->head;
        while (Clist->nrr[tail].next != END) /* finds the index of the tail node in the cursorlist */
        {
            tail = Clist->nrr[tail].next;
        }
        SetNode(&(Clist->nrr[index]), data, END); /* insert data, next index and Dnext index into Node type array */
        Clist->nrr[tail].next = Clist->curt = index;
        /* 1. connect tail node with new inserted node; 2. renew curt index as inserted index */
    }
}

void DeleteIndex(CList *Clist, Index target)
/* function that adjusts the 'deleted', clears node's data and next and adjusts the Dnext */
{
    strcpy(Clist->nrr[target].data, "\0");     /* clear node's data */
    Clist->nrr[target].next = EMPTY;           /* renew node's next index as -2(EMPTY) */
    Clist->nrr[target].Dnext = Clist->deleted; /* renew node's Dnext as deleted */
    Clist->deleted = target;                   /* renew deleted as index of node to be deleted */
}

int DeleteFront(CList *Clist) /* function that deletes the front node in the cursorlist */
{
    if (Clist->head == END) /* If there is no node in CursorList */
    {
        return -1;
    }
    else
    {
        int target = Clist->head;
        Clist->head = Clist->curt = Clist->nrr[target].next; /* renew head, curt index as head's next index */
        DeleteIndex(Clist, target);                          /* adjust deleted node's data, next, Dnext */
        return 0;
    }
}

int DeleteRear(CList *Clist) /* function that deletes the tail node in the cursorlist */
{
    if (Clist->head == END) /* In case that CursorList has no node */
    {
        return -1;
    }
    else
    {
        if (Clist->nrr[Clist->head].next == END) /* In case that CursorList has only one node */
        {
            DeleteFront(Clist); /* assign delete process to deletefront */
        }
        else
        {
            int target = Clist->head;
            while (Clist->nrr[Clist->nrr[target].next].next != END) /* finds the index which next's next node's index is END */
            {
                target = Clist->nrr[target].next; /* target is left node's index of the node to be deleted */
            }
            Clist->nrr[target].next = END; /* renew deleted node's next index as the -1(END) */
            Clist->curt = target;          /* renew curt index as target */
            DeleteIndex(Clist, Clist->nrr[target].next);
        }
        return 0;
    }
}

int DeleteCurt(CList *Clist) /* function that deletes the curt node in the cursorlist */
{
    if (Clist->head == END) /* when there is no node to delete */
    {
        return -1;
    }
    else if (Clist->curt == Clist->head) /* When curt index is same as head index */
    {
        DeleteFront(Clist);
    }
    else if (Clist->nrr[Clist->curt].next == END) /* When curt index is same as tail index */
    {
        DeleteRear(Clist);
    }
    else
    {
        int prev = Clist->head;
        while (Clist->nrr[prev].next != Clist->curt)
        {
            prev = Clist->nrr[prev].next; /* prev is index of node which is left to the curt node */
        }
        Clist->nrr[prev].next = Clist->nrr[Clist->curt].next; /* connecting curt's left node with curt's next node */
        DeleteIndex(Clist, Clist->curt);
        Clist->curt = prev; /* renew the curt index */
    }
    return 0;
}

int Search(CList *Clist, char *data) /* function which finds that input data exists in the cursorlist */
{
    if (Clist->head == END) /* In case that cursorlist is empty */
    {
        return -1;
    }
    else
    {
        int index = Clist->head;
        do
        {
            if (!strcmp(Clist->nrr[index].data, data)) /* finds the data by comparing string using strcpy */
            {
                return index; /* (when strcmp returns 0) = (both strings are same) */
            }
            index = Clist->nrr[index].next;
        } while (index != END); /* while index reaches the end of cursorlist */
    }
    return -1;
}

void PrintCurt(CList *Clist) /* function that prints the curt node in the cursorlist */
{
    if (Clist->head == END) /* In case that cursorlist is empty */
    {
        printf("As CursorList is empty, Curt node doesn't exist\n");
    }
    else
    {
        printf("Curt Node's data : %s\n", Clist->nrr[Clist->curt].data);
    }
}

void PrintList(CList *Clist) /* function that prints the whole nodes in the cursorlist */
{
    int index;
    if (Clist->head == END) /* In case that cursorlist is empty */
    {
        printf("List is empty\n");
        return;
    }
    else
    {
        index = Clist->head;
        do
        {
            printf("%s->", Clist->nrr[index].data);
            index = Clist->nrr[index].next;
        } while (index != END);
        putchar('\n');
        return;
    }
}

void Clear(CList *Clist) /* function that clears all nodes in the cursorlist */
{
    while (Clist->head != END) /* deleteing all nodes in cursorlist using function deletefront */
    {
        DeleteFront(Clist);
    }
}