#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:

    void sortzeroonetwo(vector<int>& nums){

        int low =0;
        int mid = 0;
        int high = nums.size()-1;

        while ( mid <= high){
            if(nums[mid]==0){
                swap(nums[mid], nums[low]);
                mid++;
                low++;
            }

            else if (nums[mid] == 1){
                mid++;
            }

            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

int main(){
    Solution obj;
    vector<int> nums = {2,0,1,2,0,1};

    obj.sortzeroonetwo(nums);

    for (int val : nums) 
    cout << val << " ";

    return 0;

}