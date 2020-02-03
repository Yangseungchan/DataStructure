#include <stdio.h>
#include <stdlib.h>
#include "CircularDoubleList.h"

void Initialize(CDList *cdlist) /* It is the function that initializes the CDList */
{
    Node *dummy = calloc(1, sizeof(Node));
    dummy->data = Null;
    dummy->next = dummy;
    dummy->prev = dummy;
    cdlist->head = cdlist->curt = dummy;
}

Node *SetNode(int data, Node *prev, Node *next) /* It is the function that allocates new node and sets the data, prev and next of the new node */
{
    Node *nde = calloc(1, sizeof(Node));
    nde->data = data;
    nde->prev = prev;
    nde->next = next;
    return nde;
}

void InsertAfter(CDList *cdlist, int data, Node *p) /* It is the function that inserts new node right after Node p */
{
    /* nde is the new node to be inserted into CDList */
    Node *nde = SetNode(data, p, p->next); /* nde's data, prev and data is set by function setnode */
    p->next = p->next->prev = nde;         /* p->next is nde's left node and p->next->prev is nde's right node */
    cdlist->curt = nde;                    /* curt node is renewed as newnode */
}

void InsertFront(CDList *cdlist, int data) /* It is the function that inserts new node at head node of the CDList */
{
    InsertAfter(cdlist, data, cdlist->head);
}

void InsertRear(CDList *cdlist, int data) /* It is the function that inserts new node at tail node of the CDList */
{
    InsertAfter(cdlist, data, cdlist->head->prev);
}

int Delete(CDList *cdlist, Node *target) /* It is the function that deletes the target node at the CDList */
{
    if (cdlist->head->next == cdlist->head) /* if there is only onde node in the CDList */
    {
        return FALSE;
    }
    target->prev->next = target->next;
    cdlist->curt = target->next->prev = target->prev;
    target->prev = target->next = NULL;
    free(target);
    return TRUE;
}

int DeleteFront(CDList *cdlist) /* It is the function that deletes the head node of the CDList */
{
    if (cdlist->head->next == cdlist->head) /* if there is only onde node in the CDList */
    {
        return FALSE;
    }
    else
    {
        return Delete(cdlist, cdlist->head->next);
    }
}

int DeleteRear(CDList *cdlist) /* It is the function that deletes the tail node of the CDList */
{
    if (cdlist->head->next == cdlist->head) /* if there is only onde node in the CDList */
    {
        return FALSE;
    }
    else
    {
        return Delete(cdlist, cdlist->head->prev);
    }
}

int DeleteCurt(CDList *cdlist) /* It is the function that deltes the curt node of the CDList */
{
    if (cdlist->head->next == cdlist->head) /* if there is only onde node in the CDList */
    {
        return FALSE;
    }
    else
    {
        return Delete(cdlist, cdlist->curt);
    }
}

int Search(CDList *cdlist, int data) /* It is the function that searches the node which is same as the input data */
{
    if (cdlist->head->next == cdlist->head) /* If cdlist is empty */
    {
        return FALSE;
    }
    Node *cmp = cdlist->head->next;
    do
    {
        if (cmp->data == data)
        {
            return TRUE;
        }
        cmp = cmp->next;
    } while (cmp != cdlist->head);
    return FALSE;
}

void PrintCurt(CDList *cdlist) /* It is the function that prints the curt node in the CDList */
{
    if (cdlist->head->next == cdlist->head)
    {
        printf("CDList is now empty\n\n");
        return;
    }
    else
    {
        printf("Data of Curt node of CDList : %d\n\n", cdlist->curt->data);
    }
}

void PrintList(CDList *cdlist) /* It is the function that prints the all nodes in the CDList */
{
    if (cdlist->head->next == cdlist->head)
    {
        printf("CDList is now empty\n\n");
        return;
    }
    Node *ptr = cdlist->head->next;
    printf("PRINT ALL NODE IN THE CDLIST FROM HEAD TO TAIL\n");
    do
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    } while (ptr != cdlist->head);
    putchar('\n');
    putchar('\n');
    return;
}

void Clear(CDList *cdlist) /* It is the function that clears the CDList by clearing all nodes */
{
    if (cdlist->head->next == cdlist->head)
    {
        return;
    }
    else
    {
        do
        {
            Delete(cdlist, cdlist->head->next);
        } while (cdlist->head->next != cdlist->head);
    }
}