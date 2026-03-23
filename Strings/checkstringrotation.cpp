#include<iostream>
#include<string>
using namespace std;
class Solution {
    public:
    bool checkStringRotation (string& s, string& goal){
        if(s.length() != goal.length()){
            return false;
        }
        string doubledS = s + s;
        return doubledS.find(goal) != string::npos;
    }
};
int main(){
    string s = "abcde";
    string goal = "deabc";
    Solution sol;
    bool result = sol.checkStringRotation(s, goal);
    cout << "Is '" << goal << "' a rotation of '" << s << "'? " << (result ? "Yes" : "No") << endl; // Expected: "Yes"
    return 0;
}