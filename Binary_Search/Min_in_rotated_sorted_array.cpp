#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:

    int findMin(vector<int>& nums, int k){
        int n = nums.size();
        int low = 0;
        int high = n-1;

        while(low<=high){
            int mid = (low+high)/2;

            if(nums[high] <= nums[mid]){
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        return nums[low];
    }
};

int main(){
    vector<int> nums = {4,5,6,7,0,1,2};

    Solution sol;
    int minElement = sol.findMin(nums, nums.size());

    cout<<"Minimum element in the rotated sorted array: "<<minElement<<endl;

    return 0;
}