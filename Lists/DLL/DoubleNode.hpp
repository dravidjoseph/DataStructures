/*******************************************************
* @file: Node.hpp
* @author: Dravid Joseph
* @date: 9/21/15
* @brief: Implementation file for Node class
********************************************************/


template<typename T>
DoubleNode<T>::DoubleNode():m_value(T()),m_previous(nullptr),m_next(nullptr){
	
}

template<typename T>
T DoubleNode<T>::getValue() const{
	return m_value;
}

template<typename T>
void DoubleNode<T>::setValue(T val){
	m_value = val;
}

template<typename T>
DoubleNode<T>* DoubleNode<T>::getPrevious() const{
	return m_previous;
	
}

template<typename T>
void DoubleNode<T>::setPrevious(DoubleNode<T>* prev){
	m_previous = prev;
}

template<typename T>
DoubleNode<T>* DoubleNode<T>::getNext() const{
	return m_next;
}

template<typename T>
void DoubleNode<T>::setNext(DoubleNode<T>* next){
	m_next = next;
}