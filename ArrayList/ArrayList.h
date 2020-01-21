#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#define TRUE 1
#define FALSE 0

#define LIST_LEN 100

typedef struct __ArrayList
{
    int arr[LIST_LEN];
    int numofData; /* the number of the datas in arraylist */
} ArrayList;

typedef ArrayList List;

void ListInit(List *plist); /* function that initializes the ArrayList */

int LInsert(List *plist, int data); /* function that inserts a new data */

void ListPrint(List *plist); /* function that prints the whole datas of the list */

int LRemove(List *plist, int data); /* function that deletes input data in arraylist */

int LCount(List *plist); /* function that returns the number of the data in arraylist */

int LSearch(List *plist, int data); /* function that finds the given input data in arrayList. When it finds the data, then it returns its TRUE and print index. Else it returns FALSE */

#endif