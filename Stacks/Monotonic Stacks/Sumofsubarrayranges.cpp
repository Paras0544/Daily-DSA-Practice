#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

class Solution {
    private:
    vector<int> findNSE(vector<int>& nums){
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n);

        for(int i=n-1; i >=0; i--){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }
        return ans;
    }
        vector<int> findNGE(vector<int>& nums){
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n);

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }
        return ans;
    }

    vector<int> findPSEE(vector<int>& nums){
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n);

        for(int i=0; i<n; i++){
            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }
        return ans;
    }

        vector<int> findPGEE(vector<int>& nums){
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n);

        for(int i=0; i<n; i++){
            while(!st.empty() && nums[st.top()] < nums[i]){
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }
        return ans;
    }

    long long sumSubarraymin(vector<int>& nums){
        int n = nums.size();

        vector<int> nse = findNSE(nums);
        vector<int> psee = findPSEE(nums);

        long long sum = 0;

        for(int i=0; i<n; i++){
            int left = i - psee[i];
            int right = nse[i] - i;

            long long freq = left*right*1LL;
            long long val = (freq*nums[i]*1LL);

            sum += val;
        }
        return sum;
    }


long long sumSubarraymax(vector<int>& nums){
        int n = nums.size();

        vector<int> nge = findNGE(nums);
        vector<int> pgee = findPGEE(nums);

        long long sum = 0;

        for(int i=0; i<n; i++){
            int left = i - pgee[i];
            int right = nge[i] - i;

            long long freq = left*right*1LL;
            long long val = (freq*nums[i]*1LL);

            sum += val;
        }
      return sum;
}

public:
long long subArrayRanges(vector<int> &nums){
    return (sumSubarraymax(nums)- sumSubarraymin(nums));
}

};

int main() {
    vector<int> arr = {1, 2, 3};
    
    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    /* Function call to find the sum of 
    subarray ranges in each subarray */
    long long ans = sol.subArrayRanges(arr);
    
    cout << "The sum of subarray ranges is: " << ans;
    
    return 0;
}

