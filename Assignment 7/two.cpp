#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n) {
  int start = 0, end = n - 1;
  while(start < end) {
    int min = start, max = start;
    for(int i = start; i <= end; i++) {
      if(arr[i] < arr[min]) {
        min = i;
      }
      if(arr[i] > arr[max]) {
        max = i;
      }
    }
    if(min != start) {
      int temp = arr[start];
      arr[start] = arr[min];
      arr[min] = temp;
      if(max == start)
        max = min;
    }

    if(max != end) {
      int temp = arr[end];
      arr[end] = arr[max];
      arr[max] = temp;
    }

    start++;
    end--;
  }
}

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
  int arr[] = {64, 25, 12, 22, 11, 90, 33};
  int n = sizeof(arr)/sizeof(arr[0]);

  cout << "Original array:\n";
  printArray(arr, n);

  improvedSelectionSort(arr, n);

  cout << "Array after improved selection sort:\n";
  printArray(arr, n);

  return 0;
}
