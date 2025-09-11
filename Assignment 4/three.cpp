#include <iostream>
#include <vector>
using namespace std;

void interleaveQueue(vector<int>& a) {
    int n = a.size();
    vector<int> result;

    for (int i = 0; i < n/2; i++) {
        result.push_back(a[i]);
        result.push_back(a[i + n/2]);
    }

    a = result;
}

int main() {
    int n;
    cout << "Enter number of elements (even): ";
    cin >> n;
    vector<int> a(n);

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    interleaveQueue(a);

    cout << "Interleaved queue: ";
    for (int val : a) {
        cout << val << " ";
    }
    cout << "\n";
    return 0;
}
