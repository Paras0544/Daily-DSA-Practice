#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    vector<int> getsinglenumbers(vector<int>& nums){

        int n = nums.size();

        int XOR = 0;

        // XOR all elements
        for(int i = 0; i < n; i++){
            XOR = XOR ^ nums[i];
        }

        // Find rightmost set bit
        int rightmost = (XOR & (XOR - 1)) ^ XOR;

        int XOR1 = 0, XOR2 = 0;

        // Divide into two groups
        for(int i = 0; i < n; i++){

            if(nums[i] & rightmost){
                XOR1 = XOR1 ^ nums[i];
            }
            else{
                XOR2 = XOR2 ^ nums[i];
            }
        }

        // Return sorted order
        if(XOR1 < XOR2){
            return {XOR1, XOR2};
        }

        return {XOR2, XOR1};
    }
};

int main() {

    vector<int> nums = {1, 2, 1, 3, 5, 2};

    Solution sol;

    vector<int> ans = sol.getsinglenumbers(nums);

    cout << "The single numbers in given array are: "
         << ans[0] << " and " << ans[1];

    return 0;
}