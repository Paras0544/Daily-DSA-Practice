#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:

    int nextpermutation(vector<int>& nums){
        int index = -1;
        int n = nums.size();

        for(int i =0; i<n-2; i++){
            if(nums[i] < nums[i+1]){
                index = i;
            }
        }
        if(index == -1){
            reverse(nums.begin(), nums.end());
            return 0;
        }
        for(int i = n-1; i>n-1; i--){
            if(nums[index] < nums[i]){
                swap(nums[index], nums[i]);
                break;
            }
        }
        reverse(nums.begin()+index+1, nums.end());
        return 0;
    }
};

int main(){
    vector<int> nums = {1,2,3};
    Solution sol;
    sol.nextpermutation(nums);
    cout<<"The next permutation is: ";
    for(int i=0; i<nums.size(); i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}