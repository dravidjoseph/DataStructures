/*******************************************************
* @file: DoubleLinkedList.hpp
* @author: Dravid Joseph
* @date: 9/21/15
* @brief: Implementation for DoubleLinkedList class
********************************************************/

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList():m_front(nullptr),m_back(nullptr),m_size(0){
	
}

template<typename T>
DoubleLinkedList<T>::~DoubleLinkedList(){
	
	while(!isEmpty()){
	
		removeFront();
	
	}
}

template<typename T>
bool DoubleLinkedList<T>::isEmpty() const{
	return m_size == 0;
}

template<typename T>
int DoubleLinkedList<T>::size() const{
	return m_size;
}

template<typename T>
void DoubleLinkedList<T>::pushFront(T value){
		
	//Create new node
	DoubleNode<T>* newNode = new DoubleNode<T>();
	
	//store value in node
	newNode->setValue(value);
	
	//if empty list, link to list pointers
	if(isEmpty()){
		
		//link list pointers to newDoubleNode
		m_front = newNode;
		m_back = newNode;
		
	}
	
	else{
		//temp node pointer to hold place
		DoubleNode<T>* temp = m_front;
		
		//connect list pointer to new node.  DO NOT DO THE REVERSE
		m_front = newNode;
		
		//connect new node to rest of list
		newNode->setNext(temp);
		temp->setPrevious(newNode);
	}
	
	m_size++;
	
}

template<typename T>
void DoubleLinkedList<T>::pushBack(T value){
	
	DoubleNode<T>* newNode = new DoubleNode<T>();
	
	newNode->setValue(value);
	
	//If the list is empty, link to list pointers
	if(isEmpty()){
		m_front = newNode;
		m_back = newNode;
	}
	//otherwise connect new node to back of list
	else{
		//temp node pointer to hold place
		DoubleNode<T>* temp = m_back;
		
		//connect list pointer to new node 
		m_back = newNode;
		
		//Connect new node to list
		newNode->setPrevious(temp);
		temp->setNext(newNode);
	}
	
	m_size++;
}

template<typename T>
void DoubleLinkedList<T>::removeFront() throw (std::runtime_error){
	
	if(isEmpty()){
		throw std::runtime_error("Empty list");
	}
	else{
		
		DoubleNode<T>* traverse = m_front;
		
		if(size() == 1){
			m_front = nullptr;
			m_back = nullptr;
		}
		else{
			m_front = m_front->getNext();
			m_front->setPrevious(nullptr);
		}
		delete traverse;
		traverse = nullptr;
		
		m_size--;
	}
	
}

template<typename T>
void DoubleLinkedList<T>::removeBack() throw (std::runtime_error){
	if(isEmpty()){
		throw std::runtime_error("Empty list");
	}
	else{
		
		DoubleNode<T>* traverse = m_back;
		
		if(size() == 1){
			m_front = nullptr;
			m_back = nullptr;
		}
		else{
			m_back = m_back->getPrevious();
			m_back->setNext(nullptr);
		}
		delete traverse;
		traverse = nullptr;
		
		m_size--;
	}
}

template<typename T>
void DoubleLinkedList<T>::remove(T value) throw (std::runtime_error){
	
	//If list is empty or the value isn't in the list, let user handle
	if(isEmpty() || (find(value) == nullptr)){
		throw std::runtime_error("Unable to remove value");
	}
		
	//removal	
	else{
		//hand off pointer to specified value
		DoubleNode<T>* traverse = find(value);
			
			
		//if there is one node
		if(size() == 1){
			m_front = nullptr;
			m_back = nullptr;
			//traverse is pointing at deleted node-deletion happens at end of branching statement
		}
		else{
			//if value is at the beginning of the list
			if(traverse == m_front){
				//advance list pointer.traverse holds the node
				m_front = m_front->getNext();
					
				//set the m_front pointer to nullptr
				m_front->setPrevious(nullptr);
			}
			//if value is at the end of the list
			else if(traverse == m_back){
				//reverse list pointer.traverse holds the node
				m_back = m_back->getPrevious();
					
				//set the m_back pointer of the node to nullptr
				m_back->setNext(nullptr);
			}
				
			//if value is anywhere else in the list
			else{
				//Create pointers to the adjacent nodes of the target
				DoubleNode<T>* prev = traverse->getPrevious();
				DoubleNode<T>* next = traverse->getNext();
					
				//Link the adjacent nodes so the target node can be removed
				prev->setNext(next);
				next->setPrevious(prev);
			}
		}
			
		//can include outside the conditionals since this is common
		delete traverse;
		traverse = nullptr;
			
			
		m_size--;	//decrement	
	}
}

