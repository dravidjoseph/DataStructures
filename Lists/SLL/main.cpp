/*******************************************************
* @file: main.cpp
* @author: Dravid Joseph
* @date: 9/14/15
* @brief: Driver for LinkedList Program
********************************************************/

#include "LinkedList.h"

#include <iostream>
#include <stdexcept>
#include <vector>



/*******************************************************
* @pre :  None
* @post : Prints Menu (does not do anything else)
* @return : void
********************************************************/

void printMenu(){
	std::cout << "\n\nSelect from the following menu:\n"
			<< "1) Add to the front of the list\n"
			<< "2) Add to the end of the list\n"
			<< "3) Remove from front of the list\n"
			<< "4) Remove from back of the list\n"
			<< "5) Print the list\n"
			<< "6) Search for value\n"
			<< "7) Reverse the list\n"
			<< "8) Exit\n"
			<< "Enter your choice: ";
}

int main(){
	
	//local variables needed to run program
	bool flag = false;
	int choice = 0;
	int val = 0;
	std::vector<int> vec;
	
	//Pointer to list
	LinkedList<int>* list = new LinkedList<int>();
	
	
	while(!flag){
		
		printMenu();
		std::cin>>choice;
		
		switch(choice){
		
			case 1:
			
				std::cout<<"What integer would you like to add to the list? ";
				std::cin>>val;
				
				list->addFront(val);
				
				std::cout<<val<<" added to the front of the list\n";
			
			
			break;
		
			case 2:
			
				std::cout<<"What integer would you like to add to the list? ";
				std::cin>>val;
			
				list->addBack(val);
			
				std::cout<<val<<" added to the back of the list\n";
			
			break;
			
			case 3:
			
				try{
					list->removeFront();
				}
				catch(std::runtime_error& e){
					std::cout<<e.what()<<std::endl;
				}
			
			break;
			
			case 4:
			
				try{
					list->removeBack();
				}
				catch(std::runtime_error& e){
					std::cout<<e.what()<<std::endl;
				}
			
			break;
			
			case 5:
			
				vec = list->toVector();
				for(std::size_t i = 0; i < vec.size(); i++){
					std::cout<<vec[i]<<" ";
				}
			
			break;
			
			case 6:
			
				std::cout<<"What integer would you like to search for? ";
				std::cin>>val;
			
				if(list->search(val)){
					std::cout<<val<<" is in the list.";
				}
				else{
					std::cout<<val<<" is not in the list";
				}
				
			break;
			
			case 7:
			
				std::cout<<"Reversing the list.";
				list->reverse();
			
			break;
			
			case 8:
				std::cout<<"Exiting...";
				flag = true;
				
			break;
		
		}
		
		
	}
	

	delete list;
	list = nullptr;
	
	return 0;

}