#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
    public:
    string LongestCommonPrefix(vector<string>& str){
        string ans = "";
        if(str.empty()){
            return ans;
        }
        sort(str.begin(), str.end());
        string first = str[0];
        string Last = str[str.size()-1];

        int minLength = min(first.size(), Last.size());

        for(int i = 0; i<minLength; i++){
            if(first[i] != Last[i]){
                break;
            }
            ans += first[i];
        }
        return ans;
    }
};
int main(){
    vector<string> str = {"flower", "flow", "flight"};
    Solution sol;
    string result = sol.LongestCommonPrefix(str);
    cout << "Longest common prefix: " << result << endl; // Expected: "fl"
    return 0;
}