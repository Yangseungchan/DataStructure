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

int LInsert(List *plist, int data) /* function that inserts the new data */
{
    if (plist->numofData >= LIST_LEN) /* In case that there is no space to insert a data in ArrayList */
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
    if (plist->numofData <= 0) /* In case there are no datas in ArrayList */
    {
        printf("There are no datas on ArrayList\n\n");
        return;
    }
    else
    {
        printf("ArrayList : ");
        for (size_t i = 0; i <= plist->curPosition; i++)
        {
            if (i == plist->curPosition)
            {
                printf("%d\n\n", plist->arr[i]);
            }
            else
            {
                printf("%d ->", plist->arr[i]);
            }
        }
        return;
    }
}

int LRemove(List *plist, int data) /* function that deletes input data in arraylist */
{
    int i, j;
    if (plist->numofData > 0) /* when arraylist has at least one data */
    {
        for (i = 0; i < plist->numofData; i++) /* repeat while it finds the data in arraylist */
        {
            if (plist->arr[i] == data) /* when it finds the data that you want to delete */
            {
                for (j = i; j < plist->curPosition; j++) /* 1. Delete the selected data */
                {
                    plist->arr[j] = plist->arr[j + 1]; /* 2. The datas that are behind the one to be deleted are moved to left by one index */
                }
                plist->curPosition--; /* subtract 1 from curPosition and numofData to indicate the removal of one data */
                plist->numofData--;
                return TRUE;
            }
        }
        printf("# FAILURE TO FIND THE DATA THAT YOU WANT TO DELETE#\n\n");
        return FALSE;
    }
    else
    {
        printf("# FAILURE TO DELETE DATA; NO MORE DATAS TO DELETE #\n\n");
        return FALSE;
    }
}

int LCount(List *plist) /* function that returns the number of the data in arraylist */
{
    return plist->numofData;
}

int LSearch(List *plist, int data) /* function that finds the given input data in arrayList. If it finds the data, then it returns TRUE and print index. Else it returns FALSE */
{
    int i;
    if (plist->curPosition == -1) /* In case that there isn't any data in ArrayList */
    {
        printf("# FAILURE TO FIND THE DATA#\n\n");
        return FALSE;
    }
    else
    {
        for (i = 0; i < plist->numofData; i++)
        {
            if (plist->arr[i] == data) /* In case that it finds the data in ArrayList */
            {
                printf("The given data is positioned at #%d in ArrayList\n\n", i + 1);
                return TRUE;
            }
        }
        printf("# FAILURE TO FIND THE DATA#\n\n"); /* In case that it fails to finds the data in ArrayList */
        return FALSE;
    }
}