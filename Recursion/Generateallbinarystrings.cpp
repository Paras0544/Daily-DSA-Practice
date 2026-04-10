// recursion + backtracking with conditions to avoid consecutive 1s in binary strings of length n
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution{
    public:
    void binarystrings(int n, string curr, vector<string> &result){
        if(curr.size() == n){
            result.push_back(curr);
            return;
        }
        binarystrings(n,curr + "0", result);

        if(curr.empty() || curr.back() != '1'){ // condition to avoid consecutive 1s
            binarystrings(n,curr + "1", result);
        }
    }
};

int main(){
    Solution sol;
    int n = 3;
    vector<string> result;
    sol.binarystrings(n, "", result);
    for(string s : result){
        cout << s << endl;
    }
    return 0;
}