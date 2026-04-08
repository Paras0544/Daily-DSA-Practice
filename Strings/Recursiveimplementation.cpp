#include<iostream>
#include<string>
using namespace std;

class Solution {
    public:

    int helper(const string& s, int i, long long num, int sign){ 
        if(i >= s.size() || !isdigit(s[i])){ // base case: if we reach the end of the string or encounter a non-digit character
            return (sign * num);
        }

        num = num*10 + (s[i] - '0'); // here we multiply the current number by 10 and add the new digit to it because we are processing the string from left to right, so we need to shift the previous digits to the left and add the new digit at the end
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