// backtracking with a condition
#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    void backtrack(int sum, int last, vector<int>& nums, int k, vector<vector<int>>& ans){
        if(sum == 0 && nums.size() == k){
            ans.push_back(nums);
            return;
        }

        if(sum < 0 || nums.size() > k){
            return;
        }

        for(int i = last; i <= 9; i++){

            if(i<=sum){
                nums.push_back(i);
                backtrack(sum - i, i + 1, nums,k,ans);
                nums.pop_back();
            }
            else{
                return;
            }
        }
    }

    vector<vector<int>> CombinationSum3(int k,int n){
        vector<vector<int>> ans;
        vector<int> nums;
        backtrack(n,1,nums,k,ans);
        return ans;
    }
};

int main () {
    Solution obj;
    int k = 3;
    int n = 7;
    vector<vector<int>> ans = obj.CombinationSum3(k,n);
    for(auto i: ans){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}