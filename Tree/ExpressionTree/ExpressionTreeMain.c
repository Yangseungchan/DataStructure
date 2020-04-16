#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BinaryTree.h"
#include "ExpressionConvertor.h"
#include "ExpressionTree.h"

#define MAXEXP 1000

int main(void)
{
    int result;
    BinNode *root;
    char expression[MAXEXP];

    printf("========================= Expression Tree Convertor ======================\n\n\n");
    printf("∆ Input an expression without space(number should be only positive) : ");
    scanf("%s", expression);
    convertExpression(expression, strlen(expression));
    putchar('\n');

    printf("∆ Converted postfix expression : %s\n\n", expression);
    printf("∆ The Postfix expression is converted into following ExpressionTree :  \n\n");
    root = MakeExpTree(expression);

    printf("===========================================================================\n\n");
    PrintBT(root);
    putchar('\n');
    printf("===========================================================================\n\n");
    result = EvaluateExpTree(root);
    printf("∆ Calculated result value from Expression Tree : %d\n\n", result);

    strcpy(expression, showInfixExp(root));
    printf("∆ Infix expression from ExpTree : %s\n\n", expression);

    strcpy(expression, showPostfixExp(root));
    printf("∆ Postfix expression from ExpTree : %s\n\n", expression);

    strcpy(expression, showPrefixExp(root));
    printf("∆ Prefix expression from ExpTree : %s\n\n", expression);
    RemoveTree(&root);

    printf("===========================================================================\n\n");
    return 0;
}
