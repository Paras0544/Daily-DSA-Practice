#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;

class Solution {
    public:
    void backtrack(int index, int target,vector<int> &nums,vector<vector<int>> &ans, vector<int> &result){ 
        int n = nums.size();

        if(index == n){
            if(target == 0){
                ans.push_back(result);
            }
            return;
        }

        if(nums[index] <= target){
            result.push_back(nums[index]);
            backtrack(index, target - nums[index], nums, ans, result);
            result.pop_back();
        }
        backtrack(index + 1, target, nums, ans, result);
    }


    public:
    vector<vector<int>> findcombination(vector<int> &candidates, int target){
        vector<vector<int>> ans;
        vector<int> result;
        backtrack(0,target,candidates,ans,result);
        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> v {2, 3, 6, 7};  // Candidate numbers
    int target = 7;  // Target sum
    // Get all combinations
    vector<vector<int>> ans = obj.findcombination(v, target);
    // Output the combinations
    cout << "Combinations are: " << endl;
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";  // Print each element of the combination
        }
        cout << endl;  // Print a newline after each combination
    }
    return 0;
}