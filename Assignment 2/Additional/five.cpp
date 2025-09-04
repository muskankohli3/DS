#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
        
    int count2 = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 2)
            count2++;
    }

    int i = n - 1;
    int j = n + count2 - 1;

    while (i < j) {
        if (j < n)
            arr[j] = arr[i];
        if (arr[i] == 2) {
            j--;
            if (j < n)
                arr[j] = 2;
        }
        i--;
        j--;
    }

    cout << "Modified array:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";

    return 0;
}
