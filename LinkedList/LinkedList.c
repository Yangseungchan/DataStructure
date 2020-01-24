#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void InitList(Llist *list) /* function that initializes the linkedlist */
{
    list->head = NULL;
    list->curt = NULL;
}

Node *SetNode(const int data, Node *next) /* function that allocates and makes new node and points to next node */
{
    Node *nde = calloc(1, sizeof(Node));
    nde->data = data;
    nde->next = next;
    return nde;
}

void InsertFront(Llist *list, const int data) /* function that insert the new node at head of linkedlist */
{
    Node *ptr = SetNode(data, list->head);
    list->head = ptr;
    list->curt = list->head;
    return;
}

void InsertRear(Llist *list, const int data) /* function that inserts the new node at tail of linkedlist */
{
    if (list->head == NULL) /* case that there is no node in linkedlist */
    {
        InsertFront(list, data);
        return;
    }
    else
    {
        Node *ptr = SetNode(data, NULL); /* new node is allocated */
        Node *prev = list->head;
        while (prev->next != NULL) /* while it reaches tail node, prev is moved */
        {
            prev = prev->next;
        }
        prev->next = ptr;
        list->curt = ptr;
        return;
    }
}

int RemoveFront(Llist *list) /* function that removes a node at head of linkedlist */
{
    if (list->head == NULL) /* in case of there is no node in linkedlist */
    {
        return FALSE;
    }
    else
    {
        Node *ptr = list->head;
        list->head = list->head->next;
        ptr->next = NULL; /* to disconnect with next node */
        free(ptr);
        return TRUE;
    }
}

int RemoveRear(Llist *list) /* function that removes a node at tail of linkedlist */
{
    if (list->head == NULL) /* in case that there is no node in linkedlist */
    {
        return FALSE;
    }
    else
    {
        if (list->head->next == NULL) /* in case that there is only one node in linkedlist */
        {
            return RemoveFront(list);
        }
        else /* in case that there are at least 2 nodes in linkedlist */
        {
            Node *del = list->head->next; /* the node to be deleted */
            Node *before = list->head;    /* the node before del node */
            while (del->next != NULL)
            {
                before = del;
                del = del->next;
            }
            before->next = NULL;
            free(del);
            list->curt = before;
            return TRUE;
        }
    }
}

int RemoveCur(Llist *list) /* function that removes a node that Node curt points */
{
    if (list->head == NULL)
    {
        return FALSE;
    }
    else
    {
        if (list->head->next == NULL)
        {
            return RemoveFront(list);
        }
        else
        {
            Node *before = list->head;
            while (before->next != list->curt)
            {
                before = before->next;
            }
            before->next = list->curt->next;
            list->curt->next = NULL;
            free(list->curt);
            list->curt = before;
            return TRUE;
        }
    }
}

int Search(Llist *list, const int data)
/* function that finds a node which data is same as the input data by using function compare*/
{
    Node *ptr = list->head;
    while (ptr != NULL)
    {
        if (ptr->data == data)
        {
            return TRUE;
        }
        ptr = ptr->next;
    }
    return FALSE;
}

void Clear(Llist *list) /* function that deletes all nodes */
{
    Node *ptr = list->head;
    while (ptr != NULL)
    {
        RemoveFront(list);
        ptr = list->head; /* After removal is done, renew the ptr as head node of linkedlist */
    }
    return;
}

void PrintList(const Llist *list) /* function that prints the whole datas of the linkedlist */
{
    Node *nde = list->head;
    if(nde == NULL){
        printf("Empty List\n");
        return;
    }
    while (nde != NULL)
    {
        printf("%d ->", nde->data);
        nde = nde->next;
    }
    putchar('\n');
    putchar('\n');
    return;
}
