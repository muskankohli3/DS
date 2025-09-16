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

class LinkedList{
  private:
  Node* head;

  public:
  LinkedList(){
    head = nullptr;
  }
  void insert(int num){
    Node* temp1 = new Node(num);
    Node* temp2 = head;
    if(head == nullptr){
      head = temp1;
    }
    else{
      while(temp2->next!=nullptr){
        temp2= temp2->next;
      }
      temp2->next = temp1;
    }
  }

  void display(){
    Node* temp = head;
    if(temp == nullptr){
      cout<<"Empty list";
    }
    else{
    while(temp!=nullptr){
      cout<<temp->data<<" ";
      temp = temp->next;
    }
    }
  }

  void reverse(){
    Node* temp = head;
    Node* prev = nullptr;
    Node* next = nullptr;
    while(temp!=nullptr){
      next = temp->next;
      temp->next = prev;
      prev = temp;
      temp = next;
    }
    head = prev;
  }
};

int main(){
  LinkedList l;
  int num;
  l.insert(1);
  l.insert(2);
  l.insert(3);
  l.insert(4);
  l.insert(5);
  l.display();
  l.reverse();
  cout<<endl;
  l.display();
}