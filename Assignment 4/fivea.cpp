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

class StackTwoQueues {
    QueueSim q1, q2;
    int capacity;
public:
    StackTwoQueues(int size) : capacity(size), q1(size + 1), q2(size + 1) {}

    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.frontElement());
            q1.pop();
        }
        swap(q1, q2);
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack Underflow\n";
            return;
        }
        q1.pop();
    }

    int top() {
        if (q1.empty()) {
            cout << "Stack empty\n";
            return -1;
        }
        return q1.frontElement();
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    StackTwoQueues st(10);
    st.push(10);
    st.push(20);
    cout << st.top() << "\n"; // 20
    st.pop();
    cout << st.top() << "\n"; // 10
    return 0;
}
