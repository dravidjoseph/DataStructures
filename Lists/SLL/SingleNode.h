/*******************************************************
* @file : Node.h
* @author : Dravid Joseph
* @date : 9/14/15
* @brief : Header file for Node class
********************************************************/

#ifndef SINGLENODE_H
#define SINGLENODE_H

template<typename T>
class SingleNode{
	
	/*******************************************************
	* PUBLIC METHDOS
	********************************************************/
public:
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes Node class
	* @return : Initialized Node
	********************************************************/
	SingleNode();
	
	/*******************************************************
	* @pre :  valid integer value
	* @post : None
	* @return : void
	********************************************************/
	void setValue(T val);
	
	/*******************************************************
	* @pre :  None
	* @post : valid integer
	* @return : integer value
	********************************************************/
	T getValue() const;
	
	/*******************************************************
	* @pre :  Valid Node reference
	* @post : sets Node pointer to valid node reference
	* @return : void
	********************************************************/
	void setNext(SingleNode<T>* prev);
	
	/*******************************************************
	* @pre :  None
	* @post : Valid Node reference
	* @return : Node*
	********************************************************/
	SingleNode<T>* getNext() const;
	
	
	
	/*******************************************************
	* PRIVATE MEMBERS
	********************************************************/
private: 
	
	/*******************************************************
	*Value stored inside Node
	********************************************************/
	T m_value;
	
	
	/*******************************************************
	* Pointer to next node
	********************************************************/
	SingleNode<T>* m_next;
	
	
};
#include "SingleNode.hpp"
#endif