#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

#define MAXLEN 100

typedef struct __binnode
{
    char data[MAXLEN];
    struct __binnode *left;
    struct __binnode *right;
} BinNode;

BinNode *AllocNode(); /* function that allocates new node */

void SetBinNode(BinNode *nde, const char *data); /* function that sets the datas of BinNode */

void ConnectNode(BinNode *nde, BinNode *left, BinNode *right);

int RemoveTree(BinNode **root); /* function that removes the node which has input data */

void PrintBT(BinNode *p); /* function that prints the BST p*/

void PrintTree(BinNode *nde, int level, int direction); /* function that prints the BST in 2 dimension */

#endif