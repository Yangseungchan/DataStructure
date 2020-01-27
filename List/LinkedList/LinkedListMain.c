#include <stdio.h>
#include "LinkedList.h"

typedef enum
{
    DEFAULT,
    INS_FRONT,
    INS_REAR,
    RMV_FRONT,
    RMV_REAR,
    RMV_CRNT,
    SRCH_NODE,
    PRINT_ALL,
    CLEAR,
    TERMINATE
} Menu;

Menu SelectMenu(void)
{
    int i, ch;
    char *mstring[] = {
        "INSERT NODE AT FRONT",
        "INSERT NODE AT REAR",
        "REMOVE NODE AT FRONT",
        "REMOVE NODE AT REAR",
        "REMOVE NODE AT CURT",
        "SEARCH NODE IN LIST",
        "PRINT ALL NODES IN LIST",
        "CLEAR ALL NODES IN LIST",
        "TERMINATE PROGRAM"};

    do
    {
        for (i = INS_FRONT; i < TERMINATE; i++)
        {
            printf("(%d) %-24.24s ", i, mstring[i - 1]);
            if (((i - 1) % 3) == 2)
                putchar('\n');
        }
        printf("(9) TERMINATE\n");
        printf("MENU : ");
        scanf("%d", &ch);
    } while (ch > TERMINATE || ch < INS_FRONT);

    return (Menu)ch;
}

int main(void)
{
    Menu menu;
    Llist list;
    int num;

    InitList(&list);
    do
    {
        switch (menu = SelectMenu())
        {
        case INS_FRONT:
            printf("Input number to insert : ");
            scanf("%d", &num);
            InsertFront(&list, num);
            putchar('\n');
            break;

        case INS_REAR:
            printf("Input number to insert : ");
            scanf("%d", &num);
            InsertRear(&list, num);
            putchar('\n');
            break;

        case RMV_FRONT:
            RemoveFront(&list);
            putchar('\n');
            break;

        case RMV_REAR:
            RemoveRear(&list);
            putchar('\n');
            break;

        case RMV_CRNT:
            RemoveCur(&list);
            putchar('\n');
            break;

        case SRCH_NODE:
            printf("Input number to search : ");
            scanf("%d", &num);
            if (Search(&list, num) == TRUE)
            {
                puts("It exists in LinkedList\n\n");
            }
            else
            {
                puts("It doesn't exist in LinkedList\n\n");
            }
            break;

        case PRINT_ALL:
            PrintList(&list);
            break;

        case CLEAR:
            Clear(&list);
            putchar('\n');
            break;

        case TERMINATE:
            Clear(&list);
            putchar('\n');
            break;
        }

    } while (menu != TERMINATE);

    return 0;
}
