#include <iostream>
using namespace std;

class QueueSim {
    int *a;
    int front, rear, capacity;
public:
    QueueSim(int size) : capacity(size) {
        a = new int[capacity];
        front = 0;
        rear = 0;
    }

    bool empty() const {
        return front == rear;
    }

    bool full() const {
        return (rear + 1) % capacity == front;
    }

    void push(int x) {
        if (full()) {
            cout << "Queue Overflow\n";
            return;
        }
        a[rear] = x;
        rear = (rear + 1) % capacity;
    }

    void pop() {
        if (empty()) return;
        front = (front + 1) % capacity;
    }

    int frontElement() const {
        if (empty()) return -1;
        return a[front];
    }

    int size() const {
        if (rear >= front) return rear - front;
        return capacity - front + rear;
    }
};

class StackOneQueue {
    QueueSim q;
    int capacity;
public:
    StackOneQueue(int size) : capacity(size), q(size + 1) {}

    void push(int x) {
        int sz = q.size();
        q.push(x);
        for (int i = 0; i < sz; i++) {
            int val = q.frontElement();
            q.pop();
            q.push(val);
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack Underflow\n";
            return;
        }
        q.pop();
    }

    int top() {
        if (q.empty()) {
            cout << "Stack empty\n";
            return -1;
        }
        return q.frontElement();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    StackOneQueue st(10);
    st.push(10);
    st.push(20);
    cout << st.top() << "\n"; // 20
    st.pop();
    cout << st.top() << "\n"; // 10
    return 0;
}
