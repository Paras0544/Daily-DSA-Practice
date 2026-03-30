#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    void LeftRotateArray(vector<int>& nums, int k){
        int n = nums.size();
        int temp = nums[0];
        for(int i=1; i<n; i++){
            nums[i-1] = nums[i];
        }
        nums[n-1] = temp;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 1; // Number of positions to rotate
    cout << "Original array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    for (int i = 0; i < k; i++) {
        sol.LeftRotateArray(nums, k);
    }

    cout << "Array after left rotation: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
};