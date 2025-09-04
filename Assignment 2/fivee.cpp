#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of the matrix (n): ";
    cin >> n;

    int size = n * (n + 1) / 2;
    int a[size];
    cout << "Enter " << size << " elements of symmetric matrix (lower triangular part):\n";
    for (int i = 0; i < size; i++)
        cin >> a[i];

    cout << "Full matrix:\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j <= i)
                cout << a[k++] << " ";
            else
                cout << a[j * (j + 1) / 2 + i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
