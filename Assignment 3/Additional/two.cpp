#include <iostream>
#include <stack>
using namespace std;

class Stack {
    stack<int> s;
    int minEle;
public:
    void push(int x) {
        if (s.empty()) {
            s.push(x);
            minEle = x;
        } else {
            if (x >= minEle) {
                s.push(x);
            } else {
                s.push(2 * x - minEle);
                minEle = x;
            }
        }
    }

    void pop() {
        if (s.empty()) return;
        int t = s.top(); s.pop();
        if (t < minEle) {
            minEle = 2 * minEle - t;
        }
    }

    int top() {
        int t = s.top();
        if (t < minEle) return minEle;
        return t;
    }

    int getMin() {
        return minEle;
    }

    bool empty() {
        return s.empty();
    }
};

int main() {
    Stack st;
    st.push(3);
    st.push(5);
    cout << st.getMin() << "\n"; // 3
    st.push(2);
    st.push(1);
    cout << st.getMin() << "\n"; // 1
    st.pop();
    cout << st.getMin() << "\n"; // 2
    st.pop();
    cout << st.top() << "\n";    // 5
}
