#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
  for(int i=0; i<n-1; i++) {
    int min = i;
    for(int j=i+1; j<n; j++) {
      if(arr[j]<arr[min]) {
        min = j;
      }
    }
    if(i!=min) {
      int temp = arr[i];
      arr[i] = arr[min];
      arr[min] = temp;
    }
  }
}

void insertionSort(int arr[], int n) {
  for(int i=1; i<n; i++) {
    int key = arr[i];
    int j = i-1;
    while(j>=0 && arr[j]>key) {
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = key;
  }
}

void bubbleSort(int arr[], int n) {
  for(int i=0; i<n-1; i++) {
    for(int j=0; j<n-1-i; j++) {
      if(arr[j]>arr[j+1]) {
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}

void mergeSort(int arr[], int left, int right) {
  if(left < right) {
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int* L = new int[n1];
    int* R = new int[n2];
    for(int i = 0; i < n1; i++) {
      L[i] = arr[left + i];
    }
    for(int i = 0; i < n2; i++) {
      R[i] = arr[mid + 1 + i];
    }
    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2) {
      if(L[i] <= R[j]) {
        arr[k++] = L[i++];
      } 
      else {
        arr[k++] = R[j++];
      }
    }
    while(i < n1) {
      arr[k++] = L[i++];
    }
    while(j < n2) {
      arr[k++] = R[j++];
    }
    delete[] L;
    delete[] R;
  }
}

void quickSort(int arr[], int low, int high) {
  if(low < high) {
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++) {
      if(arr[j] < pivot) {
        i++;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    int pi = i + 1;
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

void printArray(int arr[], int n) {
  for(int i=0; i<n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
}

int main() {
  int arr[] = {64, 25, 12, 22, 11};
  int n = sizeof(arr)/sizeof(arr[0]);
  int a[n], b[n], c[n], d[n], e[n];
  for(int i=0; i<n; i++) {
    a[i] = b[i] = c[i] = d[i] = e[i] = arr[i];
  }

  cout << "Original array:\n";
  printArray(arr, n);

  selectionSort(a, n);
  cout << "Selection Sort:\n";
  printArray(a, n);

  insertionSort(b, n);
  cout << "Insertion Sort:\n";
  printArray(b, n);

  bubbleSort(c, n);
  cout << "Bubble Sort:\n";
  printArray(c, n);

  mergeSort(d, 0, n-1);
  cout << "Merge Sort:\n";
  printArray(d, n);

  quickSort(e, 0, n-1);
  cout << "Quick Sort:\n";
  printArray(e, n);

  return 0;
}
