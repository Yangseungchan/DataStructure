#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BinaryTree.h"
#include "ExpressionConvertor.h"
#include "NodeStack.h"

#define MAXOP 10
#define MAXEXP 1000

int length = 0;

int is_digit(char *token)
{
    if (atoi(token) == 0 && strcmp(token, "0")) /* atoi value is 0 but token is not same as string "0" */
    {
        return FALSE;
    }
    return TRUE;
}

BinNode *MakeExpTree(char expression[MAXEXP])
{
    BNStack bnstk;
    BinNode *root, *bnde, *nde1, *nde2;
    char *token;

    token = strtok(expression, " ");

    _InitStack(&bnstk);
    while (token != NULL)
    {
        bnde = AllocNode();
        if (is_digit(token) == TRUE) /* In case that token is digit */
        {
            SetBinNode(bnde, token);
            _Push(&bnstk, bnde);
            bnde = NULL;
        }
        else /* In case that token is not digit(= is operator) */
        {
            SetBinNode(bnde, token);
            nde1 = _Pop(&bnstk);
            nde2 = _Pop(&bnstk);

            bnde->right = nde1; /* the first popped node should be at right of the root node */
            bnde->left = nde2;  /* the second popped node should be at left of the root node */
                                /* for making them in order of tree */

            _Push(&bnstk, bnde);

            bnde = nde1 = nde2 = NULL;
            free(nde1);
            free(nde2);
        }
        free(bnde);
        token = strtok(NULL, " ");
    }
    root = _Pop(&bnstk);
    _Clear(&bnstk);
    return root;
}

int EvaluateExpTree(BinNode *nde)
{
    int operand1, operand2;
    char operator[MAXOP];
    if (is_digit(nde->data) == TRUE) /* if node's data is digit, then it returns its value */
    {
        return atoi(nde->data);
    }

    /* If the data is an operator, then it performs calculation between its left child and right child */

    operand1 = EvaluateExpTree(nde->left);
    strcpy(operator, nde->data);
    operand2 = EvaluateExpTree(nde->right);

    if (!strcmp(operator, "+")) /* if operator is '+', then it performs the addition of two operands */
    {
        return operand1 + operand2;
    }
    else if (!strcmp(operator, "-")) /* if operator is '-', then it performs the substraction of two operands */
    {
        return operand1 - operand2;
    }
    else if (!strcmp(operator, "*")) /* if operator is '*', then it performs the multiplicaion of two operands */
    {
        return operand1 * operand2;
    }
    else if (!strcmp(operator, "/")) /* if operator is '/', then it performs the division of two operands */
    {
        return operand1 / operand2;
    }
    /* when it reads other operator, it becomes error */
}

char *showInfixExp(BinNode *nde)
{
    static char expression[MAXEXP];

    if (nde != NULL)
    {
        if (nde->left != NULL)
        {
            showInfixExp(nde->left);
        }
        strcat(expression, nde->data);
        strcat(expression, " ");
        if (nde->right != NULL)
        {
            showInfixExp(nde->right);
        }
    }

    return expression;
}

char *showPostfixExp(BinNode *nde)
{
    static char expression[MAXEXP];

    if (nde != NULL)
    {
        if (nde->left != NULL)
        {
            showPostfixExp(nde->left);
        }
        if (nde->right != NULL)
        {
            showPostfixExp(nde->right);
        }
        strcat(expression, nde->data);
        strcat(expression, " ");
    }

    return expression;
}

char *showPrefixExp(BinNode *nde)
{
    static char expression[MAXEXP];

    if (nde == NULL)
    {
        return expression;
    }
    strcat(expression, nde->data);
    strcat(expression, " ");
    showPrefixExp(nde->left);
    showPrefixExp(nde->right);
}