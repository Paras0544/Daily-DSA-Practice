#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    vector<int> leadersinarray(vector<int> &nums){
        if(nums.empty()){
            return {};
        }
        int n = nums.size();
        int max = n-1;
        vector<int> leaders;
        leaders.push_back(nums[max]); 

        for(int i = n-2; i>=0; i--){
            if(nums[i] > nums[max]){
                leaders.push_back(nums[i]);
                max = i;
            }
        }
        reverse(leaders.begin(), leaders.end());  
        return leaders;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {16, 17, 4, 3, 5, 2};
    vector<int> leaders = sol.leadersinarray(nums);
    for(int leader : leaders){
        cout << leader << " ";
    }
    return 0;
}