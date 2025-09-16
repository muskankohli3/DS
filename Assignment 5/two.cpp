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
  int count(int num){
    Node* temp = head;
    int count = 0;
    while(temp!=nullptr){
      if(temp->data ==num){
        count++;
      }
      temp=temp->next;
    }
    return count;
  }
};

int main(){
  LinkedList l;
  int num;
  l.insert(1);
  l.insert(2);
  l.insert(1);
  l.insert(2);
  l.insert(1);
  l.insert(3);
  l.insert(1);
  cout<<"Enter number to count: "<<endl;
  cin>>num;
  cout<<num<<" is found "<<l.count(num)<<" times in the list";
}