#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
    public:
    vector<int> ReplacewithRank(vector<int>& nums){
        int n = nums.size();

        vector<int> dupearray = nums;
        sort(dupearray.begin(), dupearray.end());

        unordered_map<int, int> rankMap;

        int rank = 1;

        for (int num : dupearray) {
            if (rankMap.find(num) == rankMap.end()) {
                rankMap[num] = rank;
                rank++;
            }
        }
        vector<int> result;
        for (int num : nums) {
            result.push_back(rankMap[num]);
        }

        return result;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 5, 8, 15, 8, 25, 9};

    vector<int> res = obj.ReplacewithRank(nums);

    for (int x : res) {
        cout << x << " ";
    }

    return 0;
}
