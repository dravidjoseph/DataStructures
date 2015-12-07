#Binary Search Tree Lab

##Purpose

This lab introduced Binary Search Trees as a way to store data. It builds on recursion, pointer usage, and inheritance concepts from previous labs.

##Concepts

###How a BST Works

The Binary Search Tree is built by linking nodes together using specific rules.  The first node is inserted at the head of the tree and is called the root.
Subsequent nodes are inserted relative to nodes that already exist in a tree.  For an arbitrary tree with *n* nodes, first compare the node you want to insert
with the root of the tree.  If the value in the node is greater than the value at the root, check the right child of the root.  If the root doesn't have a right child,
then that is where you place the node.  If the root does have a right child, compare your node with the value of the right child.  Say it's less than the value of the right child,
then check the left child of that node.  This procedure repeats until the node and it's value reaches the right place.  See blog post for additional details.

Since this is a search tree, it is important that values are not duplicated.  The rules of BSTs ensure that if a node looking to be inserted is a duplicate, it will eventually
compare against that node.  At that point, the `add` method will be forced to return `false`.

###Encapsulation

A lot of the public methods call private methods with the same name but a different function signature.  This is primarily to enforce the boundary between public and private interaction.

###Recursion

We use recursion to traverse the tree.  We call the function repeatedly until the base case (usually that the node we're looking at doesn't have a child) is satisfied, and then we back up.

###Pointer usage
We dereference pointers multiple times in order to access the node itself, when we're making copies.

###Inheritance

The BinarySearchTree inherits from BSTI.h.  Importantly, all the functions are pure virtual, which means they must be implemented in BinarySearchTree.

##Issues

1. For some odd reason, the search function does not return the value properly.  It usually returns a 5 digit number that has no bearing on the nodes in the list.  I've gotten around this by
searching for the value, and then ignoring that value.  This works as a search because if the value isn't in the list, an exception is thrown.  Still, it's awkward, unsafe, and should probably
be corrected. UPDATE: Problem solved.  When recursively calling a method, you need to make sure that the types match.  What happened was I was calling search as a void function, but it returns an integer.
I'm guessing it didn't throw an error because it eventually resolved on an integer, but it's probably why I was getting nonsensical results.

2. 
