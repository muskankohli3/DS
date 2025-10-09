#include<iostream>
using namespace std;

class Node{
public:
	int data;
	Node* next;
	Node(int x): data(x),next(nullptr){
	}
};

class CircularLinkedList{
	Node* head;
public:
	CircularLinkedList(): head(nullptr){}
	
	void insert(int x){
		Node* newNode = new Node(x);
		if(head == nullptr){
			head = newNode;
			newNode->next = head;
		}
		else{
			Node* temp = head;
			do{
				temp = temp->next;
			} while(temp->next != head);
			temp->next = newNode;
			newNode->next = head;
		}
	}
	
	int size(){
		int count = 0;
		Node* temp = head;
		do{
			count++;
			temp = temp->next;
		} while(temp!=head);
		return count;
	}
};

int main(){
	CircularLinkedList c;
	c.insert(20);
	c.insert(100);
	c.insert(40);
	c.insert(80);
	c.insert(60);
	cout<<"Size = "<<c.size();
	return 0;
	}