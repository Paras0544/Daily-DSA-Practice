#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:

    int majorityelement(vector<int>& nums){

        int n = nums.size();
        int cnt = 0;
        int el;

        for(int i=0; i<n; i++) {
            if (cnt == 0) {
                cnt = 1;
                el = nums[i];
            }
            else if ( el == nums[i]){
                cnt++;
            }
            else{
                cnt--;
            }
        } 
        int cnt1 = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] == el){
                cnt1++;
            }
        }
        if(cnt1> (n/2)) {
            return el;
        }

        return -1;

    }
};
int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    
    // Create an instance of Solution class
    Solution sol;

    int ans = sol.majorityelement(nums);
    
    // Print the majority element found
    cout << "The majority element is: " << ans << endl;
    
    return 0;
}
