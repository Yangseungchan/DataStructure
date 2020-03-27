#include <stdio.h>
#include <string.h>
#include "FormulaConvertor.h"

int main(void)
{
    char formula[1000];
    int i, length;
    printf("<Convertor from infix to postfix>\n");
    printf("Input mathematical expression without space[+, -, *, /, (, ) are possible] : ");
    scanf("%s", formula);

    length = strlen(formula);

    convertFormula(formula, length);
    putchar('\n');
    printf("result : %s\n", formula);

    return 0;
}