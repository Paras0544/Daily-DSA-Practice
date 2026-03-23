#include<iostream>
#include<string>
using namespace std;
class Solution{
    public:
    bool CheckAnagram(string s, string t){
        if(s.length()!= t.length()){
            return false
        }
    
        int count[26] = {0};

       for(int i=0; i<s.length(); i++){
            count[s[i] - 'A']++;
            count[t[i] - 'A']--;
       }

       for(int i=0; i<26; i++){
        if(count[i] != 0){
            return false;
        }
       }
    return true;
    }
};
int main(){
    string s = "listen";
    string t = "silent";
    Solution sol;
    bool result = sol.CheckAnagram(s, t);
    cout << "Are the strings anagrams? " << (result ? "Yes" : "No") << endl; // Expected: "Yes"
    return 0;
}