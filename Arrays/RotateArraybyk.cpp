#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    void ReverseArray(vector<int>& nums, int start, int end){
        while(start < end){
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
    }

    vector<int> RotateArraybyk(vector<int>& nums, int k,string direction){
        int n = nums.size();

        if(n == 0 || k == 0){
            return nums; // No rotation needed
        }
        k = k % n; // In case k is greater than n

        if(direction == "right"){
            ReverseArray(nums, 0, n-1);// Reverse the entire array
            ReverseArray(nums, 0, k-1);// Reverse the first k elements
            ReverseArray(nums, k, n-1);// Reverse the remaining n-k elements
        }
        else if(direction == "left"){
            ReverseArray(nums, 0, k-1);// Reverse the first k elements
            ReverseArray(nums, k, n-1);// Reverse the remaining n-k elements
            ReverseArray(nums, 0, n-1);// Reverse the entire array
        }
        return nums;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 2; // Number of positions to rotate
    string direction = "right"; // Direction of rotation

    cout << "Original array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> rotatedArray = sol.RotateArraybyk(nums, k, direction);

    cout << "Array after " << direction << " rotation: ";
    for (int num : rotatedArray) {
        cout << num << " ";
    }
    cout << endl;
};