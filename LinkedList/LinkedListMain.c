#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main(void){

    int cmd;
    int num, result;
    LList list;
    InitList(&list);


    do
    {
        printf("Input the cmd that you want to execute (1 = INSERT, 2 = DELETE, 3 = PRINT, 4 = # of Data, 5 = SEARCH, 6 = EXIT) : ");
        scanf("%d", &cmd);
        switch(cmd){
            case 1 :
                printf("Input the data that you want to insert : ");
                scanf("%d", &num);
                result = InsertData(&list, num);
                break;
            case 2 :
                printf("Input the data that you want to delete : ");
                scanf("%d", &num);
                result = DeleteData(&list, num);
                if(result == FALSE){
                    printf("# FAILURE TO DELETE DATA; No Data to Delete #\n");
                }
                break;
            case 3 :
                PrintList(&list);
                break;
            case 4 :
                printf("Num of Data : %d\n", ListCount(&list));
            case 5 :
                printf("Input the data that you want to search : ");
                scanf("%d", &num);
                result = SearchData(&list, num);
                if(result == TRUE){
                    printf("The data that you input exists at this LinkedList\n");
                }
                else{
                    printf("FAILURE TO FIND IT.\n");
                }
            case 6 :
                break;
            default:
                printf("Wrong cmd input; Try Again\n");
                break;
        }
    }while(cmd != 6);
    
    return 0;
}