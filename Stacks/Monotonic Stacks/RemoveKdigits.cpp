#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

class Solution{
    public:
    string RemoveKdigits(string nums, int k){
        int n = nums.size();
        stack<char> st;

        for(int i=0; i<n; i++){
            while(!st.empty() && st.top() > nums[i] && k > 0){
                st.pop();
                k--;
            }
            st.push(nums[i]);
        }

        if(st.empty()) return "0";

        string res = "";

        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }

        while(res.size() > 0 && res.back() == '0'){
            res.pop_back();
        }

        reverse(res.begin(),res.end());

        if(res.empty()) return "0";

        return res;
    }
};

int main() {
    string nums = "541892";
    int k = 2;
    
    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    /* Function call to find the smallest 
    possible integer after removing k digits */
    string ans = sol.RemoveKdigits(nums, k);
    
    cout << "The smallest possible integer after removing k digits is: " << ans;
    
    return 0;
}