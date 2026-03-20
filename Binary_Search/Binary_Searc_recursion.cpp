#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:

    int binarySearchrecusrsion(vector<int> & nums, int target, int low, int high){
        if(low > high){
            return -1;
        }

        int mid =(low + high)/2;
        if(nums[mid] == target){
            return mid;
        }
        else if (nums[mid] > target){
            high = mid -1;
        }
        else{
            low = mid + 1;
        }
        return binarySearchrecusrsion(nums, target, low, high);
    }
};

int main(){
    vector<int> nums = {1,2,3,4,5,6,7,8,9};
    int target = 5;

    Solution sol;
    int result = sol.binarySearchrecusrsion(nums, target, 0, nums.size()-1);    
    if(result != -1){
        cout<<"Element found at index: "<<result<<endl;
    }
    else{
        cout<<"Element not found in the array."<<endl;
    }
};