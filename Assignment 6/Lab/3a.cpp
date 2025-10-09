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
	
	void insert(int x){
		Node* newNode = new Node(x);
		if(head == nullptr){
			head = newNode;
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
	
	int size(){
		int count = 0;
		Node* temp = head;
		while(temp != nullptr){
			count++;
			temp = temp->next;
		}
		return count;
	}
};

int main(){
	DoublyLinkedList c;
	c.insert(20);
	c.insert(100);
	c.insert(40);
	c.insert(80);
	c.insert(60);
	cout<<"Size = "<<c.size();
	return 0;
	}