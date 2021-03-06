# ExpressionTree

# 1. Expression Tree

<br/>

<br/>

## 1-A. What is Expression Tree?

<br/>

The expression tree is a **BinaryTree** that **contains all operands and operators** of an expression. Let's assume that there is an expression "**1+2\*7**". Then this expression can be converted into the following **BinaryTree**.

<br/>

![ExpressionTree_Figure1-1](./images/ExpressionTree_Figure1-1.png)

<br/>

As you can see in above _Figure 1-1_, **one operand node** is surrounded with **child nodes that contain an operand or an operator**. If so, how can this expression tree calculate the result? In case of the expression tree, **the higher the level of the operator node, the faster it is calculated**. On this expression tree, **as the level of the multiplication operator between 2 and 7 is highest**, it is calculated at the **first time**. As a result, the tree is converted into following tree in _Figure 1-2_.

<br/>

<br/>

![ExpressionTree_Figure1-2](./images/ExpressionTree_Figure1-2.png)

<br/>

After that, **the same process** is also applied to **other remaining nodes**. As a result, the **total calculation value is evaluated as 1+14 = 15**. As you can see them, using expression tree is an easy job. However, the difficulty in expression tree comes from **making tree based on expression**.

<br/>

<br/>

## 1-B. How to convert expression to ExpressionTree?

<br/>

If we are given infix expression, how can we change it as an expression tree? Before doing it, the **change from infix expression to postfix expression is required**.

<br/>

