#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:

    int prec(char c) {
        if (c == '^') {
            return 3;
        }
        else if (c == '/' || c == '*') {
            return 2;
        }
        else if (c == '+' || c == '-') {
            return 1;
        }
        else {
            return -1;
        }
    }

    void infixToPostfix(string s) {

        stack<char> st;
        string result;

        for (int i = 0; i < s.length(); i++) {

            char c = s[i];

            // Operand
            if ((c >= 'a' && c <= 'z') ||
                (c >= 'A' && c <= 'Z') ||
                (c >= '0' && c <= '9')) {

                result += c;
            }

            // Opening bracket
            else if (c == '(') {
                st.push(c);
            }

            // Closing bracket
            else if (c == ')') {

                while (!st.empty() && st.top() != '(') {
                    result += st.top();
                    st.pop();
                }

                if (!st.empty()) {
                    st.pop();
                }
            }

            // Operator
            else {

                while (!st.empty() &&
                       st.top() != '(' &&
                       prec(c) <= prec(st.top())) {

                    result += st.top();
                    st.pop();
                }

                st.push(c);
            }
        }

        // Pop remaining operators
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        cout << "Postfix Expression is: " << result << endl;
    }
};

int main() {

    string exp = "(p+q)*(m-n)";

    cout << "Infix expression: " << exp << endl;

    Solution obj;
    obj.infixToPostfix(exp);

    return 0;
}