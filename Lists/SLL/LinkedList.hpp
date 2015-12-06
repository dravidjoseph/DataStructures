/*******************************************************
* @file: LinkedList.cpp
* @author: Dravid Joseph
* @date: 9/14/15
* @brief: Implementation file for LinkedList class
********************************************************/

template<typename T>
LinkedList<T>::LinkedList():m_front(nullptr),m_size(0){
	
}

template<typename T>
LinkedList<T>::~LinkedList(){
	
	if(!isEmpty()){
		
		removeFront();
		
	}
}

template<typename T>
bool LinkedList<T>::isEmpty() const{
	return m_size == 0;
}

template<typename T>
int LinkedList<T>::size() const{
	return m_size;
}

template<typename T>
bool LinkedList<T>::search(T value){
	
	//If empty list, automatically return false
	if(isEmpty()){
		return false;
	}
	//search list
	else{
		
		//Traverse list
		SingleNode<T>* traverse = m_front;
		
		while(traverse->getNext() != nullptr){
			if(traverse->getValue() == value){
				return true;
			}
			else{
				traverse = traverse->getNext();
			}
		}
		
		//final comparison
		if(traverse->getValue() == value){
			return true;
		}
		else{
			return false;
		}
		
		//end of list
		
		
	}
	
}

template<typename T>
std::vector<T> LinkedList<T>::toVector() const{
	//As long as the list isn't empty
	std::vector<T> vec;
	
	if(!isEmpty()){
	
		SingleNode<T>* traverse = m_front;
		
		while(traverse->getNext() != nullptr){
			vec.push_back(traverse->getValue());
			traverse = traverse->getNext();
		}
		vec.push_back(traverse->getValue());
	}
	return vec;
	
}

template<typename T>
void LinkedList<T>::addBack(T value){
	
	//Just add to m_front if list is empty
	if(isEmpty()){
		m_front = new SingleNode<T>();
		m_front->setValue(value);
	}
	else{
		//create node and stuff value in it.
		SingleNode<T>* newNode = new SingleNode<T>();
		newNode->setValue(value);
		
		//create node pointer to traverse to end of list
		SingleNode<T>* traverse = moveToEnd();

		//traverse is now pointing to last node in list
		//setNext makes the traverse node point at newNode
		traverse->setNext(newNode);
		//Now we're done.
	}
	m_size++;
}

template<typename T>
void LinkedList<T>::addFront(T value){
	
	if(isEmpty()){
		//same as with addBack
		m_front = new SingleNode<T>();
		m_front->setValue(value);
	}
	else{
		
		//create node and stuff value in it.
		SingleNode<T>* newNode = new SingleNode<T>();
		newNode->setValue(value);
		newNode->setNext(m_front);
		//move m_front to point at newNode
		m_front = newNode;
	}
	
	m_size++;
	
}

template<typename T>
void LinkedList<T>::removeBack() throw (std::runtime_error){
	
	//Can't remove from empty list
	if(isEmpty()){
		throw std::runtime_error("Can't remove from empty list");
	}
	else{
		
		SingleNode<T>* traverse = moveToPen();
		SingleNode<T>* t2 = moveToEnd();
		traverse->setNext(nullptr);
		delete t2;
		t2 = nullptr;
		m_size--;
	}
	
	
	
}

template<typename T>
void LinkedList<T>::removeFront() throw (std::runtime_error){
	//Can't remove from empty list
	if(isEmpty()){
		throw std::runtime_error("Can't remove from empty list");
	}
	//Works for any nonzero list
	else{
		
		//create traverse node
		SingleNode<T>* traverse = m_front;
		//move m_front to next node
		m_front = m_front->getNext();
		//delete node that was previously at front
		delete traverse;
		traverse = nullptr;
		
		m_size--;
	}
}

template<typename T>
SingleNode<T>* LinkedList<T>::moveToPen(){
	
	if(isEmpty() || size() == 1){
		return nullptr;
	}
	else{
		//size 2 or more
		SingleNode<T>* t1 = m_front;
		SingleNode<T>* t2 = m_front->getNext();
		
		while(t2->getNext() != nullptr){
			t1 = t1->getNext();
			t2 = t2->getNext();
		}
		return t1;
	}

}

template<typename T>
SingleNode<T>* LinkedList<T>::moveToEnd(){
	
	if(isEmpty()){
		return nullptr;
	}
	else{
		//size 1 or more
		SingleNode<T>* t1 = m_front;
		
		while(t1->getNext() != nullptr){
			t1 = t1->getNext();
		}
		return t1;
	}

}

template<typename T>
void LinkedList<T>::reverse(){
	
	if(isEmpty() || size() == 1){
	
	}
	else{
		
		SingleNode<T>* cursor = moveToPen();
		SingleNode<T>* newFront = moveToEnd();
		
		newFront->setNext(cursor);
		cursor->setNext(nullptr);
		
		cursor = m_front;
		SingleNode<T>* c2 = m_front->getNext();
		
		for(int i = 0; i < m_size - 2; i++){
			while(c2->getNext() != nullptr){
				cursor = cursor->getNext();
				c2 = c2->getNext();
			}
			cursor->setNext(nullptr);
			c2->setNext(cursor);
			
			cursor = m_front;
			c2 = m_front->getNext();
		}
		
		m_front = newFront;
		
	}
	
}