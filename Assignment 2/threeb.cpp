#include<iostream>
using namespace std;

int findMissingNumber(int arr[], int n) {
    int left = 0, right = n - 2;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] != mid + 1)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return left + 1;
}


int main(){
  int arr[] = {1,2,3,4,5,7};
  cout<< findMissingNumber(arr,6);
  return 0;
}