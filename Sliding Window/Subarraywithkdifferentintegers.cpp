#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums,k) - atMost(nums, k-1);
    }
private:
    int atMost(vector<int>& nums, int k){
        if(k < 0){
            return 0;
        }
        int n = nums.size();
        int count = 0;
        int left = 0;
        unordered_map<int,int> freq;

        for(int right = 0; right < n; right++){
            freq[nums[right]]++;

            while(freq.size() > k){
                freq[nums[left]]--;

                if(freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }
                left++;
            }
            count+= right - left + 1;
        }
        return count;
    }
};