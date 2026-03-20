#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:

    int search(vector<int>& nums, int target){
        int low = 0;
        int high = nums.size() - 1;

        while(low < high){
            int mid = low + (high - low) / 2;

            if(nums[mid] > nums[high]){
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        return low;
    }
};

int main(){
    vector<int> nums = {4,5,6,7,0,1,2};

    Solution sol;
    int rotationCount = sol.search(nums, 0);

    cout<<"Number of rotations in the array: "<<rotationCount<<endl;

    return 0;
}