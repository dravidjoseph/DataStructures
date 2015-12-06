/*******************************************************
* @file: Node.h
* @author: Dravid Joseph
* @date: 9/21/15
* @brief: Header file for Node class
********************************************************/

#ifndef DOUBLE_NODE_H
#define DOUBLE_NODE_H

template<typename T>
class DoubleNode{
	
	/*******************************************************
	* PUBLIC METHDOS
	********************************************************/
	
public:
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes Node class
	* @return : Initialized Node
	********************************************************/
	DoubleNode();
	
	/*******************************************************
	* @pre :  None
	* @post : gets stored value of node
	* @return : T
	********************************************************/
	T getValue() const;
	
	/*******************************************************
	* @pre :  None
	* @post : changes value of node
	* @return : void
	********************************************************/
	void setValue(T val);
	
	/*******************************************************
	* @pre :  None
	* @post : return pointer to previous node
	* @return : Initialized Node
	********************************************************/
	DoubleNode<T>* getPrevious() const;
	
	/*******************************************************
	* @pre :  None
	* @post : changes pointer to previous node
	* @return : void
	********************************************************/
	void setPrevious(DoubleNode<T>* val);
	
	/*******************************************************
	* @pre :  None
	* @post : return pointer to next node
	* @return : Initialized Node
	********************************************************/
	DoubleNode<T>* getNext() const;
	
	/*******************************************************
	* @pre :  None
	* @post : changes pointer to next node
	* @return : void
	********************************************************/
	void setNext(DoubleNode<T>* val);
	
	
	/*******************************************************
	* PRIVATE MEMBERS
	********************************************************/
	
private:
	
	/*******************************************************
	*Value stored inside Node
	********************************************************/
	T m_value;
	
	/*******************************************************
	*Pointer to previous Node
	********************************************************/
	DoubleNode<T>* m_previous;
	
	/*******************************************************
	*Value stored inside Node
	********************************************************/
	DoubleNode<T>* m_next;
	
};
#include "DoubleNode.hpp"
#endif