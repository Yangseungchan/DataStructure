#ifndef __CHARSTACK_H__
#define __CHARSTACK_H__

#define TRUE 1
#define FALSE 0
#define MAX 500

typedef struct __Stack
{
    char *s_arr; /* array that contains numbers and plays a role as stack */
    int top;     /* top component's index */
    int max;     /* maximum capacity of stack */
} Stack;

void InitStack(Stack *stk); /* function that initializes the new stack */

void Push(Stack *stk, char ch); /* function that pushes new number to stack */

char Pop(Stack *stk); /* function that pops a number from stack */

char Peek(Stack *stk); /* function that prints the top component in stack */

void PrintStack(Stack *stk); /* function that prints the whole components in stack */

int IsEmpty(Stack *stk); /* function that indicates whether the stack is empty */

int IsFull(Stack *stk); /* function that indicates whether the stack is full */

char Search(Stack *stk, char ch); /* function that finds the input number in stack */

void Clear(Stack *stk); /* function that clears all components in stack */

#endif