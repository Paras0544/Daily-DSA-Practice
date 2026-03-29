#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:

int countLessEqual(vector<vector<int>>& matrix, int mid){
    return upper_bound(matrix.begin(),matrix.end(),mid) - matrix.begin();
}
int findMedian(vector<vector<int>>& matrix){
    int rows = matrix.size();
    int cols = matrix[0].size();

    int low = matrix[0][0];
    int high = matrix[0][cols-1];

    for(int i=1; i < rows; i++){
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][cols-1]);
    }

    while(low < high){
        int mid = low + (high - low) / 2;
        int count = 0;

        for(int i=0; i < rows; i++){
            count += countLessEqual(matrix[i], mid);
        }

        if(count < (rows * cols + 1) / 2){
            low = mid + 1;
        }
        else{
            high = mid;
        }
    }
    return low;
}
};
int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };

    Solution sol;
    int median = sol.findMedian(matrix);
    cout << "Median of the matrix is: " << median << "\n"; // Expected: 5

    return 0;
};