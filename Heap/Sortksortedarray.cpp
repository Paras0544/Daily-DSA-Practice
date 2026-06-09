#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution{
    public:

    vector<int> nearlysortedarray(vector<int>& nums, int k){
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> minHeap;
        vector<int> result;

        for(int i = 0; i <= k && i < n; i++){
            minHeap.push(nums[i]);
        }

        for(int i = k + 1; i < n; i++){
            result.push_back(minHeap.top());
            minHeap.pop();

            minHeap.push(nums[i]);
        }

        while(!minHeap.empty()){
            result.push_back(minHeap.top());
            minHeap.pop();
        }
        return result;
    }
};

int main() {
    vector<int> nums = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;

    Solution obj;
    vector<int> sortedArr = obj.nearlysortedarray(nums, k);

    for (int num : sortedArr) {
        cout << num << " ";
    }

    return 0;
}