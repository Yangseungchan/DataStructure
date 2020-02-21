# IntSet

# 1. Introduction

<br/>

It is **Set** that contains **integer datas in array**. The Set has **two special conditions**.

<br/>

1. **Order of datas are not concerned**.
2. There is **no same data** in array.

Based on them, there are basic calculations for **Set** which is **somehow different from general calculations**.

<br/>

## 1-A. Basic Conception of IntSet

<br/>

![IntSet_Figure1-1](https://i.imgur.com/PtokPLm.png)

<br/>

As you can see in above _Figure 1-1_, the Sets can be described with two arrays. Based on **two special conditions**, each array **can't contain any same data** and **doesn't concern any order in array**.

<br/>

## 1-B. Union

<br/>

![IntSet_Figure1-2](https://i.imgur.com/fuyQ2QK.png#.Xk_CuI4815U.link)

<br/>

As you can see in _Figure 1-2_, **Union calculation** can be interpreted as **the sum of two different sets** .

<br/>

## 1-C. Difference

<br/>

![IntSet_Figure1-3](https://i.imgur.com/rxcOmuV.png#.Xk_CuNbyDJQ.link)

<br/>

As you can see in _Figure 1-3_, **Difference calculation** can be interpreted as the **subtraction of two sets**.

<br/>

## 1-D. Intersection

<br/>

![Figure1-4](https://i.imgur.com/cS31aGu.png#.Xk_CuCU_DoQ.link)

<br/>

As you can see in _Figure 1-4_, **Intersection calculation** can be interpreted as the **common components of two sets**.

<br/>

# 2. ADT(Abstract Data Type)

<br/>

## 2-1. ADT of IntSet

<br/>

```mermaid

graph LR

A(IntSet) --- B[int *IntSet]

A --- C[int max]

A --- D[int num]

B --- E(int type pointer that points the int type array which contains datas of set.)

C --- F(int type index that indicates the maximum size of the array IntSet)

D --- G(int type variabe that indicates the number of components in array IntSet)

```

<br/>

# 3. Function

<br/>

## 3-1. void InitSet(IntSet \*s, int max)

<br/>

It is the function that **initializes the IntSet**. **s->max** is set as **input max**, **s->num** is set as **0** for indicating **there is no data in IntSet s**. And IntSet is allocated for **max** x **sizeof(int).**

<br/>

## 3-2. int IsMember(const IntSet \*s, int n)

<br/>

It is the function that **indicates whether the number is member of IntSet s**. By searching through all components in array IntSet, if it finds **integer which is same with n**, it **returns the index of it**. If not so, it **returns _FALSE_** which is defined in header file as _-1_.

<br/>

## 3-3. void Add(IntSet \*s, int n)

<br/>

![Figure3-1](https://i.imgur.com/znPFD9W.png#.Xk_hvAvqxIQ.link)

<br/>

It is function that **adds number n to IntSet s**. If it is checked that **s->num is less than s->max**, then also checks whether **n is the member of IntSet s**. If so then **number n is added at index s->num** while **s->num is increased by 1**.

<br/>

## 3-4. void Remove(IntSet \*s, int n)

<br/>

![IntSet_Figure3-2](https://i.imgur.com/IpA1zvf.png#.Xk_hvCGDusM.link)

<br/>

It is the function that **removes number in IntSet s**. First it checks **whether IntSet s has at least one member**. If so, then **it also checks whehter the number n exists in IntSet s**.
If all of these are checked, then removal is gonna be done. When removal is done, **empty space is filled with the last component** like _Figure 1-6_. If **s->num is only 1,** then **it just removes the target component**.

<br/>

## 3-5. int Size(IntSet \*s)

It is the function that **returns number of components in IntSet s(s->num)**.

<br/>

## 3-6. int Capacity(IntSet \*s)

It is the function that **returns capacity of IntSet s(s->max)**.

<br/>

## 3-7. void Assign(IntSet *s1, const IntSet *s2)

<br/>

![IntSet_Figure3-3](https://i.imgur.com/BL5tuEY.png#.Xk_hvHtj3U4.link)

It is the function that **assigns all components in s2 to s1**. It is like **copying all components of s2 to s1**. However, it depends on **s1->max**. If **s1->max is less than s2->num** then, **s1->num is set to s1->max** which means that **only s1->max of s2->num components are assigned to IntSet s1**.

<br/>

## 3-8. int Equal(const IntSet *s1, const IntSet *s2)

It is the function that **indicates whether these two IntSets are equal or not**. First, it checks **s1->num and s2->num are same**. If they are **considered to be same**, then it **compares all components for checking the sameness**.

<br/>

## 3-9. void Union(IntSet *s1, const IntSet *s2, const IntSet \*s3)

It is the function that makes **Union set of s2 and s3**(like _chapter 1-B_) and returns the result to **s1**.

<br/>

![IntSet_Figure3-4](https://i.imgur.com/eihCnmM.png)

<br/>

As you can see in _Figure 3-4_, at first, function **Union assigns s2 to s1** like **yellow part**. And then, **green part is added** by **adding s3 which is not in s1**.

<br/>
  
## 3-10. void  Difference(IntSet  *s1,  const  IntSet  *s2,  const  IntSet  *s3)

It is the function that makes **difference set of s2 and s3**(_like chapter 1-C_) and returns it to s1.

<br/>

![IntSet_Figure3-5](https://i.imgur.com/06bhsP8.png)

<br/>

As you can see in _Figure 3-5_, the difference is making **a set which is s2 but not s3**. It is started by **assigning s2 to s1**. After that **by removing s3's member which are also member of s2**, the difference is done.

<br/>

## 3-11. void Intersection(IntSet *s1, const IntSet *s2, const IntSet \*s3)

It is the function that **makes intersecting set of s2 and s3**(_like chapter 1-D_) and returns it to s1.

<br/>

![IntSet_Figure3-6](https://i.imgur.com/4iZViSK.png)

<br/>

As you can see in _Figure 3-6_, it is finding the set **which is not only s2 but also s3**. By **adding s3 members to s1** which **are also s2 members**, it can be done.

<br/>

## 3-12. void PrintSet(const IntSet \*s)

It is the function that **prints all number in IntSet s in form of {1,2,3}**.

<br/>

## 3-13. void ClearSet(IntSet \*s)

It is function that clears all numbers in IntSet s and setting max and num as 0.

<br/>

# 4. Conclusion

<br/>

It is the **Set based on array**. By using the feature of array, the **basic calculations** of Set can be realized.
