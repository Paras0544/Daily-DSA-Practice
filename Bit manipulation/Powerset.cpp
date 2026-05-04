#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    vector<vector<int>> getpowerset(vector<int> &nums){
        int n = nums.size();
        int subset = 1 << n; //2^N
        vector<vector<int>> ans;

        for(int num = 0; num < subset; num++){
            vector<int> subset;

            for(int i=0; i<n; i++){
                if(num & (1 << i)){
                    subset.push_back(nums[i]);
                }
            }
            ans.push_back(subset);
        }
            return ans;
    }
};

int main() {
    // Input array
    vector<int> nums = {5, 7, 8};

    // Create object of Solution
    Solution obj;

    // Call function to generate subsets
    vector<vector<int>> subsets = obj.getpowerset(nums);

    // Print original input array
    cout << "Initial Input Array: ";
    for (auto num : nums) {
        cout << num << " ";
    }
    cout << endl;

    // Print all subsets
    cout << "Subsets: " << endl;
    for (auto subset : subsets) {
        cout << "[ ";
        for (auto num : subset) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}