#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"

int main()
{
    int cmd;
    int num, result;
    List arrList;
    ListInit(&arrList);

    do
    {
        printf("Input the cmd that you want to execute (1 = INSERT, 2 = DELETE, 3 = PRINT, 4 = # of Data, 5 = EXIT) : ");
        scanf("%d", &cmd);
        switch (cmd)
        {
        case 1:
            printf("Input the data that you want to insert : ");
            scanf("%d", &num);
            result = LInsert(&arrList, num);
            if (result == FALSE)
            {
                printf("# FAILURE TO INSERT DATA; No More Space #\n");
            }
            break;
        case 2:
            result = LRemove(&arrList);
            if (result == FALSE)
            {
                printf("# FAILURE TO DELETE DATA; No Data to Delete #\n");
            }
            break;
        case 3:
            ListPrint(&arrList);
            break;
        case 4:
            printf("Num of Data : %d\n", LCount(&arrList));
        case 5:
            break;
        default:
            printf("Wrong cmd input; Try Again\n");
            break;
        }
    } while (cmd != 5);

    return 0;
}