#ifndef __EXPRESSIONCONVERTOR_H__
#define __EXPRESSIONCONVERTOR_H__

int opPriority(char op); /* function that returns the priority of operation */

int compPriority(char op1, char op2); /* function that compares given two operartions */

void convertExpression(char expression[], int length); /* function that converts the formula from infix to postfix */

#endif