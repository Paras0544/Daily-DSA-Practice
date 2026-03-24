#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    public:
    static bool comparator(pair<char,int> p1, pair<int,char> p2){
        if(p1.first > p2.first){ // if the fz of 1 is greater put it first
            return true;
        }
        else if(p1.first < p2.first){
            return false;
        }
        return p1.second < p2.second; // if frequency is same alphabetical
    }
    public:
    vector<char> frequencysort(string s){
        pair<int,char> freq[26];

        for(int i=0; i<26;i++){
            freq[i]={0,i+'a'}; // initialize the frequency of all characters to 0
        }
        for(char ch : s){
            freq[ch-'a'].first++;
        }
        sort(freq,freq + 26,comparator);

        vector<char> ans;
        for(int i=0; i<26; i++){
            if(freq[i].first > 0) ans.push_back(freq[i].second); // if the frequency is greater than 0 push that character into ans anrray
        }
        return ans;
    }
};
int main(){
    Solution sol;
    string s= "tree";
    vector<char>result = sol.frequencysort(s);
    for(char c : result){
        cout << c << " ";
    }
    return 0;
}