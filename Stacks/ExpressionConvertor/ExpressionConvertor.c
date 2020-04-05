#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "CharStack.h"
#include "ExpressionConvertor.h"

int opPriority(char op)
{
    switch (op)
    {
    case '/':
    case '*':
        return 5;
    case '+':
    case '-':
        return 3;
    case '(':
        return 1;
    }
    return 0;
}

int compPriority(char op1, char op2)
{
    if (opPriority(op1) > opPriority(op2))
    {
        return 1;
    }
    else if (opPriority(op1) == opPriority(op2))
    {
        return 0;
    }
    else /* op1 has smaller priority than op2 */
    {
        return -1;
    }
}

void convertExpression(char expression[], int length)
{
    int i, idx, value;
    Stack stk;
    char op;
    char *result = calloc(sizeof(char), length * 3);

    idx = 0;
    InitStack(&stk);
    for (i = 0; i < length; i++)
    {
        if (isdigit(expression[i]))
        {
            result[idx++] = expression[i];
        }
        else
        {
            if (result[idx - 1] != ' ') /* preventing double space & making more convenient readiness in result by making space */
            {
                result[idx++] = ' ';
            }
            if (IsEmpty(&stk) == TRUE) /* If stack is empty */
            {
                Push(&stk, expression[i]);
            }
            else /* In case of that stack is not empty */
            {
                if (expression[i] == '(')
                {
                    Push(&stk, expression[i]);
                }
                else if (expression[i] == ')')
                {
                    while (Peek(&stk) != '(')
                    {
                        result[idx++] = Pop(&stk);  /* popping operators except '(' */
                        if (result[idx - 1] != ' ') /* preventing double space & making more convenient readiness in result by making space */
                        {
                            result[idx++] = ' ';
                        }
                    }
                    Pop(&stk); /* Popping '(' */
                }
                else
                {
                    if (compPriority(Peek(&stk), expression[i]) == -1) /* In case that stk's top < expression[i] */
                    {
                        Push(&stk, expression[i]);
                    }
                    else
                    {
                        while (compPriority(Peek(&stk), expression[i]) != -1 && Peek(&stk) != '(')
                        {
                            result[idx++] = Pop(&stk);
                            if (result[idx] != ' ') /* preventing double space & making more convenient readiness in result by making space */
                            {
                                result[idx++] = ' ';
                            }
                        }
                        Push(&stk, expression[i]);
                    }
                }
            }
        }
    }

    while (!IsEmpty(&stk))
    {
        op = Pop(&stk);
        if (op != '(')
        {
            if (result[idx - 1] != ' ')
            {
                result[idx++] = ' ';
            }
            result[idx++] = op;
        }
    }

    strcpy(expression, result);
    free(result);
    free(stk.s_arr);
}