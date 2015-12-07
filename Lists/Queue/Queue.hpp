/*******************************************************
* @file : Queue.hpp
* @author : Dravid Joseph
* @date : 9/28/15
* @brief : Implementation file for Stack class.
********************************************************/	
	
	
	
template<typename T>	
Queue<T>::Queue():m_front(nullptr),m_size(0){
	
}

template<typename T>	
Queue<T>::~Queue(){
	while(!isEmpty()){
		dequeue();
	}
}

template<typename T>	
bool Queue<T>::isEmpty() const{
	return m_size == 0;
}

template<typename T>	
void Queue<T>::enqueue(const T newEntry){
	
	if(isEmpty()){
		m_front = new SingleNode<T>();
		m_front->setValue(newEntry);
	}
	else{
		SingleNode<T>* newNode = new SingleNode<T>();
		newNode->setValue(newEntry);
		newNode->setNext(m_front);
		m_front = newNode;
	}
	
	m_size++;
}

template<typename T>	
void Queue<T>::dequeue() throw(PreconditionViolationException){
	
	if(isEmpty()){
		throw PreconditionViolationException("Can't dequeue from an empty list");
	}
	else if(size() == 1){
		delete m_front;
		m_front = nullptr;
	}
	else{
		SingleNode<T>* t1 = m_front;
		m_front = m_front->getNext();
		delete t1;
		t1 = nullptr;
	}
	m_size--;
	
	
}

template<typename T>
T Queue<T>::front() const throw(PreconditionViolationException){
	return m_front->getValue();
}

template<typename T>	
int Queue<T>::size() const{
	return m_size;
}

template<typename T>	
std::vector<T> Queue<T>::toVector() const{
	std::vector<T> vec;
	
	if(!isEmpty()){
		SingleNode<T>* t1 = m_front;
		
		while(t1->getNext() != nullptr){
			vec.push_back(t1->getValue());
			t1 = t1->getNext();
		}
		vec.push_back(t1->getValue());
	}
	return vec;
	
}