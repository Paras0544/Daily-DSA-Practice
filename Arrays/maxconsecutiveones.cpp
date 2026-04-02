#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    vector<int> maxconsecutiveones(vector<int> nums){
        int n = nums.size();
        int cnt = 0;
        int maxi = 0;

        for(int i=0; i<n; i++){
            if(nums[i] == 1){
                cnt++;
            }
            else{
                cnt = 0;
            }
            maxi = max(maxi,cnt);
        }
        return {maxi};
    }
};

int main(){
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    Solution obj;
    vector<int> result = obj.maxconsecutiveones(nums);

    cout << "The maximum number of consecutive ones is: " << result[0] << endl;

    return 0;
};