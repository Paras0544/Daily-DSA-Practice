#include<iostream>
#include<deque>
#include<vector>
using namespace std;

class Solution {
    public:

    vector<int> maxSlidingWindow(vector<int>& nums, int k){
        int n = nums.size();
        deque<int> dq;
        vector<int> result;

        for(int i=0; i<n; i++){

            while(!dq.empty() && dq.front() <= i - k){
                dq.pop_front();
            }

            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_front();
            }
            dq.push_back(i);

            if(i >= k - 1){
                result.push_back(nums[dq.front()]);
            }
        }
        return result;
    }
};

int main() {
    Solution obj;

    vector<int> arr = {4, 0, -1, 3, 5, 3, 6, 8};
    int k = 3;

    vector<int> ans = obj.maxSlidingWindow(arr, k);

    // Print the result
    for (int num : ans) {
        cout << num << " ";
    }

    return 0;
}