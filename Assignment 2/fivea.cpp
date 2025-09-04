#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of the matrix (n): ";
    cin >> n;

    int a[n];
    cout << "Enter " << n << " diagonal elements:\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Full matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                cout << a[i] << " ";
            else
                cout << 0 << " ";
        }
        cout << "\n";
    }
    return 0;
}

