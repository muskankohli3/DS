#include <iostream>
using namespace std;

int main() {
    string postfix;
    cout << "Enter postfix expression: ";
    cin >> postfix;

    int stack[postfix.length()];
    int top = -1;

    for (int i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];
        if (ch >= '0' && ch <= '9') {
            stack[++top] = ch - '0';
        } else {
            if (top < 1) {
                cout << "Invalid postfix expression\n";
                return 0;
            }
            int val2 = stack[top--];
            int val1 = stack[top--];
            int res = 0;

            switch (ch) {
                case '+': res = val1 + val2; break;
                case '-': res = val1 - val2; break;
                case '*': res = val1 * val2; break;
                case '/': res = val1 / val2; break;
                default:
                    cout << "Unknown operator\n";
                    return 0;
            }
            stack[++top] = res;
        }
    }

    if (top != 0) {
        cout << "Invalid postfix expression\n";
        return 0;
    }
    cout << "Result: " << stack[top] << "\n";

    return 0;
}
