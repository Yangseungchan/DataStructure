#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CursorList.h"

void Initialize(CList *Clist) /* function that initializes the cursorlist */
{
    Clist->head = Clist->curt = Clist->max = END;
    Clist->deleted = EMPTY;
    Clist->nrr = calloc(MAX, sizeof(Node));
    InitNodearr(Clist->nrr);
}

void InitNodearr(Node *n) /* function that initializes Node type arr in cursorlist */
{
    for (size_t i = 0; i < MAX; i++)
    {
        n[i].next = n[i].Dnext = EMPTY;
    }
}

void SetNode(Node *nde, const char *data, Index next)
{
    strcpy(nde->data, data); /* set the nde's data as input data */
    nde->next = next;        /* set the nde's next index as input next index */
    nde->Dnext = EMPTY;      /* set the nde's Dnext index as EMPTY(because setNode is one of the insert processes!) */
}

int GetIndex(CList *Clist) /* function that finds the appropriate index to put data in array */
{
    if (Clist->deleted != EMPTY) /* if deleted has any value */
    {
        int temp = Clist->deleted;
        Clist->deleted = Clist->nrr[temp].Dnext;
        return temp;
    }
    else /* if deleted has no value */
    {
        return (++Clist->max);
    }
}

void InsertFront(CList *Clist, const char *data) /* function that inserts the input data into front node */
{
    int index = GetIndex(Clist);
    SetNode(&(Clist->nrr[index]), data, Clist->head);
    Clist->head = Clist->curt = index;
}

void InsertRear(CList *Clist, const char *data) /* function that inserts the input data into tail node */
{
    if (Clist->head == END) /* In case that head's value is -1 = CursorList is empty */
    {
        InsertFront(Clist, data);
    }
    else
    {
        int index = GetIndex(Clist);
        int tail = Clist->head;
        while (Clist->nrr[tail].next != END) /* finds the index of the tail node in the cursorlist */
        {
            tail = Clist->nrr[tail].next;
        }
        SetNode(&(Clist->nrr[index]), data, END);
        Clist->nrr[tail].next = Clist->curt = index;
    }
}

void DeleteIndex(CList *Clist, Index target)
/* function that adjusts the 'deleted', clears node's data and next and adjusts the Dnext */
{
    strcpy(Clist->nrr[target].data, "\0");
    Clist->nrr[target].next = EMPTY;
    Clist->nrr[target].Dnext = Clist->deleted;
    Clist->deleted = target;
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
        Clist->head = Clist->curt = Clist->nrr[target].next;
        DeleteIndex(Clist, target);
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
            DeleteFront(Clist);
        }
        else
        {
            int target = Clist->head;
            while (Clist->nrr[Clist->nrr[target].next].next != END) /* finds the index which next next node's index is END */
            {
                target = Clist->nrr[target].next;
            }
            Clist->nrr[target].next = END;
            Clist->curt = target;
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
            prev = Clist->nrr[prev].next;
        }
        Clist->nrr[prev].next = Clist->nrr[Clist->curt].next; /* connecting curt's left node with curt's next node */
        DeleteIndex(Clist, Clist->curt);
        Clist->curt = prev; /* renew the curt index */
    }
    return 0;
}

int Search(CList *Clist, char *data) /* function which finds that input data exists in the cursorlist */
{
    if (Clist->head == END)
    {
        return -1;
    }
    else
    {
        int index = Clist->head;
        do
        {
            if (!strcmp(Clist->nrr[index].data, data))
            {
                return index;
            }
            index = Clist->nrr[index].next;
        } while (index != END); /* (when strcmp returns 1) = (both strings are different) */
    }
    return -1;
}

void PrintCurt(CList *Clist) /* function that prints the curt node in the cursorlist */
{
    if (Clist->head == END)
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
    if (Clist->head == END)
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
    while(Clist->head != END){
        DeleteFront(Clist);
    }
}