What changes it to postfix expression is [Expression Convertor](https://github.com/Yangseungchan/DataStructure-based-on-C/tree/master/Stacks/ExpressionConvertor) which has been done in chapter **Stacks**. By changing to **postfix expression**, it can be easier for system to **convert expression to expression tree**.

<br/>

After that, it's now ready to change postfix expression into expression tree. For this process, the two data structures are required. One is **Binary Tree** which is **needed for visualizing expression tree**. This is the changed version of [Binary Search Tree](https://github.com/Yangseungchan/DataStructure-based-on-C/tree/master/Tree/BST) which **has no searching function**. The second data structure is **Stack that contains nodes which are same nodes in Binary Tree** for **inserting nodes into Binary Tree**. How can be done with these two data structures?

<br/>

<br/>

![ExpressionTree_Figure1-2-1](./images/ExpressionTree_Figure1-2-1.png)

<br/>

Let's build an expression tree with **postfix expression** such as **"7 4 2 \* + 1 -"** which came from **infix expression** **"7+4\*2-1"**.

<br/>

Unlike the convertor from infix to postfix, **the operands are pushed into stack** like above **#1** in _Figure 1-2-1_ . However, when **an operator is read**, the operator **becomes the root node** of the subtree. And **the two nodes**(mostly operands but sometimes operators) **which were pushed previously** are **popped for making an expression as a pair of one operator with two operands** like above **#2-1 ~ #2-2** in _Figure 1-2-1_.

<br/>

What you can notice is that the **first popped operand becomes right child** of the operator and the **second popped one becomes left child of the operator** which is for **making them in the order of calculation**. Once the subtree which has three nodes is made, the **root node of the subtree is supposed to be pushed into stack**.

<br/>

<br/>

![ExpressionTree_Figure1-2-2](./images/ExpressionTree_Figure1-2-2.png)

<br/>

![ExpressionTree_Figure1-2-3](./images/ExpressionTree_Figure1-2-3.png)

<br/>

Likewise, if the operator is read, then the **two nodes which had been pushed is popped to create the subtree** like above _Figure 1-2-2_. Then **the newly made subtree is pushed into Stack**. These processes are **repeated until there is nothing to read from given postfix expression**. After the processes are done, finally, the finshed expression tree is created like _Figure 1-2-3_.

<br/>

<br/>

![ExpressionTree_Figure1-3](./images/ExpressionTree_Figure1-3.png)

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

![ExpressionTree_Figure2-1](./images/ExpressionTree_Figure2-1.png)

<br/>

As I mentioned, **for converting given expression into expression tree**, it is needed to convert it to **postfix expression**. The ExpressionConvertor uses two source codes named _CharStack.c_ and _ExpressionConvertor.c_. After that, the **postfix expression needs to be converted into ExpressionTree** using **Tree Convertor**. **Tree convertor** uses three source codes named _NodeStack.c_, _BinaryTree.c_ and _ExpressionTree.c_. Above _Figure 2-1_ is the diagram about these procedures.

<br/>

<br/>

# 3. Functions

As you can see in _Figure 2-1_, the **expression tree is composed of three parts**. The **first one is Expression Convertor,** the **second one is the Tree convertor** and **the third one is Main Function part**. Because I already discussed about the first part in chapter [Expression Convertor](https://github.com/Yangseungchan/DataStructure-based-on-C/tree/master/Stacks/ExpressionConvertor), I will talk **the second part which is about converting to tree from postfix expression** and **the third part which is about main function** which **includes converting to expressions from expression tree**.

<br/>

<br/>

## 3-1. Tree Convertor

<br/>

<br/>

## 3-1-A. BinaryTree.c

<br/>

### A-1. void ConnectNode(BinNode *nde, BinNode *left, BinNode \*right)

<br/>

It is the function that **connects the BinNode nde with the two BinNodes as the childs**.

<br/>

<br/>

### A-2. int RemoveTree(BinNode \*\*root)

<br/>

It is the function **removes the tree when disallocating the allocated the ExpressionTree**. It accesses all nodes in BinaryTree **recursively** as it is supposed to remove **all root nodes of subtree in the one whole BinaryTree**. As you can see in the code of this function, the **left node of the current root node becomes new root node of the left subtree**. And **the right node is done as the same way with left node**. After it removes the root node of current tree, the function is exited.

<br/>

<br/>

Other functions are skipped as there is no big difference compared to [Binary Search Tree](https://github.com/Yangseungchan/DataStructure-based-on-C/tree/master/Tree/BST).

<br/>

<br/>

## 3-1-B. NodeStack.c

<br/>

### B-1. BinNode *\_Pop(BNStack *stk)

<br/>

It is the function that **pops the top component of stack and returns the top BinNode**.

<br/>

<br/>

Other functions are skipped as there is no big difference compared to [CharStack](https://github.com/Yangseungchan/DataStructure-based-on-C/blob/master/Tree/ExpressionTree/CharStack.c)

<br/>

<br/>

## 3-1-C. ExpressionTree.c

<br/>

### C-1. int is_digit(char \*token)

<br/>

It is the function that **checks whether the given token(a collection of chars) is number or not**. It checks **two conditions** to confirm it. **One condition is checking the return value of function atoi** which changes the given string into number and **returns 0 if given token is not number**. **Second condition is the given string is not "0" using strcmp** because there can be cases that the given token is "0". By theses conditions, the given token is decided to be digit then it returns _TRUE(1)_. Else it returns _FALSE(0)_.

<br/>

<br/>

### C-2. BinNode \*MakeExpTree(char expression[MAXEXP])

<br/>

<br/>

![ExpressionTree_Figure3-1](./images/ExpressionTree_Figure3-1.png)

<br/>

It is the function that **makes expression tree using given postfix expression**. This function can be expressed as the above _Figure 3-1_.

<br/>

As I mentioned in **_chapter 1-B_**, the process of converting to expression tree becomes different by checking that the digit is read or not using function **is_digit**. When the **digit is read**, **the new node for BinaryTree is created and contains the read digit** like upper one in _Figure 1-2-1_. However, **if the read one is not digit but operator** then **the new node that contains operator is created popping two nodes in Stack for creating new subtree** like lower one in _Figure 1-2-1_.

<br/>

These processes **are repeated until there is no more things to be read in given postfix expression**. After that, the **root node of expression tree becomes a node at top of the stack** which is returned at the end of this function. Before returning the root node. **it clears out the allocated stack** which is **used for converting process**.

<br/>

<br/>

### C-3. int EvaluateExpTree(BinNode \*nde)

<br/>

<br/>

![ExpressionTree_Figure3-2](./images/ExpressionTree_Figure3-2.png)

<br/>

![ExpressionTree_Figure3-3](./images/ExpressionTree_Figure3-3.png)

<br/>

It is the function that **evaluates the total value of the given expression tree**. As you can see the code of this function, it is **recursive function**. The reason I made this function as recursive function is that the converted expression tree is **the collection of subtrees**. As you can see in _Figure 3-2_, the converted expression tree can be considered as the **collection of subtree which has one operator with two operands.** That's why the expression tree can be expressed easier like the _Figure 3-3_.

<br/>

Based on these facts, calculating the expression tree should be done **after calculating left subtree and right subtree**. After **finishing calculation of left subtree and right subtree** which becomes each left operand and right operand, **the calculation between these two operands is done based on the read operator**. And then it returns the result value to become the upper tree's operand.

<br/>

<br/>

### C-4. showInfixExp(BinNode *nde), showPostfixExp(BinNode *nde), showPrefixExp(BinNode \*nde)

It is the function that **converts the given expression tree into infix(or postfix or prefix) expression**. What you have to do is just **traveling the given tree as the appropriate order**. For example, function showInfixExp is supposed to **travel the expression tree by preorder traversal visiting in order of left child, root node, right child.** And for **improving the visuality**, whenever the root node value is printed, **the space(" ") is inserted.**

<br/>

<br/>

# 4. Conclusion

It is the program that **converts the given expression into expression tree and convert it into expression again**. As this program uses both stack and binary tree considering the rules of expression for realizing this function, it is considered one of the most complicated programs in my thought.
