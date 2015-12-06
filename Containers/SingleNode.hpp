/*******************************************************
* @file: Node.cpp
* @author: Dravid Joseph
* @date: 9/14/15
* @brief: Implementation file for Node class
********************************************************/

template<typename T>
Node<T>::Node():m_value(T()),m_next(nullptr){

}

template<typename T>
void Node<T>::setValue(T val){
	m_value = val;
}

template<typename T>
int Node<T>::getValue() const{
	return m_value;
}

template<typename T>
void Node<T>::setNext(Node<T>* prev){
>	m_next = prev;
}

template<typename T>
Node<T>* Node<T>::getNext() const{
	return m_next;
}

