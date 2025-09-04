#include <iostream>
using namespace std;

int binarySearch(int a[], int n, int x) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] == x)
            return mid;
        else if (a[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

int main() {
    int arr[] = {2, 4, 7, 13, 20, 32, 49};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 13;
    int result = binarySearch(arr, n, key);
    cout << result << endl;
    return 0;
}
