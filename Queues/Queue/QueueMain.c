#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

typedef enum
{
    DEFAULT,
    ENQUEUE,
    DEQUEUE,
    SEARCH,
    ISEMPTY,
    ISFULL,
    CLEAR,
    PRINT_QUEUE,
    TERMINATE
} Menu;

Menu SelectMenu(void)
{
    int i, ch;
    char *mstring[] = {
        "ENQUEUE",
        "DEQUEUE",
        "SEARCH",
        "ISEMPTY",
        "ISFULL",
        "CLEAR",
        "PRINT QUEUE",
        "TERMINATE"
    };
    do
    {
        for (i = ENQUEUE; i < TERMINATE; i++)
        {
            printf("(%d) %-20.20s ", i, mstring[i - 1]);
            if (((i - 1) % 3) == 2)
                putchar('\n');
        }
        printf("(8) TERMINATE PROGRAM\n");
        printf("MENU : ");
        scanf("%d%*c", &ch);
    } while (ch > TERMINATE || ch < ENQUEUE);

    return (Menu)ch;
}

int main(void)
{
    Menu menu;
    Queue q;
    int num;
    int result;

    InitQueue(&q);
    do
    {
        switch (menu = SelectMenu())
        {
        case ENQUEUE:
            printf("Input number to enqueue : ");
            scanf("%d", &num);
            Enqueue(&q, num);
            putchar('\n');
            break;

        case DEQUEUE:
            Dequeue(&q);
            putchar('\n');
            break;

        case SEARCH:
            printf("Input number to search : ");
            scanf("%d", &num);
            result = Search(&q, num);
            if(result == FALSE){
                printf("It fails to find what you input.\n");
            }
            else{
                printf("It is found at #%d in Queue\n", result+1);
            }
            putchar('\n');
            break;

        case ISEMPTY:
            if(IsEmpty(&q) == FALSE){
                printf("It's not empty\n");
            }
            else{
                printf("It's empty\n");
            }
            putchar('\n');
            break;

        case ISFULL:
            if(IsFull(&q) == FALSE){
                printf("It's not full\n");
            }
            else{
                printf("It's full\n");
            }
            putchar('\n');
            break;

        case CLEAR:
            Clear(&q);
            putchar('\n');
            break;
        
        case PRINT_QUEUE:
            PrintQueue(&q);
            putchar('\n');
            break;

        case TERMINATE:
            Clear(&q);
            free(q.arr);
            putchar('\n');
            break;
        default:
            break;
        }

    } while (menu != TERMINATE);

    return 0;
}