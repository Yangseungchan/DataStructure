#include <stdio.h>
#include "IntSet.h"

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
    IntSet s1, s2, temp;
    InitSet(&s1, MAX);
    InitSet(&s2, MAX);
    InitSet(&temp, MAX);

    while (1)
    {
        int menu, data, idx;
        printf("s1 = ");
        PrintSet(&s1);
        printf("s2 = ");
        PrintSet(&s2);
        printf("(1)Add to s1 (2) Remove from s1 (3)Search in s1 (4)Assign s1 to s2 (5)Set Calculations for s1 and s2\n");
        printf("(6)Add to s2 (7) Remove from s2 (8)Search in s2 (9)Assign s2 to s1 (0)Terminate : ");

        scanf("%d", &menu);
        if (menu == 0)
            break;
        switch (menu)
        {
        case 1:
            data = scan_data(ADD);
            Add(&s1, data);
            break;
        case 2:
            data = scan_data(RMV);
            Remove(&s1, data);
            break;
        case 3:
            data = scan_data(SCH);
            printf("It is %s", ((idx = IsMember(&s1, data)) >= 0 ? "found.\n" : "not found.\n"));
            putchar('\n');
            break;
        case 4:
            Assign(&s2, &s1);
            break;
        case 5:
            Union(&temp, &s1, &s2);
            printf("s1 | s2 = ");
            PrintSet(&temp);
            putchar('\n');

            Intersection(&temp, &s1, &s2);
            printf("s1 & s2 = ");
            PrintSet(&temp);
            putchar('\n');

            Difference(&temp, &s1, &s2);
            printf("s1 - s2 = ");
            PrintSet(&temp);
            putchar('\n');

            break;
        case 6:
            data = scan_data(ADD);
            Add(&s2, data);
            break;
        case 7:
            data = scan_data(RMV);
            Remove(&s2, data);
            break;
        case 8:
            data = scan_data(SCH);
            printf("It is %s", ((idx = IsMember(&s2, data)) >= 0 ? "found.\n" : "not found.\n"));
            putchar('\n');
            break;
        case 9:
            Assign(&s1, &s2);
            break;
        }
    }
    ClearSet(&s1);
    ClearSet(&s2);
    ClearSet(&temp);

    return 0;
}