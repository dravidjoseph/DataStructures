/*******************************************************
* @file : Stack.h
* @author : Dravid Joseph
* @date : 9/28/15
* @brief : Header file for Stack class.
********************************************************/

#ifndef STACK_H
#define STACK_H


#include <iostream>
#include <vector>

#include "PreconditionViolationException.h"
#include "SingleNode.h"
#include "StackInterface.h"

template<typename T>
class Stack : public StackInterface<T>{
	
	/*******************************************************
	* PUBLIC METHODS
	********************************************************/
public: 
	/*******************************************************
	* @pre :  None
	* @post : Initializes Stack
	* @return : None
	********************************************************/
	Stack();
	
	/*******************************************************
	* @pre :  None
	* @post : Deallocates stack
	* @return : None
	********************************************************/
	
	~Stack();
	
	/*******************************************************
	* @pre :  None
	* @post : returns true if stack is empty, fasle otherwise
	* @return : bool
	********************************************************/
	
	bool isEmpty() const;
	
	/*******************************************************
	* @pre :  valid newEntry
	* @post : pushes new entry onto stack
	* @return : void
	********************************************************/
	
	void push(const T newEntry);
	
	/*******************************************************
	* @pre :  None
	* @post : removes value at top of stack, returning value
	* @return : T
	* @throw : PreconditionViolationException
	********************************************************/
	
	void pop() throw(PreconditionViolationException);
	
	/*******************************************************
	* @pre :  None
	* @post : returns value at top of stack
	* @return : T
	********************************************************/
	
	T front() const throw(PreconditionViolationException);
	
	/*******************************************************
	* @pre :  None
	* @post : size of stack
	* @return : int
	********************************************************/
	
	int size() const;
	
	/*******************************************************
	* @pre :  None
	* @post : prints all node values in stack
	* @return : void
	********************************************************/
	
	std::vector<T> toVector() const;
	
	/*******************************************************
	* PRIVATE MEMBERS
	********************************************************/
	
private:
	
	/*******************************************************
	*Pointer for Stack
	********************************************************/
	SingleNode<T>* m_top;
	
	/*******************************************************
	*Size of Stack
	********************************************************/
	int m_size;
	
	
};
#include "Stack.hpp"
#endif