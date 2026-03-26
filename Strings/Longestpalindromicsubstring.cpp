#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
private:
    int expandAroundCenter(string s, int left, int right){
        while(left>=0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
        }
        return right - left - 1;
    }
    public:
    string LongestPalindrome(string s){
        if (s.empty())
            return "";
        int start = 0;
        int end = 0;

        for(int i=0; i<s.size(); i++){
            int odd = expandAroundCenter(s, i, i);
            int even = expandAroundCenter(s, i, i+1);
            int len = max(odd, even);

            if(len > end - start){
                start = i - (len - 1) / 2;
                end = i + len / 2;
            };
        }
        return s.substr(start, end - start + 1);
    }
};
int main(){
    string s = "babad";
    Solution ob;
    cout<<"Longest palindromic substring is: "<<ob.LongestPalindrome(s)<<endl;
    return 0;
};
