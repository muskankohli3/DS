#include <iostream>
using namespace std;

class Queue {
private:
    struct Node {
        int data;
        Node* next;
        Node(int value) {
            data = value;
            next = NULL;
        }
    };
    Node* front;
    Node* rear;
    int size;

public:
    Queue() {
        front = NULL;
        rear = NULL;
        size = 0;
    }

    void enqueue(int data) {
        Node* new_node = new Node(data);
        if (front == NULL && rear == NULL) {
            front = rear = new_node;
        } else {
            rear->next = new_node;
            rear = new_node;
        }
        size++;
        cout << "Data added" << endl;
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }
        int data = front->data;
        Node* temp = front;
        front = front->next;
        delete temp;
        size--;
        if (front == NULL) {
            rear = NULL;  // Reset rear if queue becomes empty
        }
        cout << "Dequeue element => " << data << endl;
    }

    void display() {
        if (front == NULL) {
            cout << "Empty queue" << endl;
            return;
        }
        Node* current = front;
        while (current != NULL) {
            cout << current->data << " => ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    void getSize() {
        cout << "Size of queue = " << size << endl;
    }
};

int main() {
    Queue q;
    int choice, data;

    while (true) {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Size\n0. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the data: ";
                cin >> data;
                q.enqueue(data);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                q.getSize();
                break;
            case 0:
                exit(0);
            default:
                cout << "Invalid case" << endl;
        }
    }
}
