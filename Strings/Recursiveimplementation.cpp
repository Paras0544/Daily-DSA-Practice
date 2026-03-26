#include<iostream>
#include<string>
using namespace std;

class Solution {
    public:

    int helper(const string& s, int i, long long num, int sign){
        if(i >= s.size() || !isdigit(s[i])){
            return (sign * num);
        }

        num = num*10 + (s[i] - '0'); //update num with current digit 
        return helper(s,i+1,num,sign);
    }
    int myAtoi(string s){
        int i = 0;
        while(i<s.size() && s[i] == ' '){
            i++;
        }
        int sign = 1;
        while(i<s.size() && (s[i] == '+' || s[i] == '-')){
            if(s[i] == '-'){
                sign = -1;
            }
            i++;
        }
        return helper(s,i,0,sign);
    }
};
int main(){
    Solution sol;
    string s = "   -42";
    cout << sol.myAtoi(s) << endl;
    return 0;
}