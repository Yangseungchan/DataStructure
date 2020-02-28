#include <stdio.h>
#include "BitSet.h"

enum
{
    ADD,
    RMV,
    SCH
};

int scan_data(int md)
{
    int data;
    switch (md)
    {
    case ADD:
        printf("Input data to add : ");
        break;
    case RMV:
        printf("Input data to remove : ");
        break;
    case SCH:
        printf("Input data to search : ");
        break;
    }
    scanf("%d", &data);
    return data;
}

int main(void)
{
    BitSet s1 = BitSetNull;
    BitSet s2 = BitSetNull;

    while (1)
    {
        int menu, data, idx;
        printf("s1 = ");
        Println(s1);
        printf("s2 = ");
        Println(s2);
        putchar('\n');
        printf("(1)Add to s1 (2) Remove from s1 (3)Search in s1 (4)Set Calculations for s1 and s2\n");
        printf("(5)Add to s2 (6) Remove from s2 (7)Search in s2 (8)Terminate : ");
        scanf("%d", &menu);
        if (menu == 8)
            break;
        switch (menu)
        {
        case 1:
            data = scan_data(ADD);
            Add(&s1, data);
            putchar('\n');
            break;
        case 2:
            data = scan_data(RMV);
            Remove(&s1, data);
            putchar('\n');
            break;
        case 3:
            data = scan_data(SCH);
            printf("It is %s", ((idx = IsMember(s1, data)) >= 0 ? "found.\n" : "not found.\n"));
            putchar('\n');
            break;
        case 4:
            putchar('\n');
            printf("s1 | s2 = ");
            Println(s1 | s2);
            putchar('\n');

            printf("s1 & s2 = ");
            Println(s1 & s2);
            putchar('\n');

            printf("s1 - s2 = ");
            Println(s1 & (~s2));
            putchar('\n');

            break;
        case 5:
            data = scan_data(ADD);
            Add(&s2, data);
            putchar('\n');
            break;
        case 6:
            data = scan_data(RMV);
            Remove(&s2, data);
            putchar('\n');
            break;
        case 7:
            data = scan_data(SCH);
            printf("It is %s", ((idx = IsMember(s2, data)) >= 0 ? "found.\n" : "not found.\n"));
            putchar('\n');
            break;
        }
    }

    return 0;
}