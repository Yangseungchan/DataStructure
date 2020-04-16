#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"
#include "NodeStack.h"

void _InitStack(BNStack *stk) /* function that initializes the new stack */
{
    for (int i = 0; i < stk->max; i++)
    {
        stk->nde_arr[i] = calloc(1, sizeof(BinNode));
    }
    stk->max = MAX;
    stk->top = -1;
}

void _Push(BNStack *stk, BinNode *nde) /* function that pushes new token to stack */
{
    if (_IsFull(stk) == FALSE) /* Push only when top index is smaller than max */
    {
        stk->nde_arr[++stk->top] = nde;
    }
}

BinNode *_Pop(BNStack *stk) /* function that pops a number from stack */
{
    if (_IsEmpty(stk) == FALSE)
    {
        BinNode *nde = calloc(1, sizeof(BinNode));
        nde = stk->nde_arr[stk->top];
        stk->nde_arr[stk->top--] = NULL;
        return nde;
    }
}

BinNode _Peek(BNStack *stk) /* function that prints the top component in stack */
{
    return *stk->nde_arr[stk->top];
}

void _PrintStack(BNStack *stk) /* function that prints the whole components in stack */
{
    if (_IsEmpty(stk) == FALSE)
    {
        for (size_t i = 0; i <= stk->top; i++)
        {
            printf("%s ", stk->nde_arr[i]->data);
        }
        putchar('\n');
    }
}

int _IsEmpty(BNStack *stk) /* function that indicates whether the stack is empty */
{
    if (stk->top > -1)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

int _IsFull(BNStack *stk) /* function that indicates whether the stack is full */
{
    if (stk->top < stk->max - 1)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

void _Clear(BNStack *stk) /* function that clears all components in stack */
{
    if (_IsEmpty(stk) == FALSE)
    {
        do
        {
            _Pop(stk);
        } while (_IsEmpty(stk) == FALSE);
        for (int i = 0; i < stk->max; i++)
        {
            free(stk->nde_arr[i]);
        }
    }
}