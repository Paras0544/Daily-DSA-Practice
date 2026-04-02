// xor operation of a number with itself is 0 and xor operation of a number with 0 is the number itself

#include<iostream>
#include<vector>    
using namespace std;

class Solution{
    public:
    vector<int> findnumberappearingonce(vector<int> nums){
        int n = nums.size();
        int xorr = 0;

        for(int i=0; i<n; i++){
            xorr = xorr^nums[i]; // same numbers will cancel out each other and we will be left with the xor of the two unique numbers
        }
        return {xorr};
    }
};
int main(){
    vector<int> nums = {2, 2, 3, 4, 4};
    Solution obj;
    vector<int> result = obj.findnumberappearingonce(nums);

    cout << "The number appearing once is: " << result[0] << endl;

    return 0;
};