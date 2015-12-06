/*******************************************************
* @file: main.cpp
* @author: Dravid Joseph
* @date: 9/21/15
* @brief: Driver for DoubleLinkedList implementation
********************************************************/

#include <iostream>
#include <vector>

#include "DoubleLinkedList.h"

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
		<< 	"Your choice: ";
}



int main(){
	
	int choice = 0;
	int val = 0;
	int val2 = 0;
	bool flag = false;
	std::vector<int> vec;
	
	DoubleLinkedList<int>* dll = new DoubleLinkedList<int>();
	
	while(!flag){
		
		printMenu();
		
		std::cin>>choice;
	
		switch(choice){
		
			case 1:
		
				std::cout<<"What value would you like to push to the front?";
				std::cin>>val;
				
				dll->pushFront(val);
				
				std::cout<<val<<" successfully added to the front of the list\n";
			
		
			break;
		
			case 2:
			
				std::cout<<"What value would you like to push to the back?";
				std::cin>>val;
			
				dll->pushBack(val);
			
				std::cout<<val<<" successfully added to the back of the list\n";
		
			break;
		
			case 3:
			
				std::cout<<"What value would you like to push?";
				std::cin>>val;
				std::cout<<"What value would you like to push it behind?";
				std::cin>>val2;
				
				try{
					dll->insertBehind(val,val2);
					std::cout<<val<<" successfully added behind"<<val2<< " in the list\n";	
				}
				catch(std::runtime_error& e){
					std::cout<<e.what()<<std::endl;
				}
			
				
		
			break;
		
			case 4:
			
				std::cout<<"What value would you like to push?";
				std::cin>>val;
				std::cout<<"What value would you like to push it ahead of?";
				std::cin>>val2;
				
				try{
					dll->insertBehind(val,val2);
					std::cout<<val<<" successfully added ahead of"<<val2<< " in the list\n";	
				}
				catch(std::runtime_error& e){
					std::cout<<e.what()<<std::endl;
				}
			
				
		
			break;
		
			case 5:
			
				try{
					dll->removeFront();	
					std::cout<<"Front of list removed";
				}
				catch(std::runtime_error& e){
					std::cout<<e.what()<<std::endl;
				}
				
				
		
		
			break;
		
			case 6:
			
				try{
					dll->removeBack();
					std::cout<<"Back of list removed";	
				}
				catch(std::runtime_error& e){
					std::cout<<e.what()<<std::endl;
				}
				
				
		
			break;
		
			case 7:
			
				std::cout<<"What value would you like to remove?";
				std::cin>>val;
				
				try{
					dll->remove(val);
					std::cout<<val<<" successfully removed from the list";	
				}
				catch(std::runtime_error& e){
					std::cout<<e.what()<<std::endl;
				}
				
				
		
			break;
		
			case 8:
			
				std::cout<<"Printing List...\n";
				vec = dll->toVector();
				
				for(std::size_t i = 0; i < vec.size(); i++){
					std::cout<<vec[i]<<" ";
				}
		
			break;
		
			case 9:
				
			std::cout<<"Quitting...\n";
			flag = true;
			
		
			break;
		
			default:
		
				std::cout<<"Invalid choice.\n";
			
			break;
		}
	
	}
	
	
	
	delete dll;
	dll = nullptr;
	
	return 0;
	
}