/*******************************************************
* @file: DoubleLinkedList.h
* @author: Dravid Joseph
* @date: 9/21/15
* @brief: Header file for DoubleLinkedList class
********************************************************/

#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H


#include <stdexcept>
#include <iostream>

//User-defined libraries
#include "Node.h"


template<typename T>
class DoubleLinkedList{
	
	/*******************************************************
	* PUBLIC METHDOS
	********************************************************/
	
public:
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes DoubleLinkedList class
	* @return : None
	********************************************************/
	DoubleLinkedList();
	
	/*******************************************************
	* @pre :  None
	* @post : Deallocates nodes in the list
	* @return : None
	********************************************************/
	~DoubleLinkedList();
	
	/*******************************************************
	* @pre :  None
	* @post : Checks if list is empty
	* @return : bool
	********************************************************/
	bool isEmpty() const;
	
	/*******************************************************
	* @pre :  None
	* @post : size of list
	* @return : int
	********************************************************/
	int size() const;
	
	/*******************************************************
	* @pre :  None
	* @post : pushes node to front of the list
	* @return : Initialized Node
	********************************************************/
	void pushFront(T value);
	
	/*******************************************************
	* @pre :  None
	* @post : pushes node on back of list
	* @return : Initialized Node
	********************************************************/
	void pushBack(T value);
	
	/*******************************************************
	* @pre :  None
	* @post : deletes first node containing passed value
	* @return : Initialized Node
	********************************************************/
	bool removeFront();
	
	/*******************************************************
	* @pre :  None
	* @post : deletes first node containing passed value
	* @return : Initialized Node
	********************************************************/
	bool removeBack();
	
	/*******************************************************
	* @pre :  None
	* @post : deletes first node containing passed value
	* @return : Initialized Node
	********************************************************/
	bool remove(T value);
	
	/*******************************************************
	* @pre :  None
	* @post : insert ahead of first instance of certain value
	* @return : void
	* @throw : std::runtime_error
	********************************************************/
	void insertAhead(T listValue,T newValue) throw (std::runtime_error);
	
	/*******************************************************
	* @pre :  None
	* @post : insert behind first instance of certain value
	* @return : Initialized Node
	* @throw : std::runtime_error
	********************************************************/
	void insertBehind(T listValue,T newValue) throw (std::runtime_error);
	
	/*******************************************************
	* @pre :  None
	* @post : returns pointer to first node that contains value
	* @return : Node<T>*
	********************************************************/
	Node<T>* find(T value) const;
	
	/*******************************************************
	* @pre :  None
	* @post : Assumes T is overloaded to be printable
	* @return : void
	********************************************************/
	void printList() const;
	
	
	
	/*******************************************************
	* PRIVATE MEMBERS
	********************************************************/
	
private:
	
	/*******************************************************
	*Pointer to front of list
	********************************************************/
	Node<T>* m_front;
	
	/*******************************************************
	*Pointer to back of list
	********************************************************/
	Node<T>* m_back;
	
	/*******************************************************
	*Size of list
	********************************************************/
	int m_size;
	
	
};
#include "DoubleLinkedList.hpp"
#endif