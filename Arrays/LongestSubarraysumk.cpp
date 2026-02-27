#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int LongestSubarray(vector<int>& nums, int k){
        int n = nums.size();
        int left = 0;
        int right = 0;

        int maxLen = 0;
        int sum = nums[0];

        while (right < n){

            while(left <= right && sum > k){
                sum -= nums[left];
                left++;
            }

            if(sum == k){
                maxLen = max(maxLen, (right - left + 1));
            }

            right++;

            if(right < n){
                sum += nums[right];
            }
        }
        return maxLen;
    }
};

int main (){

    vector<int> nums ={5,5,5,0,1};
    int k = 15;

    Solution sol;

    int ans = sol.LongestSubarray(nums,k);

    cout << "The Length of the Longest subarray is " << ans ;

    return 0;
}