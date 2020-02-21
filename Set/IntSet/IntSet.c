#include <stdio.h>
#include <stdlib.h>
#include "IntSet.h"

void InitSet(IntSet *s, int max) /* function that initializes the IntSet */
{
    s->max = max;
    s->num = 0;
    s->IntSet = calloc(max, sizeof(int));
}

int IsMember(const IntSet *s, int n) /* function that indicates whether the number is member of IntSet s */
{
    for (size_t i = 0; i < s->num; i++)
    {
        if (n == s->IntSet[i])
        {
            return i; /* If it finds that n is member of Set s, then it returns the index of num that is found */
        }
    }
    return FALSE;
}

void Add(IntSet *s, int n) /* function that adds number to IntSet s */
{
    if (s->num < s->max)
    {
        if (IsMember(s, n) == FALSE) /* only n doesn't exist in IntSet s */
        {
            s->IntSet[s->num++] = n;
        }
    }
}

void Remove(IntSet *s, int n) /* function that removes number in IntSet s */
{
    int idx;
    if (s->num > 0)
    {
        if ((idx = IsMember(s, n)) != FALSE) /* only n does exist in IntSet s */
        {
            if (s->num > 1)
            {
                s->IntSet[idx] = s->IntSet[--s->num]; /* replacing idx's number with the last number of IntSet s decreasing the number of components in IntSet s */
            }
            else
            {
                s->IntSet[idx] = 0;
                s->num--;
            }
        }
    }
}

int Size(IntSet *s) /* function that returns number of components in IntSet s*/
{
    return s->num;
}

int Capacity(IntSet *s) /* function that returns capacity of IntSet s */
{
    return s->max;
}

void Assign(IntSet *s1, const IntSet *s2) /* function that assigns all components in s2 to s1 */
{
    s1->num = (s1->max < s2->num) ? s1->max : s2->num; /* if s1->max is smaller than s2->num then, s1->num is s1->max else s2->num */
    for (size_t i = 0; i < s1->num; i++)
    {
        s1->IntSet[i] = s2->IntSet[i];
    }
}

int Equal(const IntSet *s1, const IntSet *s2) /* function that indicates whether these two IntSets are equal or not */
{
    int i, j;
    if (s1->num != s2->num)
    {
        return FALSE;
    }
    else
    {
        for (i = 0; i < s1->num; i++)
        {
            for (j = 0; j < s2->num; j++)
            {
                if (s1->IntSet[i] == s2->IntSet[j])
                {
                    break;
                }
            }
            if (j == s2->num) /* if j reachess s2->num which means there is no s2 member in s1 member, then it returns false */
            {
                return FALSE;
            }
        }
        return TRUE;
    }
}

void Union(IntSet *s1, const IntSet *s2, const IntSet *s3) /* function that makes union set of s2 and s3 and returns it to s1 */
{
    int num;
    s1->num = 0;    /* making s1 as empty set */
    Assign(s1, s2); /* assign all members of s2 to s1 */
    for (size_t i = 0; i < s3->num; i++)
    {
        num = s3->IntSet[i];
        if (IsMember(s1, num) == FALSE) /* only members of s3 which are not member of s1 are added to IntSet s1 */
        {
            Add(s1, num);
        }
    }
}

void Difference(IntSet *s1, const IntSet *s2, const IntSet *s3) /* function that makes difference set of s2 and s3 and returns it to s1 */
{
    int num;
    s1->num = 0; /* making s1 as empty set */
    Assign(s1, s2);
    for (size_t i = 0; i < s3->num; i++)
    {
        num = s3->IntSet[i];
        if (IsMember(s2, num) != FALSE) /* among s3 members which are member of s2 are removed from set s1 */
        {
            Remove(s1, num);
        }
    }
}

void Intersection(IntSet *s1, const IntSet *s2, const IntSet *s3) /* function that makes intersecting set of s2 and s3 and returns it to s1 */
{
    int num;
    s1->num = 0; /* making s1 as empty set */
    for (size_t i = 0; i < s3->num; i++)
    {
        num = s3->IntSet[i];
        if (IsMember(s2, num) != FALSE)
        {
            Add(s1, num);
        }
    }
}

void PrintSet(const IntSet *s) /* function that prints all number in IntSet s in form of {1,2,3} */
{
    printf("{");
    for (size_t i = 0; i < s->num; i++)
    {
        printf("%d ", s->IntSet[i]);
    }
    printf("}\n");
    putchar('\n');
}

void ClearSet(IntSet *s) /* function that clears all numbers in IntSet s */
{
    if (s->IntSet != NULL)
    {
        free(s->IntSet);
    }
    s->num = 0;
    s->max = 0;
}