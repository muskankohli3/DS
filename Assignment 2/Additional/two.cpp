#include <iostream>
using namespace std;

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;
    int n = s.length();
    bool found = false;
    for (int i = 1; i < n - 1 && !found; i++) {
        for (int j = i + 1; j < n && !found; j++) {
            string p1 = s.substr(0, i);
            string p2 = s.substr(i, j - i);
            string p3 = s.substr(j);

            // Check each part if part is substring of both others
            if ((p2.find(p1) != string::npos && p2.find(p3) != string::npos) ||
                (p1.find(p2) != string::npos && p1.find(p3) != string::npos) ||
                (p3.find(p1) != string::npos && p3.find(p2) != string::npos)) {
                found = true;
                break;
            }
        }
    }

    if (found)
        cout << "Yes, can split\n";
    else
        cout << "No, cannot split\n";

    return 0;
}
