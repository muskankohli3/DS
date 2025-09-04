#include <iostream>
using namespace std;

int main() {
    int rows1, cols1, terms1;
    cout << "Enter rows, columns, and non-zero elements of first matrix: ";
    cin >> rows1 >> cols1 >> terms1;
    int m1[terms1][3];
    cout << "Enter row, column, value for first matrix:\n";
    for (int i = 0; i < terms1; i++)
        cin >> m1[i][0] >> m1[i][1] >> m1[i][2];

    int rows2, cols2, terms2;
    cout << "Enter rows, columns, and non-zero elements of second matrix: ";
    cin >> rows2 >> cols2 >> terms2;
    int m2[terms2][3];
    cout << "Enter row, column, value for second matrix:\n";
    for (int i = 0; i < terms2; i++)
        cin >> m2[i][0] >> m2[i][1] >> m2[i][2];

    if (rows1 != rows2 || cols1 != cols2) {
        cout << "Matrices dimensions do not match for addition.\n";
        return 0;
    }

    int result[terms1 + terms2][3];
    int i = 0, j = 0, k = 0;
    while (i < terms1 && j < terms2) {
        if (m1[i][0] < m2[j][0] || (m1[i][0] == m2[j][0] && m1[i][1] < m2[j][1])) {
            result[k][0] = m1[i][0];
            result[k][1] = m1[i][1];
            result[k][2] = m1[i][2];
            i++; k++;
        }
        else if (m1[i][0] > m2[j][0] || (m1[i][0] == m2[j][0] && m1[i][1] > m2[j][1])) {
            result[k][0] = m2[j][0];
            result[k][1] = m2[j][1];
            result[k][2] = m2[j][2];
            j++; k++;
        }
        else {
            // Same position
            int sum = m1[i][2] + m2[j][2];
            if (sum != 0) {
                result[k][0] = m1[i][0];
                result[k][1] = m1[i][1];
                result[k][2] = sum;
                k++;
            }
            i++; j++;
        }
    }
    while (i < terms1) {
        result[k][0] = m1[i][0];
        result[k][1] = m1[i][1];
        result[k][2] = m1[i][2];
        i++; k++;
    }
    while (j < terms2) {
        result[k][0] = m2[j][0];
        result[k][1] = m2[j][1];
        result[k][2] = m2[j][2];
        j++; k++;
    }

    cout << "Resultant matrix after addition (row col value):\n";
    for (int x = 0; x < k; x++)
        cout << result[x][0] << " " << result[x][1] << " " << result[x][2] << "\n";

    return 0;
}
