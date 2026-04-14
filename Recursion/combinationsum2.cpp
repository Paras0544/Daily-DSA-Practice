#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void backtrack(int index, int target, vector<int> &candidates, vector<vector<int>> &ans, vector<int> &result) {
        if (target == 0) {
            ans.push_back(result);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {

            if (i > index && candidates[i] == candidates[i - 1]) continue;
            if (candidates[i] > target) break;
            result.push_back(candidates[i]);
            backtrack(i + 1, target - candidates[i], candidates, ans, result);
            result.pop_back();
        }
    }

    vector<vector<int>> findcombinations2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> result;

        backtrack(0, target, candidates, ans, result);
        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> v{10, 1, 2, 7, 6, 1, 5};

    vector<vector<int>> comb = obj.findcombinations2(v, 8);

    cout << "[ ";
    for (auto &vec : comb) {
        cout << "[ ";
        for (auto &x : vec) cout << x << " ";
        cout << "]";
    }
    cout << " ]";

    return 0;
}