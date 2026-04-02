// Basic traversal, finding total sum upto n - sum of given array = missing number

#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    vector<int> findmissingnumber(vector<int> arr, int n){
        int sum = 0;

        for(int i = 0; i<arr.size(); i++){
            sum = sum + arr[i];
        }

        int total = n * (n + 1) / 2;
        return {total - sum};
    }
};

int main(){
    vector<int> arr = {1, 2, 4, 5, 6};
    int n = 6;

    Solution obj;
    vector<int> result = obj.findmissingnumber(arr, n);

    cout << "The missing number is: " << result[0] << endl;

    return 0;
};