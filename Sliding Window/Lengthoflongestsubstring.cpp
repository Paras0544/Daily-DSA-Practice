#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
    public:
    int longestsubstringwithoutrepeating(string& s){
        int n = s.size();
        int l = 0;
        int r = 0;
        int maxLen = 0;
        vector<int> hash(256,-1);

        while(r < n){
            if(hash[s[r]] != -1){
                l = max(hash[s[r]] + 1, l);
            }

            int len = r - l + 1;
            maxLen = max(maxLen, len);
            hash[s[r]] = r;
            r++;
        }
        return maxLen;
        }
    };

int main() {
    string s = "cadbzabcd"; 
    
    // Create an instance of the Solution class
    Solution sol;

    int result = sol.longestsubstringwithoutrepeating(s);

    // Output the maximum length
    cout << "The maximum length is:\n";
    cout << result << endl;

    return 0;
}