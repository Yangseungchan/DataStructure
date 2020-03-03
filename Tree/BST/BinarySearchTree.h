#ifndef __BINARYSEARCHTREE_H__
#define __BINARYSEARCHTREE_H__

typedef struct __binnode
{
    int data;
    struct __binnode *left;
    struct __binnode *right;
} BinNode;

BinNode *AllocNode(); /* function that allocates new node */

void SetBinNode(BinNode *nde, const int data, BinNode *left, BinNode *right); /* function that sets the datas of BinNode */

BinNode *Search(BinNode *p, const int data); /* function that searches the input data in BST */

BinNode *Add(BinNode *p, int data); /* function that adds the new data to BST */

int Remove(BinNode **root, int data); /* function that removes the node which has input data */

void PrintBST(BinNode *p); /* function that prints the BST p*/

void PrintTree(BinNode *nde, int level, int direction); /* function that prints the BST in 2 dimension */

void FreeTree(BinNode **p); /* function that frees the all nodes in BST p */

#endif