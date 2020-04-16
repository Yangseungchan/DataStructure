#ifndef __EXPRESSION_TREE_H__
#define __EXPRESSION_TREE_H__

#include "BinaryTree.h"

int is_digit(char *token); /* function that indicates whether the token is digit or not */

BinNode *MakeExpTree(char *expression); /* function that makes expression tree based on given postfix expression */

int EvaluateExpTree(BinNode *nde);

char *showInfixExp(BinNode *nde);

char *showPostfixExp(BinNode *nde);

char *showPrefixExp(BinNode *nde);

#endif