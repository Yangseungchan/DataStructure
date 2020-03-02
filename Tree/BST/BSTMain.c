#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BinarySearchTree.h"

int main(void)
{
    BinNode *root = NULL;
    srand(time(NULL));

    int random, i, test_case;
    printf("input the # of test case : ");
    scanf("%d", &test_case);

    printf("random : ");
    for (i = 0; i < test_case; i++)
    {
        //random = rand() % 100;
        scanf("%d", &random);
        //printf("%d ", random);
        root = Add(root, random);
    }
    putchar('\n');

    PrintBST(root);

    printf("input the number to remove : ");
    scanf("%d", &random);

    Remove(&root, random);

    printf("\n\n");

    PrintBST(root);

    return 0;
}