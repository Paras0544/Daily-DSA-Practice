#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:

bool canPlace(vector<int>& stalls, int cows, int d) {
    int n = stalls.size();
    int count = 1;
    int lastPos = stalls[0];

    for(int i=0; i<n; i++) {
        if(stalls[i] - lastPos >= d){
            count++;
            lastPos = stalls[i];
        }
        if(count >= cows)
        return true;
    }
    return false;
}

int aggressiveCows(vector<int>& stalls, int cows) {
    sort(stalls.begin(), stalls.end());

    int low = 1;
    int high = stalls.back() - stalls[0];
    int ans = 0;

    while(low<=high) {
        int mid = low + (high - low)/2;

        if(canPlace(stalls, cows, mid)){
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;

        }
    }
    return ans;
}
};

int main() {
    vector<int> stalls = {1, 2, 4, 8, 9};
    int cows = 3;

    Solution sol;
    cout << sol.aggressiveCows(stalls, cows) << "\n";

    return 0;
}