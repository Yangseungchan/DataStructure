#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

Node *InitNode() /* function that initializes the Node*/
{
    Node *nde = (Node *)calloc(1, sizeof(Node));
    if (nde == NULL)
    {
        return NULL;
    }
    nde->data = -1;
    nde->next = NULL;
    return nde;
}

Node *AddNode(int data) /* function that initializes the Node that is goonna be inserted with data*/
{
    Node *nde = (Node *)calloc(1, sizeof(Node));
    if (nde == NULL)
    {
        return NULL;
    }
    nde->data = data;
    nde->next = NULL;
    return nde;
}

void InitList(LList *llist) /* function that initializes the List */
{
    llist->head = NULL;
    llist->tail = NULL;
    llist->count = 0;
    return;
}

int InsertData(LList *llist, int data) /* function that inserts a new data */
{
    Node *newNode = AddNode(data);
    if (newNode == NULL)
    { /* In case of failure to dynamic allocation */
        printf("# FAILURE TO ALLOCATION at newNode #\n");
        return FALSE;
    }
    else
    {
        if (llist->count == 0)
        { /* insertion at first */
            llist->head = newNode;
            llist->tail = newNode;
            llist->count++;
        }
        else
        { /* insertion after first node */
            llist->tail->next = newNode;
            llist->tail = newNode;
            llist->count++;
        }
        return TRUE;
    }
}

int DeleteData(LList *llist, int data) /* function that deletes the selected component in list */
{
    if (llist->count == 0)
    {
        return FALSE;
    }
    else if (SearchData(llist, data) == FALSE)
    {
        return FALSE;
    }
    else
    {
        Node *prev = NULL;
        Node *cur = llist->head;
        while (cur->data != data)
        {
            prev = cur;
            cur = cur->next;
        }
        if (prev != NULL)
        {
            prev->next = cur->next;
            llist->tail = prev;
        }
        else
        { /* cutting head but others exist */
            llist->head = cur->next;
            if (llist->count == 1)
            {
                llist->tail = NULL;
            }
        }
        free(cur);
        llist->count--;
        return TRUE;
    }
}

int SearchData(LList *llist, int data) /* function that finds the data whether it is in list */
{
    Node *nde = llist->head;
    while (nde != NULL)
    {
        if (nde->data == data)
        {
            return TRUE;
        }
        nde = nde->next;
    }
    return FALSE;
}

int ListCount(LList *llist) /* function that returns the number of data in list */
{
    return llist->count;
}

void PrintList(LList *llist) /* function that prints the whole datas of the list */
{
    Node *nde = llist->head;
    if (nde == NULL)
    {
        printf("No Data To Print\n");
        return;
    }
    else
    {
        while (nde != NULL)
        {
            printf("%d -> ", nde->data);
            nde = nde->next;
        }
        putchar('\n');
        return;
    }
}