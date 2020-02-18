#ifndef __INSET_H__
#define __INSET_H__

#define MAX 512
#define FALSE -1
#define TRUE 1

typedef struct __IntSet
{
    int max;     /* maximum capactiy of array */
    int num;     /* number of components in array */
    int *IntSet; /* Set array that contains integers */
} IntSet;

void InitSet(IntSet *s, int max); /* function that initializes the IntSet */

int IsMember(const IntSet *s, int n); /* function that indicates whether the number is member of IntSet s */

void Add(IntSet *s, int n); /* function that adds number to IntSet s */

void Remove(IntSet *s, int n); /* function that removes number in IntSet s */

int Size(IntSet *s); /* function that returns number of components in IntSet s*/

int Capacity(IntSet *s); /* function that returns capacity of IntSet s */

void Assign(IntSet *s1, const IntSet *s2); /* function that assigns all components in s2 to s1 */

int Equal(const IntSet *s1, const IntSet *s2); /* function that indicates whether these two IntSets are equal or not */

void Union(IntSet *s1, const IntSet *s2, const IntSet *s3); /* function that makes union set of s2 and s3 and returns it to s1 */

void Difference(IntSet *s1, const IntSet *s2, const IntSet *s3); /* function that makes difference set of s2 and s3 and returns it to s1 */

void Intersection(IntSet *s1, const IntSet *s2, const IntSet *s3); /* function that makes intersecting set of s2 and s3 and returns it to s1 */

void PrintSet(const IntSet *s); /* function that prints all number in IntSet s in form of {1,2,3} */

void ClearSet(IntSet *s); /* function that clears all numbers in IntSet s */

#endif