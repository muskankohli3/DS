#include<iostream>
using namespace std;

class Node {
public:
  int data;
  Node* next;
  Node(int value) {
    data = value;
    next = nullptr;
  }
};

class CircularSinglyLinkedList{
  private:
  Node* head; Node* tail;
  public:

  CircularSinglyLinkedList(){
    head = tail = nullptr;
  }

  void insertAtEnd(int num){
    Node* newNode = new Node(num);
    if(head == nullptr){
      head = newNode;
      newNode->next = head;
      return;
    }
    Node* temp = head;
    while(temp->next != head){
      temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
  }

  bool ifCircular(){
    Node* temp = head;
    while(temp != nullptr && temp != head){
      temp = temp->next;
    }
    return (temp == head);
  }

  void display(){
    Node* temp = head;
    do{
      cout<< temp->data<<endl;
      temp = temp->next;
    }while(temp != head);
  }
};

int main(){
  CircularSinglyLinkedList dl;
  dl.insertAtEnd(1);
  dl.insertAtEnd(2);
  dl.insertAtEnd(3);
  dl.insertAtEnd(4);
  dl.insertAtEnd(5);
  dl.insertAtEnd(6);
  if (dl.ifCircular()){
      cout<<"List is circular";
  }
  else{
      cout<<"List is not circular";
  }
}