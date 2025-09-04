#include <iostream>
using namespace std;

int main() {
    string expr;
    cout << "Enter expression: ";
    cin >> expr;

    char stack[expr.length()];
    int top = -1;
    bool balanced = true;

    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1) {
                balanced = false;
                break;
            }
            char topChar = stack[top--];
            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) {
                balanced = false;
                break;
            }
        }
    }

    if (top != -1) balanced = false;

    if (balanced)
        cout << "Balanced\n";
    else
        cout << "Not balanced\n";

    return 0;
}
