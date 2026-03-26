#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
    public:
    int atmostKdistinct(string s, int k){
        int left = 0, res = 0;
        unordered_map<char,int> freq;

        for(int right = 0; right < s.size(); right++){
            freq[s[right]]++;

            while(freq.size() > k){
                freq[s[left]]--;
                if(freq[s[left]] == 0){
                    freq.erase(s[left]);
                }
                left++;
            }
            res += (right - left + 1);
        }
        return res;
    }
};

int main(){
    string s = "abcba";
    int k = 2;
    Solution ob;
    cout<<"Number of substrings with at most "<<k<<" distinct characters is: "<<ob.atmostKdistinct(s,k)<<endl;
    return 0;
};