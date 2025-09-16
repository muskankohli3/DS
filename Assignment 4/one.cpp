#include <iostream>
using namespace std;

#define MAX 100

class Queue {
private:
    int arr[MAX];
    int front, rear, size;

public:
    Queue() {
        front = -1;
        rear = -1;
        size = 0;
    }

    void enqueue(int data) {
        if (rear == MAX - 1) {
            cout << "Queue is full" << endl;
            return;
        }
        if (front == -1) {
            front = 0;
        }
        rear++;
        arr[rear] = data;
        size++;
        cout << "Data added" << endl;
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Dequeued element => " << arr[front] << endl;
        front++;
        size--;
        if (front > rear) {
            front = rear = -1;  // Reset queue when empty
        }
    }

    void display() {
        if (front == -1 || front > rear) {
            cout << "Empty queue" << endl;
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " => ";
        }
        cout << "NULL" << endl;
    }

    void getSize() {
        cout << "Size of queue = " << size << endl;
    }
};

int main() {
    Queue q;
    int choice = 1, data;

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
                break;
            default:
                cout << "Invalid case" << endl;
                break;
        }
    }
}
