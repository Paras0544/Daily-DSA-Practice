#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    int linearsearch(vector<int> &nums, int k){
        int n = nums.size();

        for(int i=0;i<n;i++){
            if(nums[i] == k){
                return i;
            }
        }
        return -1;
    }
};

int main(){
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 3;

    Solution obj;
    int index = obj.linearsearch(nums, k);

    if (index != -1) {
        cout << "Element " << k << " found at index: " << index << endl;
    } else {
        cout << "Element " << k << " not found in the array." << endl;
    }

    return 0;
};