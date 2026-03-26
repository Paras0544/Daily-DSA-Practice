#include<iostream>
using namespace std;

class Solution {
public:
   bool isSorted(int arr[], int n){
    for(int i=1; i<n; i++){
        if(arr[i] < arr[i-1]){
            return false;
        }
    }
    return true;
   }
};
int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    Solution ob;
    if(ob.isSorted(arr,n)){
        cout<<"The array is sorted in non-decreasing order."<<endl;
    }
    else{
        cout<<"The array is not sorted in non-decreasing order."<<endl;
    }
    return 0;
};