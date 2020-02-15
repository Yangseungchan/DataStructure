#include <stdio.h>
#include "Stack.h"


typedef enum
{
    DEFAULT,
    PUSH,
    POP,
    PEEK,
    PRINT_STACK,
    ISEMPTY,
    ISFULL,
    SEARCH,
    TERMINATE
} Menu;

Menu SelectMenu(void)
{
    int i, ch;
    char *mstring[] = {
        "PUSH",
        "POP",
        "PEEK",
        "PRINT STACK",
        "CHECK EMPTINESS",
        "CHECK FULLNESS",
        "SEARCH",
        "TERMINATE PROGRAM"
    };
    do
    {
        for (i = PUSH; i < TERMINATE; i++)
        {
            printf("(%d) %-18.18s ", i, mstring[i - 1]);
            if (((i - 1) % 3) == 2)
                putchar('\n');
        }
        printf("(8) TERMINATE PROGRAM\n");
        printf("MENU : ");
        scanf("%d%*c", &ch);
    } while (ch > TERMINATE || ch < PUSH);

    return (Menu)ch;
}

int main(void)
{
    Menu menu;
    Stack stk;
    int num;
    int result;

    InitStack(&stk);
    do
    {
        switch (menu = SelectMenu())
        {
        case PUSH:
            printf("Input number to push : ");
            scanf("%d", &num);
            Push(&stk, num);
            putchar('\n');
            break;

        case POP:
            Pop(&stk);
            putchar('\n');
            break;

        case PEEK:
            Peek(&stk);
            putchar('\n');
            break;

        case PRINT_STACK:
            PrintStack(&stk);
            putchar('\n');
            break;

        case ISEMPTY:
            if(IsEmpty(&stk) == FALSE){
                printf("It's not empty\n");
            }
            else{
                printf("It's empty\n");
            }
            putchar('\n');
            break;

        case ISFULL:
            if(IsFull(&stk) == FALSE){
                printf("It's not full\n");
            }
            else{
                printf("It's full\n");
            }
            putchar('\n');
            break;

        case SEARCH:
            printf("input the number to search : ");
            scanf("%d", &num);
            result = Search(&stk, num);
            if(result == FALSE){
                printf("FAILURE TO SEARCH\n");
            }
            else{
                printf("It is positioned at #%d\n", result+1);
            }
            putchar('\n');
            break;

        case TERMINATE:
            Clear(&stk);
            putchar('\n');
            break;
        default:
            break;
        }

    } while (menu != TERMINATE);

    return 0;
}