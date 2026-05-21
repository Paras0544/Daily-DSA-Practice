#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution{
    public:
    vector<int> NextSmallerelement(vector<int>& nums){
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n,-1); // initalized ans array with all elements as -1

        for(int i=n-1; i>=0; i--){

            while(!st.empty() && st.top() >= nums[i]){
                st.pop();
            }

            if(!st.empty()){
                ans[i] = st.top();
            }

            st.push(nums[i]);
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {1, 3, 2, 4};
    Solution sol;

    // Get result
    vector<int> ans = sol.NextSmallerelement(nums);

    // Print result
    cout << "The next smaller elements are: ";
    for (int val : ans) {
        cout << val << " ";
    }

    return 0;
}