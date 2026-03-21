#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

class Solution {
    public:
    int countPainters(vector<int>& arr, int time){
        int n = arr.size();
        int painters = 1;
        long long boardsPainter = 0;

        for(int i=0; i<n; i++){
            if(boardsPainter + arr[i] <= time){
                boardsPainter += arr[i];
            }
            else{
                painters++;
                boardsPainter = arr[i];
            }
        }
        return painters;
    }

    int findlargestMinDistance(vector<int>& arr, int k){
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);

        int result = high;

        while(low<=high){
            int mid = low + (high - low)/2;
            int painters = countPainters(arr, mid);

            if(painters <= k){
                result = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return result;
    }

    int main() {
    vector<int> boards = {10, 20, 30, 40};
    int k = 2;

    Solution pp;
    int ans = pp.findlargestMinDistance(boards, k);
    cout << "The answer is: " << ans << "\n"; // Expected: 60
    return 0;
}};