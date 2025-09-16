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

  void insertBeg(int num){
    Node* temp = new Node(num);
    temp->next = head;
    head = temp;
}

  void insertEnd(int num){
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

void insertBetween(int val1, int val2, int num) {
  if (head == nullptr) {
    cout << "List is empty" << endl;
    return;
  }
  Node* temp1 = head;
  while (temp1 != nullptr && temp1->next != nullptr) {
    if (temp1->data == val1 && temp1->next->data == val2) {
      Node* temp2 = new Node(num);
        temp2->next = temp1->next;
        temp1->next = temp2;
        return;
      }
    temp1 = temp1->next;
  }
  cout << "No such adjacent nodes with values " << val1 << " and " << val2 << " found." << endl;
}

void deleteBeg(){
  if(head == nullptr){
    cout<<"List is empty";
  }
  else{
    Node* temp = head;
    head = head->next;
    delete temp;
  }
}

void deleteEnd(){
  if(head == nullptr){
    cout<<"List is empty";
  }
  else if(head->next == nullptr){
    delete head;
    head = nullptr;
  }
  else{
    Node* temp = head;
    while(temp->next->next!= nullptr){
      temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
  }
}

void deleteSpec(int num){
    if(head == nullptr){
        cout<<"List is empty";
    }
    else{
        Node* temp = head;
        Node* prev = nullptr;
        while(temp!= nullptr && temp->data != num){
            prev = temp;
            temp = temp->next;
        }
        if(temp == nullptr){
            cout<<"Element not found";
        }
        else if(temp == head){
            head = head->next;
        }
        else{
            prev->next = temp->next;
            delete temp;
        }
    }
}

  int search(int num){
    int pos = 1;
    Node* temp = head;
    while(temp!=nullptr){
      if(temp->data ==num){
          return pos;
          break;
      }
      temp = temp->next;
      pos++;
    }
    return -1;
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

};

int main() {
  LinkedList l;
  int choice,num,val1,val2;

  while (true) {
    cout << "\n(1) Insertion at the beginning.\n(2) Insertion at the end.\n(3) Insertion in between (before after a node having a specific value, say 'Insert a new Node 35 before/after the Node 30').\n(4) Deletion from the beginning.\n(5) Deletion from the end.\n(6) Deletion of a specific node, say 'Delete Node 60').\n(7) Search for a node and display its position from head.\n(8) Display all the node values\nEnter your choice: ";
    cin >> choice;
    switch (choice) {
    case 1:
      cout<<"Enter the number: ";
      cin>>num;
      l.insertBeg(num);
      break;
    case 2:
      cout<<"Enter the number: ";
      cin>>num;
      l.insertEnd(num);
      break;
    case 3:
      cout<<"Enter the number to insert: ";
      cin>>num;
      cout<<"\nEnter the numbers between which to insert: ";
      cin>>val1>>val2;
      l.insertBetween(val1,val2,num);
      break;
    case 4:
      l.deleteBeg();
      break;
    case 5:
      l.deleteEnd();
      break;
    case 6:
      cout<<"Enter the number: ";
      cin>>num;
      l.deleteSpec(num);
      break;
    case 7:
      cout<<"Enter the number: ";
      cin>>num;
      if(l.search(num) == -1){
        cout<<"Element not found";
      }
      else{
        cout<<"Found at position "<<l.search(num)<<endl;
      }
      break;
    case 8:
      l.display();
      break;
    default:
      cout<<"Invalid case";   
}
  }

  
 return 0;
}
