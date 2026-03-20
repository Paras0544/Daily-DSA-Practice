#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:

    int firstOccurence(vector<int>& nums, int k, int n){
        int low = 0;
        int high = n-1;
        int first = -1;

        while(low<=high){
            int mid = (low+high)/2;

            if(nums[mid] == k){
                first = mid;
                high = mid - 1;
            }
            else if(nums[mid] < k){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return first;
    }

    int lastOccurence(vector<int>& nums, int k, int n){
        int low = 0;
        int high = n-1;
        int last = -1;

        while(low<=high){
            int mid = (low+high)/2;

            if(nums[mid] == k){
                last = mid;
                low = mid + 1;
            }
            else if(nums[mid] < k){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return last;
    }

    int countOccurrences(vector<int>& nums, int k, int n){
        int first = firstOccurence(nums, k, n);
        if(first == -1) return 0;
        int last = lastOccurence(nums, k, n);
        return last - first + 1;
    }
};

pair<int, int> findFirstAndLast(vector<int>& nums, int k) {
    Solution sol;
    int first = sol.firstOccurence(nums, k, nums.size());
    int last = sol.lastOccurence(nums, k, nums.size());
    return {first, last};
};

int main() {
    vector<int> nums = {1, 2, 2, 3, 4, 4, 4, 5};
    int target = 4;

    pair<int, int> result = findFirstAndLast(nums, target);
    cout << "First Occurrence: " << result.first << endl;
    cout << "Last Occurrence: " << result.second << endl;

    return 0;
};