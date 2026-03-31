#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    void movezerostoend(vector<int> &nums){
        int n = nums.size();
        int j = -1;

        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                j = i;
                break;
            }
            else if(j == -1){
                return;
            }
        }

        for(int i = j+1; i<n; i++){
            if(nums[i] != 0){
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};

int main(){
    vector<int> nums = {0, 1, 0, 3, 12};

    Solution obj;
    obj.movezerostoend(nums);

    cout << "Array after moving zeros to the end: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
};