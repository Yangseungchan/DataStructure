#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"

BinNode *AllocNode() /* function that allocates new node */
{
    return calloc(1, sizeof(BinNode));
}

void SetBinNode(BinNode *nde, const int data, BinNode *left, BinNode *right) /* function that sets the datas of BinNode */
{
    nde->data = data;
    nde->left = left;
    nde->right = right;
}

BinNode *Search(BinNode *p, const int data) /* function that searches the input data in BST */
{
    while (p != NULL)
    {
        if (p->data == data)
        {
            return p;
        }
        else if (p->data < data)
        {
            p = p->right;
        }
        else
        {
            p = p->left;
        }
    }
    return NULL;
}

BinNode *Add(BinNode *p, int data) /* function that adds the new data to BST */
{
    BinNode *nde, *parent, *temp;
    nde = AllocNode();
    SetBinNode(nde, data, NULL, NULL);
    temp = p;

    if (temp == NULL)
    {
        p = nde;
    }
    else
    {
        while (temp != NULL)
        {
            if (temp->data == data)
            {
                return p;
            }
            else if (temp->data < data)
            {
                parent = temp;
                temp = temp->right;
            }
            else
            {
                parent = temp;
                temp = temp->left;
            }
        }
        if (data < parent->data)
        {
            parent->left = nde;
        }
        else if (data > parent->data)
        {
            parent->right = nde;
        }
    }
    return p;
}

int Remove(BinNode **root, int data) /* function that removes the node which has input data */
{
    BinNode **target;
    BinNode *parent, *child, *child_parent;
    int tmp_data, flag; /* flag is indicator which indicates the target is left or right child of the parent */
    target = root;
    parent = NULL;
    flag = 0;                                          /* target is root */
    while (*target != NULL && (*target)->data != data) /* searching target node to be removed */
    {
        if ((*target)->data < data)
        {
            flag = 2; /* target is right child of the parent */
            parent = *target;
            *target = (*target)->right;
        }
        else
        {
            flag = 1; /* target is left child of the parent */
            parent = *target;
            *target = (*target)->left;
        }
    }
    /* process of searching target is ended */
    //printf("target : %d\n", target->data);

    if (*target == NULL) /* if target is not found */
    {
        return -1;
    }
    else /* if the target is found */
    {
        if ((*target)->left == NULL && (*target)->right == NULL) /* if target node has no child */
        {
            //printf("target has no child\n");
            if (flag == 0) /* target is root without any child */
            {
                (*root) = NULL;
            }
            else if (flag == 1) /* target is left child */
            {
                parent->left = NULL;
            }
            else /* target is right child */
            {
                parent->right = NULL;
            }
        }
        else if ((*target)->left == NULL || (*target)->right == NULL) /* if target node has one childs */ /* How can I do if target is root? */
        {
            //printf("target has one child\n");
            if ((*target)->left != NULL) /* target node has only left child */
            {
                child = (*target)->left;
                (*target)->left = NULL;
            }
            else /* target node has only right child */
            {
                child = (*target)->right;
                (*target)->right = NULL;
            }
            if (flag == 0)
            {
                *root = child;
            }
            else if (flag == 1)
            {
                parent->left = child;
            }
            else if (flag == 2)
            {
                parent->right = child;
            }
        }
        else /* if target node has two child */
        {
            //printf("two child\n");
            child = (*target)->left;
            child_parent = *target;
            while (child->right != NULL) /* searching the biggest child of the target */
            {
                child_parent = child;
                child = child->right;
            }
            /* searching biggest child of the target is ended */

            (*target)->data = child->data; /* changing target's data with child's data */

            if (child->left == NULL) /*child has no its child */
            {
                //printf("child has no child\n");
                if (child == (*target)->left)
                {
                    child_parent->left = NULL;
                }
                else
                {
                    child_parent->right = NULL;
                }
            }
            else /* child has one child (in this case left child is only possible) */
            {
                if (child == (*target)->left)
                {
                    child_parent->left = child->left;
                }
                else
                {
                    child_parent->right = child->left;
                }
            }
        }
        free(*target);
        return 0;
    }
    return -1;
}

void PrintBST(BinNode *p) /* function that prints the BST p */
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
        printf("%d", nde->data);
        putchar('\n');
        PrintTree(nde->left, level + 1, 1);
    }
}

void FreeTree(BinNode **p) /* function that frees the all nodes in BST p */
{
    while (*p != NULL)
    {
        Remove(p, (*p)->data);
    }
}