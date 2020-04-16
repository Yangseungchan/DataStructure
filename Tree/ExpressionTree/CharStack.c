#include <stdio.h>
#include <stdlib.h>
#include "CharStack.h"

void InitStack(Stack *stk) /* function that initializes the new stack */
{
    stk->s_arr = calloc(MAX, sizeof(char));
    stk->max = MAX;
    stk->top = -1;
}

void Push(Stack *stk, char ch) /* function that pushes new number to stack */
{
    if (IsFull(stk) == FALSE) /* Push only when top index is smaller than max */
    {
        stk->s_arr[++stk->top] = ch;
    }
}

char Pop(Stack *stk) /* function that pops a number from stack */
{
    if (IsEmpty(stk) == FALSE)
    {
        return stk->s_arr[stk->top--];
    }
}

char Peek(Stack *stk) /* function that prints the top component in stack */
{
    return stk->s_arr[stk->top];
}

void PrintStack(Stack *stk) /* function that prints the whole components in stack */
{
    if (IsEmpty(stk) == FALSE)
    {
        for (size_t i = 0; i <= stk->top; i++)
        {
            printf("%c ", stk->s_arr[i]);
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

char Search(Stack *stk, char ch) /* function that finds the input number in stack */
{
    if (IsEmpty(stk) == FALSE)
    {
        for (size_t i = 0; i <= stk->top; i++)
        {
            if (stk->s_arr[i] == ch)
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