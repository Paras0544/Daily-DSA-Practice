#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:

    string twoSumExists(vector<int> arr, int target){
        int n = arr.size();

        vector<pair<int, int>> numsWithIndex;
        for(int i = 0; i < n; i++){
            numsWithIndex.push_back({arr[i], i});
        }

        sort(numsWithIndex.begin(), numsWithIndex.end());

        int left = 0;
        int right = n - 1;

        while(left < right){
            int sum = numsWithIndex[left].first + numsWithIndex[right].first;

            if(sum == target){
                return "true";
            }
            else if(sum < target){
                left++;
            }
            else{
                right--;
            }
        }
        return "NO";
    }    
};

int main(){

    vector<int> arr = {2,6,5,8,11};
    int target = 14;

    Solution sol;

    cout<< sol.twoSumExists(arr,target) << endl;

    return 0;
}