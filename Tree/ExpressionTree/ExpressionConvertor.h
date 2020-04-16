#ifndef __EXPRESSIONCONVERTOR_H__
#define __EXPRESSIONCONVERTOR_H__

int opPriority(char op); /* function that returns the priority of an operator */

int compPriority(char op1, char op2); /* function that compares given two operators */

void convertExpression(char expression[], int length); /* function that converts the expression from infix to postfix */

#endif