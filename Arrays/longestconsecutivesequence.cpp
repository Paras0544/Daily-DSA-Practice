#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
    public:
    int longestconsecutive(vector<int> &nums){
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        unordered_set<int> st(nums.begin(),nums.end()); // we can use a hash set to store the elements of the array for O(1) lookups
        int longest = 1;

        for(int num : nums){
            if(st.find(num - 1) == st.end()){// we only want to start counting a sequence from the smallest number in the sequence, so we check if num - 1 is not in the set
                int currentnum = num;
                int currentlongest = 1;

                while(st.find(currentnum + 1) != st.end()){ // we keep checking for the next number in the sequence until we find a number that is not in the set
                    currentnum++;
                    currentlongest++;
                }
                longest = max(longest, currentlongest); // we update the longest sequence found so far

            }
        }
        return longest;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << sol.longestconsecutive(nums) << endl; // output: 4 (the longest consecutive sequence is [1, 2, 3, 4])
    return 0;
}