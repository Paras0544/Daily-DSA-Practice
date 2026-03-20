#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int daysNeeded(vector<int>& weights, int capacity) {
        int days = 1;
        int currentLoad = 0;

        for (int w : weights) {
            if (currentLoad + w > capacity) {
                days++;
                currentLoad = w;
            } else {
                currentLoad += w;
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int d) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);

        while (left < right) {
            int mid = left + (right - left) / 2;

            int needed = daysNeeded(weights, mid);

            if (needed <= d) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

int main() {
 
    vector<int> weights = {5,4,5,2,3,4,5,6};


    int d = 5;


    Solution sol;

    cout << sol.shipWithinDays(weights, d) << "\n";

    return 0;
}
