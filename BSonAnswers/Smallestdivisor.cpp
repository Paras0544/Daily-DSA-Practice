#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class smallestDivisor {
    public:
    int calculateTotal(vector<int>& nums, int divisor){
        int sum = 0;
        for(int num : nums){
            sum+= ceil((double)num/divisor);
        }
        return sum;
    }

    int findSmallestDivisor(vector<int>& nums, int threshold) {

        if(nums.size() > threshold) return -1;
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = high;


        while(low <= high){
            int mid = low + (high - low)/2;
            int total = calculateTotal(nums, mid);

            if(total <= threshold){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }

}