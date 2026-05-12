#include <iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;  

        for (auto el : s) {
            if (el == '(' || el == '{' || el == '[')
                st.push(el);  
            else {
                if (st.empty()) return false;  // No matching opening bracket

                char ch = st.top();
                st.pop();

                // Check for matching pair
                if ((el == ')' && ch == '(') ||
                    (el == ']' && ch == '[') ||
                    (el == '}' && ch == '{'))
                    continue;
                else
                    return false;
            }
        }
        return st.empty();  // True if all brackets matched
    }
};

int main() {
    Solution sol;
    string s = "()[{}()]";

    if (sol.isValid(s))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}
