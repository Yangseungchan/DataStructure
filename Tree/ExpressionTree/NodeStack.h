#ifndef __NODESTACK_H__
#define __NODESTACK_H__

#include "BinaryTree.h"

#define TRUE 1
#define FALSE 0
#define MAX 100

typedef struct __bnstack
{
    int max;               /* maximum capacity of stack */
    int top;               /* top component's index */
    BinNode *nde_arr[MAX]; /* array that contains numbers and plays a role as stack */
} BNStack;

void _InitStack(BNStack *stk); /* function that initializes the new stack */

void _Push(BNStack *stk, BinNode *nde); /* function that pushes new number to stack */

BinNode *_Pop(BNStack *stk); /* function that pops a number from stack */

BinNode _Peek(BNStack *stk); /* function that prints the top component in stack */

void _PrintStack(BNStack *stk); /* function that prints the whole components in stack */

int _IsEmpty(BNStack *stk); /* function that indicates whether the stack is empty */

int _IsFull(BNStack *stk); /* function that indicates whether the stack is full */

void _Clear(BNStack *stk); /* function that clears all components in stack */

#endif