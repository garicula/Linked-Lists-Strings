// Garrick Morley
// CPSC 300 Project 2
// This program is a modification of string-queue.cpp that inputs and outputs strings in alphabetical order


// Implement a string queue using a linked list

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <cmath>
#include <fstream>
#include <cassert>
#include <algorithm>
using namespace std;

struct node
    {
    string str;
    node *next;
    };
    
// Global variables -- Yuck!!!!
// We'll get rid of these later when we look at an object-oriented
// version of this program.

node *head, *tail;
int counter;

// Add a string to the queue.

//I modified this to input in alphabetical order

void queue_add(string s)    
	{    
		//set the important features of the string queue
		node *fill = head;
   		node *ptr = new node;
   		node *prev = NULL;
   		ptr->next = NULL;
		ptr->str = s;
   		

		//modifications to input method
   		if (head == NULL)
        	head = ptr;
		else if (head !=NULL)
		{
			for(fill=head;fill != NULL;fill = fill->next)
			{
					
				if(fill->str >= ptr->str)
				{
					break;
				}		
				prev=fill;
				tail = fill;				
			}
				
		if (fill==head)
		{		
			ptr->next = head;
			head=ptr;
		}		
		else if (fill!=head)
		{
			ptr->next=fill;
			prev->next=ptr;
		}	
		counter++;
		}
	}
	
// Remove a string from the queue.
string queue_remove()	
	{   
		if (head == NULL)  // Is the queue empty? 
		return "";
	
		else        
			{        
				string s = head->str;        
				node *ptr = head;        
				head = head->next;        
				delete ptr;        
				--counter;        
				return s;        
			}   
	}
	
void string_printer()
{
	const node *print;
	for (print = head; print != NULL; print = print->next)
	{
		cout << print->str << endl;
	}	
}
	
	
// Return the current size of the queue.
int queue_size()    
	{
		return counter + 1;
    }
    
void display_menu()    
	{   
		cout << endl;    
			cout << "1. Add a string to the queue "  << endl;  
			cout << "2. Remove a string from the queue " << endl;    
			cout << "3. Check the queue size " << endl;
			//I added option 4 to allow the printing of the strings
			cout << "4. Print the strings in alphabetical order " << endl; 
			cout << "5. Quit " << endl;    
		cout << endl;
	}
	
int main(int argc, char *argv[])    
	{    
		int choice;   
		 
		//initialize variables    
		head = NULL;    
		counter = 0;
		
		//do while loop to allow infinite uses of the program
		do
	   	{	    
			display_menu();
			cout << "Your choice: ";      
			cin >> choice;        
			if (choice == 1)            
			{            
				string s;            
				cout << "string: ";                        
				cin.ignore();            
				getline (cin, s);            
				queue_add (s);            
				cout << "'" << s << "' has been added to the queue \n";
		   	}
			else if (choice == 2)            
			{           
				if (counter > 0)                
				{                
					string s = queue_remove();                
					cout << "'" << s << "' has been removed from the queue \n";                
				}            
				else                
					cout << "The queue is empty \n"; 
		   	}     
			else if (choice == 3)
			{            
				cout << "Queue size: " << queue_size() << "\n";
    		} 	  
			//I added this option to print the strings     
			else if (choice == 4)            
			{            
				string_printer();           
			} 	
			else if(choice != 5)	
			{
				cout << "Nope.  Try again. \n";	
			} 
		}    
		while (choice != 5);
		
		return 0;
	}
