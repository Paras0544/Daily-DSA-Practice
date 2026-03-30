#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    int Removeduplicatesinplace(vector<int>& nums){
        int n = nums.size();
        if(nums.size() == 0){
            return 0;
        }
        int i = 0;
        for(int j=1; j<n; j++){
            if(nums[i] != nums[j]){ // if the current element is not equal to the previous element, we have found a unique element  
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5};
    int newLength = sol.Removeduplicatesinplace(nums);
    cout << "New length after removing duplicates: " << newLength << endl;
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
};
