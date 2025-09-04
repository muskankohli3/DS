#include <iostream>
using namespace std;

int main() {
    int n, k;
    cout << "Enter array size and difference k: ";
    cin >> n >> k;
    int arr[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] - arr[j] == k || arr[j] - arr[i] == k)
                count++;
        }
    }
    cout << "Total pairs with difference " << k << " : " << count << "\n";
    return 0;
}
