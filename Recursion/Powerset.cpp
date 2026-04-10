#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    void Powerset(string &s, int index, string curr, vector<string> &result){
        if(index == s.size()){
            result.push_back(curr);
            return;
        }

        Powerset(s, index + 1, curr, result); // we can choose to not include the current character in the subset

        curr.push_back(s[index]); // we can choose to include the current character in the subset
        Powerset(s, index + 1, curr, result);
        curr.pop_back(); // backtrack to explore other subsets
    }
    public:
        vector<string> generate(string s){
            vector<string> result;
            Powerset(s, 0, "", result);
            return result;
        }
};

int main(){
    Solution sol;
    string s = "abc";
    vector<string> result = sol.generate(s);
    for(string subset : result){
        cout << subset << endl;
    }
    return 0;
}