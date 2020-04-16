#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BinaryTree.h"

BinNode *AllocNode() /* function that allocates new node */
{
    return calloc(1, sizeof(BinNode));
}

void SetBinNode(BinNode *nde, const char *data) /* function that sets the datas of BinNode */
{
    strcpy(nde->data, data);
    nde->left = nde->right = NULL;
}

void ConnectNode(BinNode *nde, BinNode *left, BinNode *right)
{
    nde->left = left;
    nde->right = right;
}

int RemoveTree(BinNode **root) /* function that removes the node which has input data */
{
    if ((*root)->left != NULL)
    {
        RemoveTree(&((*root)->left));
    }
    if ((*root)->right != NULL)
    {
        RemoveTree(&((*root)->right));
    }
    *root = NULL;
    free(*root);
    return 0;
}

void PrintBT(BinNode *p) /* function that prints the BST p */
{
    if (p != NULL)
    {
        PrintTree(p, 0, 0);
    }
}

void PrintTree(BinNode *nde, int level, int direction) /* function that prints the BST in 2 dimension */
/* direction : 0 = root; 1 = left; 2 = right */
{
    if (nde != NULL)
    {
        PrintTree(nde->right, level + 1, 2);
        for (int i = 0; i < level; i++)
        {
            if (i != level - 1)
            {
                printf("          ");
            }
            if (i == level - 1)
            {
                if (direction == 2)
                {
                    //printf("          ");
                    printf("┌─────────");
                }
                else if (direction == 1)
                {
                    //printf("          ");
                    printf("└─────────");
                }
            }
        }
        printf("%s", nde->data);
        putchar('\n');
        PrintTree(nde->left, level + 1, 1);
    }
}
