#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool canStackSort(const vector<int>& A) {
    stack<int> S;
    int expected = 1;
    int i = 0, n = A.size();

    while (i < n || !S.empty()) {
        if (!S.empty() && S.top() == expected) {
            S.pop();
            expected++;
        } else if (i < n) {
            S.push(A[i++]);
        } else {
            return false; 
        }
    }
    return true;
}

int main() {
    vector<int> A = {4, 1, 3, 2, 5};
    cout << (canStackSort(A) ? "Yes" : "No") << endl;
    return 0;
}
