#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextGreaterElement(const vector<int>& arr) {
    stack<int> s;
    vector<int> result(arr.size(), -1);
    for (int i = arr.size() - 1; i >= 0; --i) {
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }
        if (!s.empty()) result[i] = s.top();
        s.push(arr[i]);
    }
    return result;
}

int main() {
    vector<int> arr = {4, 5, 2, 25};
    vector<int> res = nextGreaterElement(arr);
    for (int val : res) cout << val << " ";
    return 0;
}
