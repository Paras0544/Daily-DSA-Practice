#include<iostream>
using namespace std;

class Solution {
    public:
    bool isSorted(int arr[],int n){
        if(n == 0 || n == 1){
            return true;
        }
        for(int i=1; i<n; i++){ // here we are starting from 1 because we will compare the current element with the previous element
            if(arr[i] < arr[i-1]){ // if the current element is less than the previous element then the array is not sorted
                return false;
            }
        }
        return true;
    }
};

int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    Solution sol;

    if(sol.isSorted(arr,n)){
        cout<<"The array is sorted."<<endl;
    }
    else{
        cout<<"The array is not sorted."<<endl;
    }
}