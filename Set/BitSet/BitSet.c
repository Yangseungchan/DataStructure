#include <stdio.h>

#define BitSetNum 32
#define BitSetNull (BitSet)0
#define SetOf(no) ((BitSet)1 << no)

typedef unsigned int BitSet;

int IsMember(BitSet s, int n) /* function that checks whehter n is a member of BitSet s */
{
    return s & SetOf(n);
}

void Add(BitSet *s, int n) /* function that adds n to BitSet s */
{
    (*s) |= SetOf(n);
}

void Remove(BitSet *s, int n) /* function that removes n from BitSet s */
{
    (*s) &= ~SetOf(n);
}

int Size(BitSet s) /* function that returns the size of it */
{
    int n = 0;
    for (; s != 0; n++)
    {
        s &= s - 1;
    }
    return n;
}

void Print(BitSet s) /* function that prints the datas of BitSet s */
{
    int i;
    printf("{ ");
    for (i = 0; i < BitSetNum; i++)
    {
        if (IsMember(s, i))
        {
            printf("%d ", i);
        }
    }
    printf("}");
}

void Println(BitSet s) /* function that prints BitSet s using Print with newline*/
{
    Print(s);
    putchar('\n');
}
