#include <iostream>
using namespace std;

void heap(int arr[], int n, int i, bool maxHeap) {
  int root = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (maxHeap) {
    if (left < n && arr[left] > arr[root])
    root = left;
    if (right < n && arr[right] > arr[root])
    root = right;
  } 
  else {
    if (left < n && arr[left] < arr[root])
    root = left;
    if (right < n && arr[right] < arr[root])
    root = right;
  }

  if (root != i) {
    swap(arr[i], arr[root]);
    heap(arr, n, root, maxHeap);
  }
}

void heapSort(int arr[], int n, bool ascending = true) {
  bool maxHeap = !ascending;

  for (int i = n / 2 - 1; i >= 0; i--)
    heap(arr, n, i, maxHeap);

  for (int i = n - 1; i > 0; i--) {
    swap(arr[0], arr[i]);
    heap(arr, i, 0, maxHeap);
  }
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}
void printArray(int arr[], int n) {
 for (int i = 0; i < n; i++)
  cout << arr[i] << " ";
 cout << endl;
}

int main() {
  int arr[] = {64, 34, 25, 12, 22, 11, 90};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "Original array: ";
  printArray(arr, n);

  heapSort(arr, n, true);
  cout << "Sorted (increasing): ";
  printArray(arr, n);

  heapSort(arr, n, false);
  cout << "Sorted (decreasing): ";
  printArray(arr, n);
  return 0;
}

