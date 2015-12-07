/*******************************************************
* @file : main.cpp
* @author : Dravid Joseph
* @date : 9/28/15
* @brief : Driver class for stack project
********************************************************/

#include "Stack.h"


/*******************************************************
* @pre :  None
* @post : Prints a menu of options
* @return : void
********************************************************/

void printMenu(){
	
	std::cout << 	"\n\nSelect an action: \n"
			<<	"1) Add something to stack\n"
			<<	"2) See what is at the top of stack\n"
			<<	"3) Print contents in stack\n"
			<<	"4) Pop stack\n"
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
	StackInterface<int>* lane1 = new Stack<int>();
	
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
			
				std::cout<<"Add integer to stack: \n";
				std::cin>>entry;
				lane1->push(entry);
				std::cout<<entry<<" successfully added to stack.";
				
			
			break;
			
			case 2:
			
				std::cout<<"What is going on top of the stack?\n";
		
				try{
					entry = lane1->peek();
				}
				catch(PreconditionViolationException& e){
					std::cout<<e.what()<<std::endl;
				}
				std::cout<<entry<<" is at the top of the stack.\n";
			
			break;
			
			case 3:
			
				vec = lane1->toVector();
				std::cout<<"Printing list...\n";
				for(std::size_t i = 0; i < vec.size(); i++){
					std::cout<<vec[i]<<" ";
				}
			
			break;
			
			case 4:
			
				try{
					lane1->pop();
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