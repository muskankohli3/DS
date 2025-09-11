#include <iostream>
#include <vector>
using namespace std;

void firstNonRepeating(string& s) {
    char CHAR =256;
    int freq[CHAR] = {0};
    vector<char> q;
    
    for (char ch : s) {
        freq[ch]++;
        q.push_back(ch);

        while (!q.empty() && freq[q.front()] > 1) {
            q.erase(q.begin());
        }

        if (q.empty())
            cout << -1 << " ";
        else
            cout << q.front() << " ";
    }
    cout << "\n";
}

int main() {
    string s;
    cout << "Enter string without spaces: ";
    cin >> s;
    firstNonRepeating(s);
    return 0;
}
