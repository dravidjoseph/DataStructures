/*******************************************************
* @file : main.cpp
* @author : Dravid Joseph
* @date : 9/28/15
* @brief : Driver class for stack project
********************************************************/

#include "Queue.h"
#include <vector>
#include <stdexcept>
#include <iostream>


/*******************************************************
* @pre :  None
* @post : Prints a menu of options
* @return : void
********************************************************/

void printMenu(){
	
	std::cout << 	"\n\nSelect an action: \n"
			<<	"1) Add something to queue\n"
			<<	"2) See what is at the front of the queue\n"
			<<	"3) Print contents in queue\n"
			<<	"4) Dequeue\n"
			<<	"5) Quit\n"
			<< 	"Enter choice: ";
}

/*******************************************************
* @pre :  None
* @post : Driver method for program
* @return : int
********************************************************/

int main(){
	
	//Remember, parent pointers can take child objects.
	Queue<int>* lane1 = new Queue<int>();
	
	//Helper variables for main
	int choice = 0;
	int entry = 0;
	bool flag = false;
	std::vector<int> vec;
	
	while(!flag){
		
		printMenu();
		
		std::cin>>choice;
		std::cout<<"You chose: "<<choice<<"\n";
		
		
		
		switch(choice){
			
			case 1:
			
				std::cout<<"Add integer to queue: \n";
				std::cin>>entry;
				lane1->enqueue(entry);
				std::cout<<entry<<" successfully added to queue.";
				
			
			break;
			
			case 2:
			
				std::cout<<"What is going on at the front of the queue?\n";
		
				try{
					entry = lane1->front();
				}
				catch(PreconditionViolationException& e){
					std::cout<<e.what()<<std::endl;
				}
				std::cout<<entry<<" is at the front of the queue.\n";
			
			break;
			
			case 3:
			
				vec = lane1->toVector();
				std::cout<<"Printing contents of queue...\n";
				for(std::size_t i = 0; i < vec.size(); i++){
					std::cout<<vec[i]<<" ";
				}
			
			break;
			
			case 4:
			
				try{
					lane1->dequeue();
				}
				catch(PreconditionViolationException& e){
					std::cout<<e.what()<<std::endl;
				}
			
			
			break;
			
			case 5:
			
				std::cout<<"Quitting...\n";
				flag = true;
			
			
			break;
			
			default:
				std::cout<<"Invalid choice.\n";
			
			break;
		}
	}
	
	delete lane1;
	lane1 = nullptr;
	
	return 0;
	
}