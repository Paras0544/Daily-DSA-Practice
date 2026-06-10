#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
    public:
    vector<int> ReplacewithRank(vector<int>& nums){
        int n = nums.size();
        vector<int> RankArray;

        for(int i=0; i<n; i++){
            unordered_set<int> smaller;

            for(int j=0; j<n; j++){
                if(nums[j] < nums[i]){
                    smaller.insert(nums[j]);
                }
            }
            int rank = smaller.size() + 1;
            RankArray.push_back(rank);
        }
        return RankArray;
    }
};

int main() {
    vector<int> arr = {20, 15, 26, 2, 98, 6};
    Solution sol;
    vector<int> result = sol.ReplacewithRank(arr);

    for (int r : result) {
        cout << r << " ";
    }
    cout << endl;
    return 0;
}