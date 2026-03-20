#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    int LowerBounds(vector<int>& nums, int x, int n){ // Same for upper bound
        int low = 0;
        int high = n-1;
        int ans = n; 

        while(low<=high){
            int mid = (low+high)/2;

            if(nums[mid] >= x){ // jus > x in upper bound
                ans = mid; 
                high = mid - 1; 
            }
            else{
                low = mid + 1; 
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1,2,3,4,5,6,7,8,9};
    int target = 5;

    Solution sol;
    int result = sol.LowerBounds(nums, target, nums.size());    
    if(result != nums.size()){
        cout<<"Lower bound index: "<<result<<endl;
    }
    else{
        cout<<"No element greater than or equal to target found in the array."<<endl;
    }
};