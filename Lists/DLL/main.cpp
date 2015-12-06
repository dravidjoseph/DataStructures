/*******************************************************
* @file: main.cpp
* @author: Dravid Joseph
* @date: 9/21/15
* @brief: Driver for DoubleLinkedList implementation
********************************************************/

#include <iostream>

#include "DoubleLinkedList.h"
#include "Test.h"

void printMenu()
{
	std::cout << 	"\n\nMake choice\n"
		<<	"1) push value onto front\n"
		<<	"2) push value onto back\n"
		<<	"3) insert behind a value\n"
		<<	"4) insert ahead of a value\n"
		<<	"5) remove front value\n"
		<<	"6) remove back value\n"
		<<	"7) remove specific value\n"
		<<	"8) print list\n"
		<<	"9) Quit\n"
		<<	"10) Run Tests\n"
		<< 	"Your choice: ";
}



int main(){
	
	DoubleLinkedList<int>* dll = new DoubleLinkedList<int>();
	bool flag = false;
	int choice = 0;
	int value = 0;
	int search = 0;
	
	while(!flag){
		
		printMenu();
		std::cin>>choice;
		
		std::cout<<"\nYou chose: "<<choice<<"\n";
		
		if(choice == 1){
			std::cout<<"Give a value: ";
			std::cin>>value;
			
			dll->pushFront(value);
			
			std::cout<<value<<" added to the front of list.";
		}
		else if(choice == 2){
			std::cout<<"Give a value: ";
			std::cin>>value;
			
			dll->pushBack(value);
			
			std::cout<<value<<" added to the back of list.";
		}
		else if(choice == 3){
			std::cout<<"Give a value to insert: ";
			std::cin>>value;
			
			std::cout<<"Pick a value to insert behind: ";
			std::cin>>search;
			
			std::cout<<"Attempting to insert "<<value<<" behind "<<search<<"\n";
			
			try{
				dll->insertBehind(search,value);
			}
			catch(std::runtime_error& e){
				std::cout<<e.what()<<std::endl;
			}
				
		}
		else if(choice == 4){
			std::cout<<"Give a value to insert: ";
			std::cin>>value;
			
			std::cout<<"Pick a value to insert ahead of: ";
			std::cin>>search;
			
			std::cout<<"Attempting to insert "<<value<<" ahead of "<<search<<"\n";
			
			try{
				dll->insertAhead(search,value);
			}
			catch(std::runtime_error& e){
				std::cout<<e.what()<<std::endl;
			}
		}
		else if(choice == 5){
			std::cout<<"Removing front node.";
			if(dll->removeFront()){
				std::cout<<"Front node removed.";
			}
			else{
				std::cout<<"Removal failed.";
			}
			
		}
		else if(choice == 6){
			std::cout<<"Removing back node.";
			if(dll->removeBack()){
				std::cout<<"Back node removed.";
			}
			else{
				std::cout<<"Removal failed.";
			}
		}
		else if(choice == 7){
			std::cout<<"Give a value to remove: ";
			std::cin>>value;
			std::cout<<"You gave "<<value<<"\n";
			
			if(dll->remove(value)){
				std::cout<<value<<" removed from list.";
			}
			else{
				std::cout<<value<<" could not be removed from list.";
			}
		}
		else if(choice == 8){
			dll->printList();
		}
		else if(choice == 9){
			std::cout<<"Program ending...";
			flag = true;
		}
		else if(choice == 10){
			Test myTest(std::cout);
			myTest.runTests();
		}
		
		else{
			std::cout<<"Invalid choice.\n";
		}
	}
	
	delete dll;
	dll = nullptr;
	
	
}