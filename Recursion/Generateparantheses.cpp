// recursion + backtracking with conditions
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
    public:
    void generateparantheses(string curr, int n, int open, int close, vector<string> &result){
        if(curr.size() == 2*n){
            result.push_back(curr);
            return;
        }
        if(open < n){
            generateparantheses(curr + "(", n, open +1, close, result);
        }
        if(close < open){
            generateparantheses(curr + ")", n, open, close + 1, result);
        }
    }

    vector<string> generate(int n){
        vector<string> result;
        generateparantheses("", n, 0, 0, result);
        return result;
    }
};

int main(){
    Solution sol;
    int n = 3;
    vector<string> result = sol.generate(n);
    for(string s : result){
        cout << s << endl;
    }
    return 0;
}