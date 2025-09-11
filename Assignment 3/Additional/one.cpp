#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> toLeft(const vector<int>& a) {
    stack<int> s;
    vector<int> result;
    for (int x : a) {
        while (!s.empty() && s.top() >= x) {
            s.pop();
        }
        if (s.empty()) {
            result.push_back(-1);
        } else {
            result.push_back(s.top());
        }
        s.push(x);
    }
    return result;
}

int main() {
    int n;
    cout<<"Enter number of elements: "<<endl;
    cin>>n;
    vector<int> a;
    cout<<"Enter array: "<<endl;
    for(int i=0;i<n;i++){
      int x;
      cin >> x;
      a.push_back(x);
    }
    vector<int> b = toLeft(a);
    for (int x : b) cout << x << " ";
    return 0;
}
