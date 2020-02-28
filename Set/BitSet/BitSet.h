#ifndef __BITSET_H__
#define __BITSET_H__

#define BitSetNum 32
#define BitSetNull (BitSet)0
#define SetOf(no) ((BitSet)1 << no)

typedef unsigned int BitSet;

int IsMember(BitSet s, int n); /* function that checks whehter n is a member of BitSet s */

void Add(BitSet *s, int n); /* function that adds n to BitSet s */

void Remove(BitSet *s, int n); /* function that removes n from BitSet s */

int Size(BitSet s); /* function that returns the size of it */

void Print(BitSet s); /* function that prints the datas of BitSet s */

void Println(BitSet s); /* function that prints BitSet s using Print with newline*/

#endif