/*******************************************************
* @file : Node.h
* @author : Dravid Joseph
* @date : 9/14/15
* @brief : Header file for Node class
********************************************************/

#ifndef NODE_H
#define NODE_H

template<typename T>
class Node<T>{
	
	/*******************************************************
	* PUBLIC METHDOS
	********************************************************/
public:
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes Node class
	* @return : Initialized Node
	********************************************************/
	Node();
	
	/*******************************************************
	* @pre :  valid integer value
	* @post : None
	* @return : void
	********************************************************/
	void setValue(int val);
	
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
	void setNext(Node<T>* prev);
	
	/*******************************************************
	* @pre :  None
	* @post : Valid Node reference
	* @return : Node*
	********************************************************/
	Node<T>* getNext() const;
	
	
	
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
	Node<T>* m_next;
	
	
};
#include "SingleNode.hpp"
#endif