template<typename T>
void DoubleLinkedList<T>::insertAhead(T listValue,T newValue) throw (std::runtime_error){
	
	DoubleNode<T>* traverse = find(listValue);
	
	//Can't insert if the pointer isn't pointing
	if(traverse == nullptr){
		throw std::runtime_error("Value not found.\n");		//executed in catch block of main
	}
	else{
		
		//Create new DoubleNode and store value
		DoubleNode<T>* newNode = new DoubleNode<T>();
		newNode->setValue(newValue);
		
		//if node is at the front of the list
		if(traverse == m_front){
			m_front = newNode;		//m_front points to newDoubleNode, the new front of the list
			newNode->setNext(traverse);		//newDoubleNode's next pointer points to traverse, previous pointer at nullptr
			traverse->setPrevious(newNode);		//Previous pointer now points at newnode, next pointer is fine
		}
		else{
			
			//pointer to node previous to the list
			DoubleNode<T>* prev = traverse->getPrevious();	//node prior to node traverse is pointing at
			
			//link newDoubleNode's pointers to the list
			newNode->setPrevious(prev);		
			newNode->setNext(traverse);
			
			prev->setNext(newNode);		//link prev DoubleNode to newDoubleNode
			traverse->setPrevious(newNode);		//link traverse node to newDoubleNode
			
		}
		
		
		m_size++;
		
		
	}
}

template<typename T>
void DoubleLinkedList<T>::insertBehind(T listValue,T newValue) throw (std::runtime_error){
	
	DoubleNode<T>* traverse = find(listValue);
	
		//Can't insert if the pointer isn't pointing
		if(traverse == nullptr){
			throw std::runtime_error("Value not found.");	//executed in catch block of main
		}
		else{
		
			//Create new DoubleNode and store value
			DoubleNode<T>* newNode = new DoubleNode<T>();
			newNode->setValue(newValue);
		
			//if node is at the front of the list
			if(traverse == m_back){
				m_back = newNode;
				newNode->setPrevious(traverse);
				traverse->setNext(newNode);
			}
			else{
				DoubleNode<T>* next = traverse->getNext();
				newNode->setNext(next);
				newNode->setPrevious(traverse);
			
				next->setPrevious(newNode);
				traverse->setNext(newNode);
			
			}
		
			m_size++;
		}
	
}

template<typename T>
DoubleNode<T>* DoubleLinkedList<T>::find(T value) const{
	
	//nothing to find
	if(isEmpty()){
		return nullptr;
	}
	//traverse through list
	else{
		DoubleNode<T>* traverse = m_front;
		
		//while search pointer isn't pointing at the end of the list
		while(traverse->getNext() != nullptr){
			//if you find pointer, return it.
			if(traverse->getValue() == value){
				return traverse;
			}
			//otherwise, advance to next node
			else{
				traverse = traverse->getNext();
			}
		}
		//end of list comparison
		if(traverse->getValue() == value){
			return traverse;
		}
		//only executed if traversal doesn't find node.
		return nullptr;
	}
	
}

template<typename T>
std::vector<T> DoubleLinkedList<T>::toVector() const{
	
	std::vector<T> vec;
	if(!isEmpty()){
		DoubleNode<T>* t1 = m_front;
	
		while(t1->getNext() != nullptr){
			vec.push_back(t1->getValue());
			t1 = t1->getNext();
		}
		vec.push_back(t1->getValue());
	
	}
	
	return vec;
	
}