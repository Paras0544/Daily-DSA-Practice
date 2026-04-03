#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
    public:
    int LongestSubarray(vector<int> nums, int k){
        int n = nums.size();
        int left = 0, right = 0;
        int sum = nums[0];
        int maxLength = 0;

        while(right < n){
            while(sum > k && left <=right){
                sum = sum - nums[left];
                left++;
            }
            if(sum == k){
                maxLength = max(maxLength, right - left + 1);
            }
            right++;

            if(right < n){
                sum = sum + nums[right];
            }
        }
        return maxLength;
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