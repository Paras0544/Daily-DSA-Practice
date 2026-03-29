#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    int LargestElement(int arr[], int n){
        int max = arr[0];

        for(int i=0; i<n; i++){
            if(arr[i] > max){
                max = arr[i];
            }
        }
        return max;
    }
};

int main(){
    int arr[] = {2,7,8,9,6,4};
    int n = 6;
    Solution sol;

    cout<<"the largest element in the arrays is:"<<sol.LargestElement(arr,n)<<endl;
    return 0;
}