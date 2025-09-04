#include <iostream>
using namespace std;

int main() {
    char ch = 'G';
    if(ch >= 'A' && ch <= 'Z'){
      ch+=32;
    }
    cout << ch << endl;
    return 0;
}
