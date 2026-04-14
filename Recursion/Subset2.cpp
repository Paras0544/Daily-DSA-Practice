// push all subsets into result without duplicates but array can contain duplicates

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
    void backtrack(int index, vector<int> &nums, vector<int> &curr, vector<vector<int>> &result){
        result.push_back(curr);

        for(int i = index; i<nums.size(); i++){
            if(i > index && nums[i] == nums[i-1]) continue;

            curr.push_back(nums[i]);
            backtrack(i+1,nums,curr,result);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsetwithduplicates(vector<int> &nums){
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        vector<int> curr;
        backtrack(0,nums,curr,result);
        return result;
    }
};

int main() {
    Solution obj;
    vector<int> v {1, 2, 2};  // Input array with duplicates
    vector<vector<int>> ans = obj.subsetwithduplicates(v);  // Get all subsets without duplicates

    cout << "Subsets are: " << endl;
    for (const auto &subset : ans) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";  // Print each element of the subset
        }
        cout << "]" << endl;  // Print a newline after each subset
    }
    return 0;
}