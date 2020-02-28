# BitSet

# 1. Introduction

<br/>

## 1-A. Bit based on unsigned int

![BitSet_Figure1-1](./images/BitSet_Figure1-1.png)

<br/>

It is the **Set that based on the Bit of unsigned integer**. As **unsigned integer** is **4Byte** size data structure, it can contain 32 bits on it. Using these 32bits, it can describe numbers **from 0 to 31** like _Figure 1-1_.

<br/>

## 1-B. Bit that describes a Set

<br/>

![BitSet_Figure1-2](./images/BitSet_Figure1-2.png)

<br/>

As you can see in _Figure 1-2_, the **Bit in unsigned int** can be described as a Set. Each **1 bit** is the number in the Set.

<br/>

# 2. ADT(Abstract Data Type)

<br/>

> **unsigned int** is re-defined as **BitSet**
>
> **BitSetNull** indicates **the set which has only 0 bits**.
>
> **BitSetNum** is the constant that **contains the number of bits in BitSet**.

<br/>

# 3. Function

<br/>

## 3-1. SetOf(no) ((BitSet)1 << no)

<br/>

It is a macro function that converts input integer number as BitSet by **using bit left shift operator**.

<br/>

## 3-2. int IsMember(BitSet s, int n)

<br/>

It is the function that checks **whether n is a member of BitSet s.** It can be checked by using **AND bit** operator **between BitSet s and SetOf(n)** .

<br/>

![BitSet_Figure3-1-1](./images/BitSet_Figure3-1-1.png)

<br/>

If integer **n is a member of BitSet s**, then it **returns SetOf(n)** like _Figure 3-1-1_.

<br/>

![BitSet_Figure3-1-2](./images/BitSet_Figure3-1-2.png)

<br/>

If integer **n is not member of BitSet s**, then it **returns SetOf(0)** like _Figure 3-1-2_.

<br/>

## 3-3. void Add(BitSet \*s, int n)

It is function that adds n to BitSet s. It can be done by **using OR bit operator**. **Bit OR operator** can make result bit as **1 if at least one of two bits is 1**.

<br/>

![BitSet_Figure3-2](./images/BitSet_Figure3-2.png)

<br/>

For example, when you try to add 8 to BitSet s, it can be done by using OR operator with SetOf(8). As **8th bit in SetOf(8) is 1**, the **result bit also becomes 1** like _Figure 3-2-1_.

<br/>

## 3-4. void Remove(BitSet \*s, int n)

It is the function that **removes n from BitSet s**. It can be done by using bit operator **AND** and **NOT**. **NOT operator** is **exchanging 1bit with 0bit (or 0bit with 1bit)**.

<br/>

![BitSet_Figure3-3](./images/BitSet_Figure3-3.png)

<br/>

By **taking NOT operator on SetOf(8)**, every bit in SetOf(8) becomes 1 except the 8th bit. After that, **taking AND operator s with ~SetOf(8)** can **remove 1bit at 8th bit from BitSet s** like _Figure 3-3._

## 3-5. int Size(BitSet s)

It is the function that **returns the size of BitSet s**. It can be done **by using AND operator**.

<br/>

![BitSet_Figure3-4-1](./images/BitSet_Figure3-4-1.png)

![BitSet_Figure3-4-2](./images/BitSet_Figure3-4-2.png)
<br/>

Before using **AND operator**, you need to to make **BitSet s-1**. After that, you have to **take AND operator s with s-1**. By doing so, you can **remove rightmost 1 bit in BitSet s** like _Figure 3-4-1_ and _Figure 3-4-2_. It is done until s is not 0. While you are doing so, **you have to count how many AND operators have been taken**.

<br/>

## 3-6. void Print(BitSet s)

<br/>

It is function that **prints the datas of BitSet in form of ordinary Set**. By comparing all bits in BitSet using function IsMember, it prints the data if IsMember returns positive integer.

<br/>

## 3-7. void Println(BitSet s)

It is the function that **prints the BitSet s using function Print and prints new line**.

<br/>

# 4. Conclusion

<br/>

By using bit operator and unsigned integer, it can express the Set simply. However, as it uses the unsigned integer, it can only express the integer from 0 to 31.
