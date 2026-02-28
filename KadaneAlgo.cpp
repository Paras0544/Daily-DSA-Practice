#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:

    int maxSubarray(vector<int>& nums){
        int max = INT_MIN;
        int sum = 0;
        int n = nums.size();

        for(int i =0; i<n; i++){
            sum+= nums[i];

            if(sum>max){
                max = sum;
            }
            if(sum < 0){
                sum =0;
            }
        }
        return max;
    }
};

int main(){
    vector<int> nums ={-2,1,-3,4,-1,2,1,-5,4};
    Solution sol;

    int ans = sol.maxSubarray(nums);
    cout<<"The maximum subarray sum is: "<<ans<<endl;
    return 0;
}