#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
    int maxDepth(string s){
        int p = 0;
        int ans = 0;
        for(char x:s){
            if(x=='('){
                p++;
            }
            else if(x==')'){
                p--;
            }
            ans = max(p,ans);
        }
        return ans;
    }
};

int main(){
    Solution sol;
    string s = "(1+(2*3)+((8)/4))+1";
    cout << sol.maxDepth(s) << endl;
    return 0;
}