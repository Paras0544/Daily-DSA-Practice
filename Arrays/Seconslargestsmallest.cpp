#include<iostream>
using namespace std;

class Solution{
    public:
    int SecondSmallest(int arr[], int n){
        if(n < 2){
            return -1;
        }

        int smallest = INT_MAX;
        int secondsmallest = INT_MAX;

        for(int i=0; i<n; i++){
            if(arr[i] < smallest){
                secondsmallest = smallest;
                smallest = arr[i];
            }
            else if(arr[i] < secondsmallest && arr[i] > smallest){
                secondsmallest = arr[i];
            }
        }
        return secondsmallest;
    }

    int SecondLargest(int arr[], int n){
        if(n<2){
            return -1;
        }
        int largest = INT_MIN;
        int secondlargest = INT_MIN;

        for(int i=0; i<n; i++){
            if(arr[i] > largest){
                secondlargest = largest;
                largest = arr[i];
            }
            else if(arr[i] > secondlargest && arr[i] < largest){
                secondlargest = arr[i];
            }
        }
        return secondlargest;
    }
};

int main(){
    int arr[] = {2,7,8,9,6,4};
    int n = 6;
    Solution sol;

    cout<<"the second smallest element in the arrays is:"<<sol.SecondSmallest(arr,n)<<endl;
    cout<<"the second largest element in the arrays is:"<<sol.SecondLargest(arr,n)<<endl;
    return 0;
}


