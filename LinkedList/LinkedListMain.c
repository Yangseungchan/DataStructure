#include <stdio.h>
#include "LinkedList.h"

typedef enum
{
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

/*--- ∏ﬁ¥∫ º±≈√ ---*/
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
            printf("(%d) %-24.24s ", i + 1, mstring[i]);
            if ((i % 3) == 2)
                putchar('\n');
        }
        printf("(9) TERMINATE\n");
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
    menu = SelectMenu();
    do
    {
        switch (menu = SelectMenu())
        {
        case INS_FRONT:
            printf("Input number to insert : ");
            num = scanf("%d", &num);
            InsertFront(&list, num);
            break;

        case INS_REAR:
            printf("Input number to insert : ");
            num = scanf("%d", &num);
            InsertRear(&list, num);
            break;

        case RMV_FRONT:
            RemoveFront(&list);
            break;

        case RMV_REAR:
            RemoveRear(&list);
            break;

        case RMV_CRNT:
            RemoveCur(&list);
            break;

        case SRCH_NODE:
            printf("Input number to search : ");
            num = scanf("%d", &num);
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
            break;

        default:
            break;
        }

    } while (menu != TERMINATE);

    return 0;
}