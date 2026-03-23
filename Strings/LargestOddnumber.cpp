#include<iostream>
#include<string>
using namespace std;
class Solution {
    public:
    string LargestOddNumber(string& s){
        int index = -1;
        int n = s.length();
        for(int i=n-1; i>=0; i--){
            if((s[i] - '0') % 2 == 1){
                index = i;
                break;
            }
        }
    i = 0;
    while(i<=index && s[i] == '0'){
        i++;}
    return s.substr(i,index - i + 1);
    }
};
int main(){
    string s = "52";
    Solution sol;
    string result = sol.LargestOddNumber(s);
    cout << "Largest odd number: " << result << endl; // Expected: "5"
    return 0;
}