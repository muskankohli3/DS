#include <iostream>
using namespace std;

#define SIZE 100

void createArray(int arr[], int &n) {
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void displayArray(int arr[], int n) {
    if (n == 0) {
        cout << "Array is empty!\n";
        return;
    }
    cout << "Array elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void insertElement(int arr[], int &n) {
    if (n >= SIZE) {
        cout << "Array is full! Cannot insert.\n";
        return;
    }
    int pos, val;
    cout << "Enter position to insert (1-" << n+1 << "): ";
    cin >> pos;
    cout << "Enter value to insert: ";
    cin >> val;
    
    if (pos < 1 || pos > n+1) {
        cout << "Invalid position!\n";
        return;
    }
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = val;
    n++;
    cout << "Element inserted.\n";
}

void deleteElement(int arr[], int &n) {
    if (n == 0) {
        cout << "Array is empty! Cannot delete.\n";
        return;
    }
    int pos;
    cout << "Enter position to delete (1-" << n << "): ";
    cin >> pos;
    
    if (pos < 1 || pos > n) {
        cout << "Invalid position!\n";
        return;
    }
    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    cout << "Element deleted.\n";
}

void linearSearch(int arr[], int n) {
    int val;
    cout << "Enter value to search: ";
    cin >> val;
    for (int i = 0; i < n; i++) {
        if (arr[i] == val) {
            cout << "Element found at position " << (i + 1) << "\n";
            return;
        }
    }
    cout << "Element not found.\n";
}

int main() {
    int arr[SIZE], n = 0;
    int choice;
    do {
        cout << "\n------ MENU ------\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: createArray(arr, n); break;
            case 2: displayArray(arr, n); break;
            case 3: insertElement(arr, n); break;
            case 4: deleteElement(arr, n); break;
            case 5: linearSearch(arr, n); break;
            case 6: cout << "Exiting program.\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);
    
    return 0;
}