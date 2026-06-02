#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
    int nicesubarrays(vector<int>& nums, int k){
        return atMost(nums,k) - atMost(nums,k-1);
    }
    private:
    int atMost(vector<int>&nums, int k){
        int n = nums.size();
        if(k < 0){
            return 0;
        }
        int left = 0;
        int count = 0;
        int oddCount = 0;

        for(int right = 0; right < n; right++){
            if(nums[right] % 2 != 0){
                oddCount++;
            }
            if(oddCount > k){
                if(nums[left] % 2 != 0){
                    oddCount--;
                }
                left++;
            }
            count+= right-left + 1;
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;
    cout << sol.nicesubarrays(nums, k) << endl;
    return 0;
}