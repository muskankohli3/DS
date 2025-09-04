#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of the matrix (n): ";
    cin >> n;

    int a[3 * n - 2];
    cout << "Enter " << 3 * n - 2 << " elements (lower diagonal, main diagonal, upper diagonal):\n";
    for (int i = 0; i < 3 * n - 2; i++)
        cin >> a[i];

    cout << "Full matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i - j == 1)
                cout << a[i - 1] << " ";
            else if (i - j == 0)
                cout << a[n - 1 + i] << " ";
            else if (i - j == -1)
                cout << a[2 * n - 1 + i] << " ";
            else
                cout << 0 << " ";
        }
        cout << "\n";
    }
    return 0;
}
