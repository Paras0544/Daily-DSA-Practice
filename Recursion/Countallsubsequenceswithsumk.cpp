#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution{
    public:
    void func(vector<int> &nums, int k, int index, int sum, int &count){
        if(index == nums.size()){
            if(sum == k){
                count++;
            }
            return;
        }

        // Exclude the current element
        func(nums, k, index + 1, sum, count);

        // Include the current element
        func(nums, k, index + 1, sum + nums[index], count);
    }
    void countSubsequencesWithSumK(vector<int> &nums, int k){
        int count = 0;
        func(nums, k, 0, 0, count);
        cout << count << endl;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {4,9,2,5,1};
    int k = 10;
    sol.countSubsequencesWithSumK(nums, k);
    return 0;
}
