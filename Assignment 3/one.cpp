#include <iostream>
using namespace std;

int top = -1;
int *stack;
int n;

bool isFull() {
    return top == n - 1;
}

bool isEmpty() {
    return top == -1;
}

void push() {
    if (isFull()) {
        cout << "Stack Overflow! Cannot push.\n";
    } else {
        cout << "Enter value to push: ";
        int val;
        cin >> val;
        stack[++top] = val;
        cout << val << " pushed to stack.\n";
    }
}

void pop() {
    if (isEmpty()) {
        cout << "Stack Underflow! Cannot pop.\n";
    } else {
        int popped = stack[top--];
        cout << "Popped element: " << popped << "\n";
    }
}

void peek() {
    if (isEmpty()) {
        cout << "Stack is empty. No top element.\n";
    } else {
        cout << "Top element: " << stack[top] << "\n";
    }
}

void display() {
    if (isEmpty()) {
        cout << "Stack is empty.\n";
    } else {
        cout << "Stack elements (top to bottom): ";
        for (int i = top; i >= 0; i--)
            cout << stack[i] << " ";
        cout << "\n";
    }
}

int main() {
    cout << "Enter stack size: ";
    cin >> n;
    stack = new int[n];

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Push\n2. Pop\n3. IsEmpty\n4. IsFull\n5. Display\n6. Peek\n7. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: cout << (isEmpty() ? "Stack is empty.\n" : "Stack is not empty.\n"); break;
            case 4: cout << (isFull() ? "Stack is full.\n" : "Stack is not full.\n"); break;
            case 5: display(); break;
            case 6: peek(); break;
            case 7:
                cout << "Exiting program.\n";
                delete[] stack;
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}
