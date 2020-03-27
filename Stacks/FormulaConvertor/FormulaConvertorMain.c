#include <stdio.h>
#include <string.h>
#include "FormulaConvertor.h"

int main(void)
{
    char formula[1000];
    int i, length;
    scanf("%s", formula);

    length = strlen(formula);

    convertFormula(formula, length);
    printf("%s\n", formula);

    return 0;
}