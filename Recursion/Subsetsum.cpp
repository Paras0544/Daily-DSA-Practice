#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
     void findsum(int index,int currsum, vector<int> &nums, vector<int> &result){
        int n = nums.size();
        if(index == n){
            result.push_back(currsum);
            return;
        }
        findsum(index+1, currsum + nums[index], nums, result);

        findsum(index+1,currsum,nums,result);


        }

        vector<int> subsetsum(vector<int> &nums){
            vector<int> result;
            findsum(0,0,nums,result);
            sort(result.begin(),result.end());
            return result;
        }
        
    };

    int main() {
    Solution sol;
    vector<int> nums = {5, 2, 1};
    vector<int> finalresult = sol.subsetsum(nums);

    for (int sum : finalresult) {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}
