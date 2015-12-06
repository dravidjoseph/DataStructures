/*******************************************************
* @file: LinkedList.h
* @author: Dravid Joseph
* @date: 9/14/15
* @brief: Header file for LinkedList class
********************************************************/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

//Standard libraries
#include <stdexcept>
#include <vector>

//User-defined libraries
#include "SingleNode.h"

template<typename T>
class LinkedList{
	
public:	
	/*******************************************************
	* PUBLIC METHDOS
	********************************************************/
	
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes LinkedList class
	* @return : Initialized LinkedList
	********************************************************/
	LinkedList();
	
	/*******************************************************
	* @pre :  None
	* @post : Deletes all Nodes in list
	* @return : None
	********************************************************/
	virtual ~LinkedList();
	
	/*******************************************************
	* @pre :  None
	* @post : state of list size
	* @return : bool
	********************************************************/
	bool isEmpty() const;
	
	/*******************************************************
	* @pre :  valid size
	* @post : returns size of list
	* @return : int
	********************************************************/
	int size() const;
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes Node class
	* @return : bool
	********************************************************/
	bool search(T value);
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes Node class
	* @return : void
	********************************************************/
	std::vector<T> toVector() const;
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes Node class
	* @return : void
	********************************************************/
	void addBack(T value);
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes Node class
	* @return : void
	********************************************************/
	void addFront(T value);
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes Node class
	* @return : bool
	********************************************************/
	void removeBack() throw (std::runtime_error);
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes Node class
	* @return : bool
	********************************************************/
	void removeFront() throw (std::runtime_error);
	
	
	/*******************************************************
	* @pre :  None
	* @post : Reverses the list
	* @return : void
	********************************************************/
	
	void reverse();
	
	
	
	/*******************************************************
	* PRIVATE MEMBERS
	********************************************************/
	
private:
	
	
	/*******************************************************
	* @pre :  Valid boolean
	* @post : Returns either pointer last node or penultimate node
	* Private method to preserve linkedlist
	* @return : Node pointer
	********************************************************/
	
	SingleNode<T>* moveToPen();
	
	SingleNode<T>* moveToEnd();
	
	/*******************************************************
	*Points to the front of the list linked
	********************************************************/
	SingleNode<T>* m_front;
	
	/*******************************************************
	*Size of the list.
	********************************************************/
	int m_size;	
	
};
#include "LinkedList.hpp"
#endif