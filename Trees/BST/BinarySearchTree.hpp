/*******************************************************
* @file: BinarySearchTree.hpp
* @author: Dravid Joseph
* @date: 11/9/15
* @brief: Implementation for BinarySearchTree class
********************************************************/

/*******************************************************
* PUBLIC METHODS
********************************************************/

template<typename T>
BinarySearchTree<T>::BinarySearchTree():m_root(nullptr){
	
}

template<typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& other){
	
	if(!other.isEmpty()){
		m_root = new SingleNode<T>(*(other.m_root));
	}
	//important check for cloning empty tree
	else{
		m_root = nullptr;
	}
}

template<typename T>
BinarySearchTree<T>::~BinarySearchTree(){
	
	deleteTree(m_root);
	
}

template<typename T>
BSTI<T>* BinarySearchTree<T>::clone(){

	BSTI<T>* clone = new BinarySearchTree<T>(*(this));
	
	return clone;
}

template<typename T>
bool BinarySearchTree<T>::isEmpty() const{
	return m_root == nullptr;
}

template<typename T>
bool BinarySearchTree<T>::add(T value){
	return add(value,m_root);
}


template<typename T>
bool BinarySearchTree<T>::search(T value) const{
	
	if(isEmpty()){
		return false;
	}
	else{
		return search(value,m_root);
	}
}

template<typename T>
std::vector<T> BinarySearchTree<T>::treeToVector(Order order) const{
	//create vector
	std::vector<T> vec;
	//modify vector with values
	treeToVector(order,m_root,vec);
	//return vector
	return vec;
	
}

/*******************************************************
* PRIVATE METHODS
********************************************************/

template<typename T>
bool BinarySearchTree<T>::add(T value, Node<T>* subTree){
	
	
	//if tree is empty
	if(isEmpty()){
		
		//create new node and place value
		SingleNode<T>* newNode = new SingleNode<T>();
		newNode->setValue(value);
		m_root = newNode;
		
		return true;
	}
	
	//if the value is less than the value in the subtree
	
	else if(value < subTree->getValue()){
		
		if(subTree->getLeft() == nullptr){
			
			SingleNode<T>* newNode = new SingleNode<T>();
			newNode->setValue(value);
			subTree->setLeft(newNode);
			
			return true;
		}
		
		return add(value,subTree->getLeft());
	}
	else if(value > subTree->getValue()){
		if(subTree->getRight() == nullptr){
			
			SingleNode<T>* newNode = new SingleNode<T>();
			newNode->setValue(value);
			subTree->setRight(newNode);
			
			return true;
		}
		
		return add(value,subTree->getRight());
	}
	else{
		return false;
	}
	
}

template<typename T>
void BinarySearchTree<T>::deleteTree(Node<T>* subTree){
	if(subTree != nullptr){
		if(subTree->getLeft() != nullptr){
			deleteTree(subTree->getLeft());
		}
		if(subTree->getRight() != nullptr){
			deleteTree(subTree->getRight());
		}
	}
	
	delete subTree;
	subTree = nullptr;
	
}

template<typename T>
bool BinarySearchTree<T>::search(T value, Node<T>* subTree) const{
	//Tree has been checked as not empty.
	if(value < subTree -> getValue()){
		if(subTree -> getLeft() != nullptr){
			return search(value,subTree->getLeft());
		}
		else{
			return false;
		}
	}
	else if(value > subTree -> getValue()){
		if(subTree -> getRight() != nullptr){
			return search(value,subTree->getRight());
		}
		else{
			return false;
		}
	}
	else if(value == subTree->getValue()){
		return true;
	}
	else{
		return false;
	}
	
	
}


template<typename T>
void BinarySearchTree<T>::treeToVector(Order order,Node<T>* subTree, std::vector<T>& vec) const{
	
//pretty much exactly like printTree but stores values in vector	
	switch(order){
		
		case PRE_ORDER:
		
		if(subTree != nullptr){
			vec.push_back(subTree->getValue());
			treeToVector(order,subTree->getLeft(),vec);
			treeToVector(order,subTree->getRight(),vec);
		}
		
		break;
		
		case IN_ORDER:
		
		if(subTree != nullptr){
			
			treeToVector(order,subTree->getLeft(),vec);
			vec.push_back(subTree->getValue());
			treeToVector(order,subTree->getRight(),vec);
			
		}
		
		break;
		
		case POST_ORDER:
		
		if(subTree != nullptr){
			
			treeToVector(order,subTree->getLeft(),vec);
			treeToVector(order,subTree->getRight(),vec);
			vec.push_back(subTree->getValue());	
		}
		
		
		break; 	
	}
	
	
}

