#include <stdio.h>
#include "BinarySearchTree.h"

typedef enum
{
    TERMINATE,
    ADD,
    REMOVE,
    SEARCH,
    PRINT,
    CLEAR
} Menu;

Menu SelectMenu(void)
{
    int ch;
    do
    {
        printf("(1) ADD (2) REMOVE (3) SEARCH (4) PRINT (5) CLEAR (0) TERMINATE: ");
        scanf("%d", &ch);
    } while (ch < TERMINATE || ch > CLEAR);
    return (Menu)ch;
}

int main(void)
{
    int num;
    Menu menu;
    BinNode *root = NULL;
    do
    {
        BinNode *temp;
        switch (menu = SelectMenu())
        {
        case ADD:
            printf("input number to add : ");
            scanf("%d", &num);
            root = Add(root, num);
            printf("\n\n");
            break;

        case REMOVE:
            printf("input number to remove : ");
            scanf("%d", &num);
            Remove(&root, num);
            printf("\n\n");
            break;

        case SEARCH:
            printf("input number to search : ");
            scanf("%d", &num);
            if ((temp = Search(root, num)) != NULL)
                printf("%d is found in Tree\n", temp->data);
            printf("\n\n");
            break;

        case PRINT:
            PrintBST(root);
            printf("\n\n");
            break;

        case CLEAR:
            FreeTree(&root);
            printf("\n\n");
            break;

        default:
            break;
        }
    } while (menu != TERMINATE);

    FreeTree(&root);

    return 0;
}
