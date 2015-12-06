/*******************************************************
* @file: Node.h
* @author: Dravid Joseph
* @date: 9/21/15
* @brief: Header file for Node class
********************************************************/

#ifndef NODE_H
#define NODE_H

template<typename T>
class Node{
	
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
	Node<T>* getPrevious() const;
	
	/*******************************************************
	* @pre :  None
	* @post : changes pointer to previous node
	* @return : void
	********************************************************/
	void setPrevious(Node<T>* val);
	
	/*******************************************************
	* @pre :  None
	* @post : return pointer to next node
	* @return : Initialized Node
	********************************************************/
	Node<T>* getNext() const;
	
	/*******************************************************
	* @pre :  None
	* @post : changes pointer to next node
	* @return : void
	********************************************************/
	void setNext(Node<T>* val);
	
	
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
	Node<T>* m_previous;
	
	/*******************************************************
	*Value stored inside Node
	********************************************************/
	Node<T>* m_next;
	
};
#include "Node.hpp"
#endif