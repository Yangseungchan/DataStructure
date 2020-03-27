#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "CharStack.h"
#include "FormulaConvertor.h"

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
    else
    {
        return -1;
    }
}

void convertFormula(char formula[], int length)
{
    int i, idx, value;
    Stack stk;
    char op;
    char *result = calloc(sizeof(char), length * 2);

    idx = 0;
    InitStack(&stk);
    for (i = 0; i < length; i++)
    {
        if (isdigit(formula[i]))
        {
            result[idx++] = formula[i];
        }
        else
        {
            if (result[idx - 1] != ' ')
            {
                result[idx++] = ' ';
            }
            if (IsEmpty(&stk) == TRUE) /* If stack is empty */
            {
                Push(&stk, formula[i]);
            }
            else /* In case of that stack is not empty */
            {
                if (formula[i] == '(')
                {
                    Push(&stk, formula[i]);
                }
                else if (formula[i] == ')')
                {
                    while (Peek(&stk) != '(')
                    {
                        result[idx++] = Pop(&stk); /* popping operators except '(' */
                        if (result[idx - 1] != ' ')
                        {
                            result[idx++] = ' ';
                        }
                    }
                    Pop(&stk); /* Popping '(' */
                }
                else
                {
                    if (compPriority(Peek(&stk), formula[i]) == -1) /* In case that stk's top < formula[i] */
                    {
                        Push(&stk, formula[i]);
                    }
                    else
                    {
                        while (compPriority(Peek(&stk), formula[i]) != -1 && Peek(&stk) != '(')
                        {
                            result[idx++] = Pop(&stk);
                            if (result[idx] != ' ')
                            {
                                result[idx++] = ' ';
                            }
                        }
                        Push(&stk, formula[i]);
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

    strcpy(formula, result);
    free(result);
}