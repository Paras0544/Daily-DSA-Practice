#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
string ReverseWords(string s){
    string result = "";
    int n = s.length();
    int i = n-1;

    while(i>=0){
        while(i>=0 && s[i] == ' '){
            i--;
        }
        if(i<0){
            break;
        }
        int end = i;

        while(i>=0 && s[i]! = ' '){
            i--;
        }

        string word = s.substr(i+1, end - i);

        if(!result.empty()){
            result + = " ";
        }
        result + = word;
    }
    return result;
}
};
int main(){
    string s = "Hello World from C++";
    Solution sol;
    string result = sol.ReverseWords(s);
    cout << "Reversed words: " << result << endl; // Expected: "C++ from World Hello"
    return 0;
}