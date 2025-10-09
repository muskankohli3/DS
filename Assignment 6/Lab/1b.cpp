#include<iostream>
using namespace std;

class Node{
public:
	int data;
	Node* next;
	Node* prev;
	Node(int x): data(x),next(nullptr),prev(nullptr){}
};

class DoublyLinkedList{
	Node* head;
public:
	DoublyLinkedList(): head(nullptr){}
	
	void insertBeg(int x){
		Node* newNode = new Node(x);
		if(head == nullptr){
			head = newNode;
		}
		else{
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
	}
	
	void insertEnd(int x){
		Node* newNode = new Node(x);
		if(head == nullptr){
			head = newNode;
			newNode->next = head;
			newNode->prev = head;
		}
		else{
			Node* temp = head;
			while(temp->next != nullptr){
				temp = temp->next;
			}
			temp->next = newNode;
			newNode->prev = temp;
		}
	}
	
	void insertAfter(int x,int key){
		Node* temp = head;
		bool found = false;
		while(temp->next != nullptr){
			if(temp->data == key){
				found = true;
				break;
			}
			temp = temp->next;
		} 
		if(found == false){
			cout<<"Element not found";
		}
		else{
			Node* newNode = new Node(x);
			newNode->next = temp->next;
			newNode->prev = temp;
			temp->next->prev = newNode;
			temp->next = newNode;
		}
	}
	
	void deleteNum(int x){
		if(head == nullptr){
			cout<<"Empty list";
			return;
		}
		Node* temp = head;
		bool found = false;
		while(temp->next != nullptr){
			if(temp->data == x){
				found = true;
				break;
			}
			temp = temp->next;
		}
		if(found == false){
			cout<<"Element not found";
		}
		else{
			temp->prev->next = temp->next;
			delete temp;
		}
	}
	
	bool search(int x){
		Node* temp = head;
		bool found = false;
		while(temp->next != nullptr){
			if(temp->data == x){
				found = true;
				break;
			}
			temp = temp->next;
		}
		return found;
	}
};

int main(){
	DoublyLinkedList c;
	int num,key,choice;
	while(true){
		cout<<"Enter choice\n1)Insert at beginning.\n2)Insert at end./n3)Insert after an element.\n4)Delete an element.\n5)Search an element\n6)Return";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"\nEnter the element to insert:";
				cin>>num;
				c.insertBeg(num);
				break;
			case 2:
				cout<<"\nEnter the element to insert:";
				cin>>num;
				c.insertEnd(num);
				break;
			case 3:
				cout<<"\nEnter the element to insert:";
				cin>>num;
				cout<<"\nEnter the element to insert after:";
				cin>>key;
				c.insertAfter(num,key);
				break;
			case 4:
				cout<<"\nEnter the element to delete:";
				cin>>num;
				c.deleteNum(num);
				break;
			case 5:
				cout<<"\nEnter the element to find:";
				cin>>num;
				if(c.search(num)){
					cout<<"Element found";
				}
				else{
					cout<<"Element not found";
				}
				break;
			default:
				cout<<"Invalid";
				break;
		}
	}
	return 0;
}

