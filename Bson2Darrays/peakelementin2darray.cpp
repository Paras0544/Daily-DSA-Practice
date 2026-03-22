#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
int peakElement(vector<vector<int>>& arr, int col){
    int n = arr.size();
    int max_value = INT_MIN;
    int index = -1;

    for(int i=0; i<n; i++){
        if(arr[i][col] > max_value){
            max_value = arr[i][col];
            index = i;
        }
    }

    return index;
}

vector<int> findPeakGrid(vector<vector<int>>& arr){
    int n = arr.size();
    int m = arr[0].size();

    int low = 0;
    int high = m-1;

    while(low<=high){
        int mid = (low+high)/2;

        int peak_row = peakElement(arr,mid);

        int left = mid - 1 >= 0 ? arr[peak_row][mid-1] : INT_MIN;
        int right = mid + 1 < m ? arr[peak_row][mid+1] : INT_MIN;

        if(arr[peak_row][mid] > left && arr[peak_row][mid] > right){
            return {peak_row, mid};
        }
        else if(arr[peak_row][mid] < left){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return {-1, -1};
}

int main() {
    vector<vector<int>> arr = {
        {1, 4, 3},
        {6, 5, 2}
    };

    Solution sol;
    vector<int> peak = sol.findPeakGrid(arr);
    cout << "Peak Element found at: [" << peak[0] << ", " << peak[1] << "]\n"; // Expected: [1, 0]

    return 0;
}};