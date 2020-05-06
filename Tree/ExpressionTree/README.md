# ExpressionTree

# 1. Expression Tree

<br/>

<br/>

## 1-A. What is Expression Tree?

<br/>

The expression tree is a **BinaryTree** that **contains all operands and operators** of an expression. Let's assume that there is an expression "**1+2\*7**". Then this expression can be converted into the following **BinaryTree**.

<br/>

![ExpressionTree_Figure1-1](https://i.imgur.com/0stnzq8.png)

<br/>

As you can see in above _Figure 1-1_, **one operand node** is surrounded with **child nodes that contain an operand or an operator**. If so, how can this expression tree calculate the result? In case of the expression tree, **the higher the level of the operator node, the faster it is calculated**. On this expression tree, **as the level of the multiplication operator between 2 and 7 is highest**, it is calculated at the **first time**. As a result, the tree is converted into following tree in _Figure 1-2_.

<br/>

<br/>

![ExpressionTree_Figure1-2](https://i.imgur.com/irbfuDO.png)

<br/>

After that, **the same process** is also applied to **other remaining nodes**. As a result, the **total calculation value is evaluated as 1+14 = 15**. As you can see them, using expression tree is an easy job. However, the difficulty in expression tree comes from **making tree based on expression**.

<br/>

<br/>

## 1-B. How to convert expression to ExpressionTree?

<br/>

If we are given infix expression, how can we change it as an expression tree? For doing so, the **1 process is required**.

<br/>

What you are required is to change **infix expression to postfix expression**. What changes it to postfix expression is [Expression Convertor](https://github.com/Yangseungchan/DataStructure-based-on-C/tree/master/Stacks/ExpressionConvertor) which has been done in chapter **Stacks**. By changing to **postfix expression**, it can be easier for system to **convert expression to expression tree**.

<br/>

After that, it's now ready to change postfix expression into expression tree. For this process, the two data structures are required. One is **Binary Tree** which is **needed for visualizing expression tree**. This is the changed version of [Binary Search Tree](https://github.com/Yangseungchan/DataStructure-based-on-C/tree/master/Tree/BST) which **has no searching function**. The second data structure is **Stack that contains nodes which are same nodes in Binary Tree** for **inserting nodes into Binary Tree**. How can be done with these two data structures?

<br/>

<br/>

![ExpressionTree_Figure1-2-1](https://i.imgur.com/hhiVBks.png)

<br/>

Let's build an expression tree with **postfix expression** such as **"7 4 2 \* + 1 -"** which came from **infix expression** **"7+4\*2-1"**.

Unlike the convertor from infix to postfix, **the operands are pushed into stack** like above **#1** in Figure 1-2-1 . However, when **an operator is read**, the operator **becomes the root node** of the subtree. And **the two nodes**(mostly operands but sometimes operators) **which were pushed previously** are **popped for making an expression as a pair of one operator with two operands** like above **#2-1 ~ #2-2** in _Figure 1-2-1_. What you can notice is that the **first popped operand becomes right child** of the operator and the **second popped one becomes left child of the operator** which is for **making them in the order of calculation**. Once the subtree which has three nodes is made, the **root node of the subtree is supposed to be pushed into stack**.

<br/>

<br/>

![ExpressionTree_Figure1-2-2](https://i.imgur.com/CfsI3AF.png)

<br/>

![ExpressionTree_Figure1-2-3](https://i.imgur.com/KhRNjzC.png)

<br/>

Likewise, if the operator is read, then the **two nodes which had been pushed is popped to create the subtree** like above _Figure 1-2-2_. Then **the newly made subtree is pushed into Stack**. These processes are **repeated until there is nothing to read from given postfix expression**. After the processes are done, finally, the finshed expression tree is created like _Figure 1-2-3_.

<br/>

<br/>

![ExpressionTree_Figure1-3](https://i.imgur.com/uETUmyt.png)

<br/>

To sum up those things, it can be summarized as above _Figure 1-3_.

<br/>

<br/>

# 2. ADT(Abstract Data Type)

<br/>

<br/>

## 2-1. DataStructures for Expression Tree Convertor

<br/>

```mermaid

graph LR

A(Expression Tree Convertor) --- B(Expression Convertor)

A --- C(Tree Convetor)

B --- D(CharStack)

D --- E[The Stack that contains character]

C --- F(NodeStack)

C --- G(BinaryTree)

F --- H[The Stack that contains BinNode]

G --- I[The tree that contains BinNode]



```

<br/>

<br/>

## 2-2. Source codes' flows of ExpressionTree

<br/>

![ExpressionTree_Figure2-1](https://i.imgur.com/M4AcFbP.png)

<br/>

As I mentioned, **for converting given expression into expression tree**, it is needed to convert it to **postfix expression**. The ExpressionConvertor uses two source codes named _CharStack.c_ and _ExpressionConvertor.c_. After that, the **postfix expression needs to be converted into ExpressionTree** using **Tree Convertor**. **Tree convertor** uses three source codes named _NodeStack.c_, _BinaryTree.c_ and _ExpressionTree.c_. Above _Figure 2-1_ is the diagram about these procedures.

<br/>

<br/>

# 3. Functions

<br/>

<br/>

## 3-1.

<br/>

<br/>

<br/>

## 3-2.

<br/>

<br/>

# 4. Conclusion
