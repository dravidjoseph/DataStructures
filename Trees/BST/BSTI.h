/*******************************************************
* @file: BSTI.h
* @author: Dravid Joseph
* @date: 11/9/15
* @brief: Header file for BST Interface
********************************************************/

#ifndef BSTI_H
#define BSTI_H

#include <vector>

enum Order {PRE_ORDER,IN_ORDER,POST_ORDER};



template<typename T>
class BSTI{
	
	
	/*******************************************************
	* PUBLIC METHODS
	********************************************************/
	
public:
	
	
	/*******************************************************
	* @pre :  A BSTI exists
	* @post : Deletes entire tree
	* @return : None
	********************************************************/
	
	virtual ~BSTI(){};
	
	/*******************************************************
	* @pre :  Valid state
	* @post : creates a deep copy of this
	* @return : BSTI<T>*
	********************************************************/
	
	virtual BSTI<T>* clone() = 0;
	
	/*******************************************************
	* @pre :  None
	* @post : None
	* @return : true if no nodes, false otherwise
	********************************************************/
	
	virtual bool isEmpty() const = 0;
	
	/*******************************************************
	* @pre :  value is valid T
	* @post : a new Node<T> is created and inserted into the tree
	* @return : false if value couldn't be added
	********************************************************/
	
	virtual bool add(T value) = 0;
	
	/*******************************************************
	* @pre :  Type T comparable by ==
	* @post : returns if value in tree, otherwise exception is thrown
	* @return : T
	********************************************************/
	
	virtual bool search(T value) const = 0;
	
	/*******************************************************
	* @pre :  None
	* @post : prints tree in specified order
	* @return : void
	********************************************************/
	virtual void printTree(Order order) const = 0;
	
	
	/*******************************************************
	* @pre : None
	* @post : prints tree in order
	* @return : T
	********************************************************/
	virtual void sortedPrint() const = 0;
	
	
	/*******************************************************
	* @pre :  valid order
	* @post : returns vector in specified traversal
	* @return : vector
	********************************************************/
	virtual std::vector<T> treeToVector(Order order) const = 0;
	
};
#endif

