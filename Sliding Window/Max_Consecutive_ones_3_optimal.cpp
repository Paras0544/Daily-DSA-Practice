#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    public:
    int maxConsecutiveones3(vector<int>& nums, int k){
        int n = nums.size();
        int maxLen = 0;
        int left = 0;
        int zeros = 0;
        
        for(int right = 0; right < n; right++){

            if(nums[right] == 0){
                zeros++;
            }

            while(zeros > k){
                if(nums[left] == 0){
                    zeros--;
                }
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};

int main() {

    Solution sol;

    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;

    cout << sol.maxConsecutiveones3(nums, k) << endl;

    return 0;
}