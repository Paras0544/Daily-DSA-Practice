#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:

    int Floorfinder(vector<int>& nums, int x, int n){
        int low = 0;
        int high = n-1;
        int ans = -1;

        while(low<=high){
            int mid = (low+high)/2;

            if(nums[mid] <= x){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return ans;
    }
};

int ceilingfinder(vector<int>& nums, int x, int n){
    int low = 0;
    int high = n-1;
    int ans = n;

    while(low<=high){
        int mid = (low+high)/2;

        if(nums[mid] >= x){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {1,2,3,4,5,6,7,8,9};
    int target = 5;

    Solution sol;
    int floorIndex = sol.Floorfinder(nums, target, nums.size());
    int ceilingIndex = ceilingfinder(nums, target, nums.size());

    if(floorIndex != -1){
        cout<<"Floor index: "<<floorIndex<<endl;
    }
    else{
        cout<<"No element less than or equal to target found in the array."<<endl;
    }

    if(ceilingIndex != nums.size()){
        cout<<"Ceiling index: "<<ceilingIndex<<endl;
    }
    else{
        cout<<"No element greater than or equal to target found in the array."<<endl;
    }
}