#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:

    int binarysearch(vector<int>& nums, int target){
        int n = nums.size();
        int low = 0;
        int high = n-1;

        while(low<=high){
            int mid = (low+high)/2;

            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return -1;    }
};

int main(){
    vector<int> nums = {1,2,3,4,5,6,7,8,9};
    int target = 5;

    Solution sol;
    int result = sol.binarysearch(nums, target);    
    if(result != -1){
        cout<<"Element found at index: "<<result<<endl;
    }
    else{
        cout<<"Element not found in the array."<<endl;
    }
};
