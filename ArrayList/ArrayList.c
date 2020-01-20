#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"

void ListInit(List *plist) /* function that initializes the ArrayList */
{
    for (size_t i = 0; i < LIST_LEN; i++)
    {
        plist->arr[i] = -1;
    }
    plist->numofData = 0;
    plist->curPosition = -1; /* it means that there isn't any data in list */
}

int LInsert(List *plist, int data) /* function that insert the new data */
{
    if (plist->numofData >= LIST_LEN)
    {
        return FALSE;
    }
    else
    {
        plist->arr[++plist->curPosition] = data;
        plist->numofData++;
        return TRUE;
    }
}

void ListPrint(List *plist) /* function that prints the whole datas of the list */
{
    printf("ArrayList : ");
    for (size_t i = 0; i <= plist->curPosition; i++)
    {
        if (i == plist->curPosition)
        {
            printf("%d\n", plist->arr[i]);
        }
        else
        {
            printf("%d ->", plist->arr[i]);
        }
    }
}

int LRemove(List *plist) /* function that deletes the last component in arraylist */
{
    if (plist->numofData > 0)
    {
        plist->arr[plist->curPosition--] = -1;
        plist->numofData--;
        return TRUE;
    }
    else
    {
        printf("# FAILURE TO DELETE DATA; NO MORE DATAS TO DELETE #\n");
        return FALSE;
    }
}

int LCount(List *plist) /* function that returns the number of the data in arraylist */
{
    return plist->numofData;
}