/*******************************************************
* @file: Node.hpp
* @author: Dravid Joseph
* @date: 9/21/15
* @brief: Implementation file for Node class
********************************************************/


template<typename T>
Node<T>::Node():m_value(T()),m_previous(nullptr),m_next(nullptr){
	
}

template<typename T>
T Node<T>::getValue() const{
	return m_value;
}

template<typename T>
void Node<T>::setValue(T val){
	m_value = val;
}

template<typename T>
Node<T>* Node<T>::getPrevious() const{
	return m_previous;
	
}

template<typename T>
void Node<T>::setPrevious(Node<T>* prev){
	m_previous = prev;
}

template<typename T>
Node<T>* Node<T>::getNext() const{
	return m_next;
}

template<typename T>
void Node<T>::setNext(Node<T>* next){
	m_next = next;
}