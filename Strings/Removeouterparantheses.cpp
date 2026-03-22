#include<iostream>
#include<string>
using namespace std;
class Solution {
    public:
    string RemoveOuterParantheses(string s){
        string result = "";
        int levelCounter = 0;

        for(char ch : s){
            if(ch == '('){
                if(levelCounter > 0){
                    result += ch;
                }
                levelCounter++;
            }
            else if(ch == ')'){
                levelCounter--;
                if(levelCounter > 0){
                    result += ch;
                }
            }
        }
        return result;
    }
};
int main(){
    string s = "(()())(())";
    Solution sol;
    string result = sol.RemoveOuterParantheses(s);
    cout << "Result after removing outer parentheses: " << result << endl; // Expected: "()()()"
    return 0;
}