#include <iostream>
using namespace std;

int main() {
    int r1, c1, t1;
    cout << "Enter rows, columns, and non-zero elements of first matrix: ";
    cin >> r1 >> c1 >> t1;
    int m1[t1][3];
    cout << "Enter row, column, value for first matrix:\n";
    for (int i = 0; i < t1; i++)
        cin >> m1[i][0] >> m1[i][1] >> m1[i][2];

    int r2, c2, t2;
    cout << "Enter rows, columns, and non-zero elements of second matrix: ";
    cin >> r2 >> c2 >> t2;
    int m2[t2][3];
    cout << "Enter row, column, value for second matrix:\n";
    for (int i = 0; i < t2; i++)
        cin >> m2[i][0] >> m2[i][1] >> m2[i][2];

    if (c1 != r2) {
        cout << "Matrices cannot be multiplied due to incompatible dimensions.\n";
        return 0;
    }

    int result[r1][c2];
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            result[i][j] = 0;

    for (int i = 0; i < t1; i++) {
        for (int j = 0; j < t2; j++) {
            if (m1[i][1] == m2[j][0]) {
                result[m1[i][0]][m2[j][1]] += m1[i][2] * m2[j][2];
            }
        }
    }

    cout << "Resultant matrix after multiplication:\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++)
            cout << result[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
