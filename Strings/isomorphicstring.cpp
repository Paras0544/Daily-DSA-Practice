#include<iostream>
#include<string>
using namespace std;

class Solution {
    public:
    bool isomorphicString(string s, string t){
        if(s.length() != t.length()){
            return false;
        }
        int m1[256] = {0};
        int m2[256] = {0};

        int n = s.size();

        for(int i=0; i<n; i++){
            if(m1[s[i]] != m2[t[i]]){
                return false;
            }
            m1[s[i]] = i+1;
            m2[t[i]] = i+1;
            }
        }
        return true;
    };
int main(){
    string s = "egg";
    string t = "add";
    Solution sol;
    bool result = sol.isomorphicString(s, t);
    cout << "Are the strings isomorphic? " << (result ? "Yes" : "No") << endl; // Expected: "Yes"
    return 0;
}