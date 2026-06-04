// find the longest substring length where there are at most k distinct charachters
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
using namespace std;

class Solution{
    public:
    int longestsubstringwithatmostk(string s, int k){
        int n = s.size();
        int left = 0;
        unordered_map<char,int> freq;
        int ans = 0;

        for(int right = 0; right < n; right++){
            freq[s[right]]++;

            while(freq.size() > k){
                freq[s[left]]--;

                if(freq[s[left]] == 0){
                    freq.erase(s[left]);
                }
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

int main(){
    string s = "aababbcaacc";
    int k = 2;
    Solution obj;
    cout << obj.longestsubstringwithatmostk(s,k) << endl;
    return 0;
}