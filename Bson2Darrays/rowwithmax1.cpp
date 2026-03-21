#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
int lowerBound(vector<int>& arr, int n, int x){
    int low = 0;
    int high = n-1;
    int ans = n;

    while(low<=high){
        int mid = (low + high)/2;

        if(arr[mid] >= x){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}
int rowwithMax1s(vector<vector<int>>& matrix, int n, int m){
    int cnt_max = 0;
    int index = -1;

    for(int i=0; i<n; i++){
        int cnt = m - lowerBound(matrix[i], m, 1);
        if(cnt > cnt_max){
            cnt_max = cnt;
            index = i;
        }
    }
}
};
int main() {
    vector<vector<int>> matrix = {
        {0, 0, 0, 1},
        {0, 1, 1, 1},
        {0, 0, 0, 0},
        {1, 1, 1, 1}
    };
    int n = matrix.size();
    int m = matrix[0].size();

    Solution sol;
    cout << sol.rowwithMax1s(matrix, n, m) << "\n"; // Expected: 3

    return 0;
}