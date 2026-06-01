#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution{
    public:
    int characterReplacement(string s, int k){
        int n = s.size();
        int left = 0, right = 0;
        int maxfreq = 0;
        int maxLen = 0;
        unordered_map<char,int> freq;

        while(right < n){
            freq[s[right] - 'A']++;

            maxfreq = max(maxfreq, freq[s[right] - 'A']);

            if((right - left + 1) - maxfreq > k){
                freq[s[left] - 'A']--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};
int main() {
    Solution sol;
    string s = "AABABBA";
    int k = 1;
    // Output: 4
    cout << sol.characterReplacement(s, k) << endl; 
    return 0;
}