#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) {
        data = value;
        next = prev = nullptr;
    }
};

class DoublyLinkedList{
  private:
  Node* head; Node* tail;
  public:

  DoublyLinkedList(){
    head = tail = nullptr;
  }

  void insertAtEnd(char c){
    Node* newNode = new Node(c);
    if(head == nullptr){
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}


  bool isPalindrome(){
    Node* front = head;
    Node* back = tail;
    bool p = true;
    while (front != back && front->prev != back){
      if(front->data != back->data){
        p = false;
      }
      front = front->next;
      back = back->prev;
    }
    return p;
  }
};

int main(){
  DoublyLinkedList dl;
  dl.insertAtEnd('L');
  dl.insertAtEnd('E');
  dl.insertAtEnd('V');
  dl.insertAtEnd('E');
  dl.insertAtEnd('L');
  if(dl.isPalindrome()){
      cout<<"True";
  }
  else{
      cout<<"False";
  }
}

