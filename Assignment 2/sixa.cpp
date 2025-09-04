#include <iostream>
using namespace std;

int main() {
    int rows, cols, terms;
    cout << "Enter number of rows, columns, and non-zero elements: ";
    cin >> rows >> cols >> terms;

    int triplet[terms][3];
    cout << "Enter each non-zero element as row, column, value:\n";
    for (int i = 0; i < terms; i++)
        cin >> triplet[i][0] >> triplet[i][1] >> triplet[i][2];

    cout << "Transpose matrix triplets:\n";
    // Transpose by swapping row and column of each triplet
    for (int i = 0; i < terms; i++)
        cout << triplet[i][1] << " " << triplet[i][0] << " " << triplet[i][2] << "\n";

    return 0;
}
