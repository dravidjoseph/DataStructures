# Stack Lab

##Purpose
This lab is designed to familiarize the concept of a stack as well as inheritance, along with some more exception handling.

##Concepts
1. Interfaces:  While C++ doesn't have *interfaces* per se, it does allow for abstract classes (classes where some methods are virtual).  A class that consists of all pure virtual methods, except for the destructor, is therefore a *de facto* interface.  

2. Operator overloading: C++ allows operators (like <,>,+,etc.) to mean different things depending on the context.  This will be useful during this lab.

3. Inheritance: The idea that some classes can operate as specialized versions of other classes.

##Issues

1. Makefiles won't work unless you have all the dependencies correct.  You have to make sure all your `#include` statements are in the right places.

2. Not so much an issue, but as a note: `Stack.h` only has to include methods that end with the `= 0`; anything else is a suggestion.

3. Since the operator methods deal with pointers that have been dereferenced, you need to use the . instead of the `->`.