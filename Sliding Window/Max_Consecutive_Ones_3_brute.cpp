#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int MaxConsecutiveones3(vector<int>& nums, int k) {

        int n = nums.size();
        int maxLen = 0;

        for(int i = 0; i < n; i++) {

            int zeros = 0;

            for(int j = i; j < n; j++) {

                if(nums[j] == 0)
                    zeros++;

                if(zeros > k)
                    break;

                maxLen = max(maxLen, j - i + 1);
            }
        }

        return maxLen;
    }
};

int main() {

    Solution sol;

    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;

    cout << sol.MaxConsecutiveones3(nums, k) << endl;

    return 0;
}