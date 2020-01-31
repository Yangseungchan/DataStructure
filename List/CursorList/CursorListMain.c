#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CursorList.h"

typedef enum
{
    DEFAULT,
    INS_FRONT,
    INS_REAR,
    RMV_FRONT,
    RMV_REAR,
    RMV_CRNT,
    SRCH_NODE,
    PRINT_CURT,
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
        "PRINT CURT NODE IN LIST",
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
        printf("(10) TERMINATE PROGRAM\n");
        printf("MENU : ");
        scanf("%d%*c", &ch);
    } while (ch > TERMINATE || ch < INS_FRONT);

    return (Menu)ch;
}

int main(void)
{
    Menu menu;
    CList list;
    char data[20];
    int result;

    Initialize(&list);
    do
    {
        switch (menu = SelectMenu())
        {
        case INS_FRONT:
            printf("Input string to insert(< 20) : ");
            scanf("%s", data);
            InsertFront(&list, data);
            putchar('\n');
            break;

        case INS_REAR:
            printf("Input string to insert(< 20) : ");
            scanf("%s", data);
            InsertRear(&list, data);
            putchar('\n');
            break;

        case RMV_FRONT:
            if (DeleteFront(&list) == -1)
            {
                printf("Fail to delete data(It doesn't exist in CursorList)\n");
            }
            putchar('\n');
            break;

        case RMV_REAR:
            if (DeleteRear(&list) == -1)
            {
                printf("Fail to delete data(It doesn't exist in CursorList)\n");
            }
            putchar('\n');
            break;

        case RMV_CRNT:
            if (DeleteCurt(&list) == -1)
            {
                printf("Fail to delete data(It doesn't exist in CursorList)\n");
            }
            putchar('\n');
            break;

        case SRCH_NODE:
            printf("Input string to search : ");
            scanf("%s", data);
            result = Search(&list, data);
            if (result == -1)
            {
                printf("It fails to find what you want\n");
            }
            else
            {
                printf("# [WARNING] : There can be empty nodes in each index #\n");
                printf("Data : [%s] exists in #%d node in CursorList\n", list.nrr[result].data, result + 1);
            }
            putchar('\n');
            break;

        case PRINT_CURT:
            PrintCurt(&list);
            putchar('\n');
            break;

        case PRINT_ALL:
            PrintList(&list);
            putchar('\n');
            break;

        case CLEAR:
            Clear(&list);
            putchar('\n');
            break;

        case TERMINATE:
            Clear(&list);
            free(list.nrr);
            putchar('\n');
            break;
        default:
            break;
        }

    } while (menu != TERMINATE);

    return 0;
}
