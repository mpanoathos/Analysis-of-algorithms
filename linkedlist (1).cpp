#include <iostream>
#include <cstdlib>
using namespace std;
struct node {
	int a;
	node *next;
} Node;
class linkedList {
	public:
		node *head;// head pointer
		node *tail;// tail pointer
		
		//default constructor
		linkedList(){
			head = NULL;
			tail = NULL;
		}
		//parametrised constructor
		linkedList(const linkedList& List2) {
			head = List2.head;
			tail = List2.tail;
		}
		//operator overloading
	   void operator = (const linkedList &List2){
		this->head =List2.head;
		this->tail=tail;
		}
		//inserting number at the front
		void insertAtFront (int number) {
			node *b = new node();
			b->a = number;
			b->next = head;
			head = b;
		}
		//inserting number at the back
		void insertAtBack (int number) {
			node *b = new node();
			b->a = number;
			b->next = NULL;
			
			if (head == NULL) {
				head = b;
				tail = b;
				b = NULL;
			}else {
				tail->next = b;
				tail = b;
			}
		}
		  //searching
		void search(){  
		    node *ptr = new node;  
		    int item,i=0,flag;  
		    ptr = head;   
		    if(ptr == NULL){  
		    	cout<<"Enter an item.\n"; 
		    } else {   
		    	cout<<"Enter item which you want to search:\n";
		        cin>>item;   
		          
		        while (ptr!=NULL){  
		            if(ptr->a == item){  
		            	cout<<"Found at node of location "<<(i+1)<<endl;
		                  
		                flag=0;
						break;  
		            }else {  
		                flag=1;  
		            }  
		            i++;  
		            ptr = ptr -> next;  
		        }  
		        if(flag==1){  
		        	cout<<"Not found!\n";
		              
		        }  
		    }     
		          
		}
	
		void output(){
		    node *temp=new node;
		    temp = head;
		    if (head == NULL) { 
		       cout<<"Error"<<endl;       
		       return;  
		    }else {
			    cout<<"The current linked  list elements are:"<<endl;
			    while(temp!=NULL){
			      cout<<temp->a<<"\t";
			      temp=temp->next;
			    }		    	
			}

	  	}
	  	
		//Constructor that generates a linked list of random integers
		linkedList(int listSize) {
			int i=0;
			while (i < listSize) {
				insertAtBack (rand());
				i++;
			}
			output();
		}
	
		//removing duplicate numbers
		void removeDuplicate() {  
		    node *current = new node;
		    node *index = new node;
		    node *temp = new node;
			current = head,  index = NULL, temp = NULL;  
		      
		    if(head == NULL) {  
		        return;  
		    }  
		    else {  
		        while(current != NULL){    
		            temp = current;   
		            index = current->next;  
		              
		            while(index != NULL) {    
		                if(current->a == index->a) {   
		                    temp->next = index->next;  
		                }  
		                else {  
		                    temp = index;  
		                }  
		                index = index->next;  
		            }  
		            current = current->next;  
		        } 
				output();         
		    }  
		}  
      	//reversing
		void reverse_list() {
			if (head == NULL) return;
			
		    node *temp = new node;
		    node *prev = new node;
		    node *current = new node;
		    
			temp = NULL;
		    prev = NULL;
		    current = head;
		    while(current != NULL) {
		        temp = current->next;
		        current->next = prev;
		        prev = current;
		        current = temp;
		    }
		    head = prev;
		}
};

int main() {
	int size_of_list, choice, insertedNum;

	cout<<"Enter the number of integers to be generated:";
	cin>>size_of_list;

	linkedList List(size_of_list);
	    cout<<"Choose any of the following:"<<endl;
        cout<<"1.Node at the front."<<endl;
        cout<<"2.Node at the end."<<endl;
        cout<<"3.Display Linked List"<<endl;
        cout<<"4.Search Element"<<endl;
        cout<<"5.Reverse Linked List "<<endl;
		cout<<"6.Remove duplicates from the list."<<endl;
        cout<<"7.Exit "<<endl;
			
    while (1){
        cout<<"Enter:";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter the number to insert at the front:"<<endl;
			cin>>insertedNum;
            List.insertAtFront (insertedNum);
            cout<<endl;
            break;
        case 2:
            cout<<"Enter the number to insert at the end"<<endl;
            cin>>insertedNum;
            List.insertAtBack (insertedNum);
            cout<<endl;
            break;
        case 3:
            List.output();
            cout<<endl;
            break;
        case 4:
            List.search();
            cout<<endl;
            break;
        case 5:
            List.reverse_list();
            cout<<endl;
            break;
        case 6:
            cout<<"Removing duplicates"<<endl;
            List.removeDuplicate();
            cout<<endl;
            break;
        case 7:
            cout<<"\nEnter a number you want to delete: "<<endl;
            cin>>insertedNum;
            break;            
        case 8:
            cout<<"End!"<<endl;
            exit(1);
            break;  
        default:
            cout<<"Invalid input!"<<endl;
        }
    }
	
}
