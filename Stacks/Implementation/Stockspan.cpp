#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution{
    private:
    vector<int> findPGE(vector<int>& nums){
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n);

        for(int i=0; i<n; i++){

            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    public:
    vector<int> StockSpan(vector<int> nums, int n){
        vector<int> PGE = findPGE(nums);
        vector<int> ans(n);

        for(int i=0; i < n; i++){
            ans[i] = i - PGE[i];
        }
        return ans;
    }
};

int main() {
    int n = 7;
    vector<int> arr = {120, 100, 60, 80, 90, 110, 115};
    
    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    /* Function call to find the span 
    of stock prices for each day */
    vector<int> ans = sol.StockSpan(arr, n);
    
    cout << "The span of stock prices is: ";
    for(int i=0; i < n; i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}