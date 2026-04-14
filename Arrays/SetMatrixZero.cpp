#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
    void setZeroes(vector<vector<int>> &matrix){
        int m = matrix.size();
        int n = matrix[0].size();

        bool firstrowzero = 0;
        bool firstcolzero = 0;

        for(int j=0; j<n; j++){
            if(matrix[0][j] == 0){
                firstrowzero = true;
            }
        }

        for(int i=0; i<m; i++){
            if(matrix[i][0] == 0){
                firstcolzero = true;
            }
        }

        for(int j=1; j<n; j++){
            for(int i=1; i<m;i++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for(int j=1; j<n; j++){
            for(int i=1; i<m; i++){
                if(matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        if(firstrowzero){
            for(int j=0; j<n; j++){
                matrix[0][j] = 0;
            }
        }

        if(firstcolzero){
            for(int i=0; i<m; i++){
                matrix[i][0] = 0;
            }
        }
    }
};

int main() {
    Solution obj;
    vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    obj.setZeroes(matrix);
    for (auto row : matrix) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}