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
  int findMiddle(){
    if(head == nullptr){
      cout<<"Empty list";
    }
    Node* slow = head;
    Node* fast = head;
    while(fast!=nullptr && fast->next!=nullptr){
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow->data;
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
  cout<<"Middele of list is: "<<l.findMiddle();
}