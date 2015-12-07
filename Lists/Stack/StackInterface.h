/*******************************************************
* @file : StackInterface.h
* @author : Dravid Joseph
* @date : 9/28/15
* @brief : Stack Interface
********************************************************/

#ifndef STACK_INTERFACE_H
#define STACK_INTERFACE_H

template<typename T>

class StackInterface{
	
	/*******************************************************
	* PUBLIC METHODS
	********************************************************/
public: 
	/*******************************************************
	* @pre :  None
	* @post : Deallocates stack
	* @return : None
	********************************************************/

	virtual ~StackInterface() {};
	
	/*******************************************************
	* @pre :  None
	* @post : returns true if stack is empty, fasle otherwise
	* @return : bool
	********************************************************/
	
	virtual bool isEmpty() const = 0;
	
	/*******************************************************
	* @pre :  valid newEntry
	* @post : pushes new entry onto stack
	* @return : void
	********************************************************/
	
	virtual void push(const T newEntry) = 0;
	
	/*******************************************************
	* @pre :  None
	* @post : removes value at top of stack, returning value
	* @return : T
	* @throw : PreconditionViolationException
	********************************************************/
	
	virtual void pop() throw(PreconditionViolationException) = 0;
	
	/*******************************************************
	* @pre :  None
	* @post : returns value at top of stack
	* @return : T
	********************************************************/
	
	virtual T peek() const throw(PreconditionViolationException) = 0;
	
	/*******************************************************
	* @pre :  None
	* @post : size of stack
	* @return : int
	********************************************************/
	
	virtual int size() const = 0;
	
	/*******************************************************
	* @pre :  None
	* @post : prints all node values in stack
	* @return : void
	********************************************************/
	
	virtual std::vector<T> toVector() const = 0;
};
#endif