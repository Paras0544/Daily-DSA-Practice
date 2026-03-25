#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        unordered_map<char,int> roman = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000},
        };
        for(int i=0; i<s.size()-1;i++){
            if(roman[s[i]] < roman[s[i+1]]){
                ans -= roman[s[i]];
            }
            else{
                ans += roman[s[i]];
            }
        }
        ans += roman[s.back()];
        return ans;
    }
};
int main(){
    Solution sol;
    string s = "MCMXCIV";
    cout << sol.Romantoint(s) << endl;
    return 0;
}