#include <iostream>
#include <stack>
using namespace std;

string decodeString(string s) {
    stack<int> numStack;
    stack<string> strStack;

    string current = "";
    int k = 0;

    for (char ch : s) {
        if (isdigit(ch)) {
            k = k * 10 + (ch - '0'); // handle multi-digit numbers
        }
        else if (ch == '[') {
            numStack.push(k);
            strStack.push(current);
            k = 0;
            current = "";
        }
        else if (ch == ']') {
            int repeat = numStack.top(); numStack.pop();
            string prev = strStack.top(); strStack.pop();

            string temp = "";
            for (int i = 0; i < repeat; i++) {
                temp += current;
            }
            current = prev + temp;
        }
        else {
            current += ch;
        }
    }
    return current;
}

int main() {
    string s;
    cout << "Enter encoded string: ";
    cin >> s;

    cout << "Decoded string: " << decodeString(s);

    return 0;
}