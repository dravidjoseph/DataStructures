/*******************************************************
* @file: Node.hpp
* @author: Dravid Joseph
* @date: 9/14/15
* @brief: Implementation file for Node class
********************************************************/

template<typename T>
SingleNode<T>::SingleNode():m_value(T()),m_next(nullptr){

}

template<typename T>
void SingleNode<T>::setValue(T val){
	m_value = val;
}

template<typename T>
T SingleNode<T>::getValue() const{
	return m_value;
}

template<typename T>
void SingleNode<T>::setNext(SingleNode<T>* prev){
	m_next = prev;
}

template<typename T>
SingleNode<T>* SingleNode<T>::getNext() const{
	return m_next;
}

