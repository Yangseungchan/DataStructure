#ifndef __FORMULACONVERTOR_H__
#define __FORMULACONVERTOR_H__

int opPriority(char op); /* function that returns the priority of operation */

int compPriority(char op1, char op2); /* function that compares given two operartions */

void convertFormula(char formula[], int length); /* function that converts the formula from infix to postfix */

#endif