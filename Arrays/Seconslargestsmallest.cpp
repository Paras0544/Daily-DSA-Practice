#include<iostream>
using namespace std;
class Solution {
public:
int secondsmallest(int arr[],int n){
    if(n<2){
        return - 1;
    }
    int small = INT_MAX;
    int secondsmall = INT_MAX;

    for(int i=0; i<n; i++){
        if(arr[i] < small){
            secondsmall = small;
            small = arr[i];
        }
        else if(arr[i] < secondsmall && arr[i] != small){
            secondsmall = arr[i];
        }
    }
    return secondsmall;
}
int secondlargest(int arr[],int n){
    if(n<2){
        return -1;
    }
    int large = INT_MIN;
    int secondlarge = INT_MIN;

    for(int i=0; i<n; i++){
        if(arr[i] > large){
            secondlarge = large;
            large = arr[i];
        }
        else if(arr[i] > secondlarge && arr[i] != large){
            secondlarge = arr[i];
        }
    }
    return secondlarge;
}
};

int main(){
    int arr[] = {2,3,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    Solution ob;
    cout<<"Second smallest element is: "<<ob.secondsmallest(arr,n)<<endl;
    cout<<"Second largest element is: "<<ob.secondlargest(arr,n)<<endl;
    return 0;
};