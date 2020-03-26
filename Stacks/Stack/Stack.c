#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

void InitStack(Stack *stk) /* function that initializes the new stack */
{
    stk->s_arr = calloc(MAX, sizeof(int));
    for (size_t i = 0; i < MAX; i++)
    {
        stk->s_arr[i] = -1;
    }
    stk->max = MAX;
    stk->top = -1;
}

void Push(Stack *stk, int num) /* function that pushes new number to stack */
{
    if (IsFull(stk) == FALSE) /* Push only when top index is smaller than max */
    {
        stk->s_arr[++stk->top] = num;
    }
}

int Pop(Stack *stk) /* function that pops a number from stack */
{
    if (IsEmpty(stk) == FALSE)
    {
        return stk->s_arr[stk->top--];
    }
}

int Peek(Stack *stk) /* function that prints the top component in stack */
{
    return stk->s_arr[stk->top];
}

void PrintStack(Stack *stk) /* function that prints the whole components in stack */
{
    if (IsEmpty(stk) == FALSE)
    {
        for (size_t i = 0; i <= stk->top; i++)
        {
            printf("%d ", stk->s_arr[i]);
        }
        putchar('\n');
    }
}

int IsEmpty(Stack *stk) /* function that indicates whether the stack is empty */
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

int IsFull(Stack *stk) /* function that indicates whether the stack is full */
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

int Search(Stack *stk, int num) /* function that finds the input number in stack */
{
    if (IsEmpty(stk) == FALSE)
    {
        for (size_t i = 0; i <= stk->top; i++)
        {
            if (stk->s_arr[i] == num)
            {
                return i;
            }
        }
        return FALSE;
    }
    else
    {
        return FALSE;
    }
}

void Clear(Stack *stk) /* function that clears all components in stack */
{
    if (IsEmpty(stk) == FALSE)
    {
        do
        {
            Pop(stk);
        } while (IsEmpty(stk) == FALSE);
    }
}