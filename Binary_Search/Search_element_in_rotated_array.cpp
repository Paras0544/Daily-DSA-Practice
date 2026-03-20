#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:

    int search(vector<int>& arr, int k , int n){
        int low = 0;
        int high = n-1;

        while(low<=high){
            int mid = (low+high)/2;

            if(arr[mid] == k){
                return mid;
            }
            else if(arr[low] <= arr[mid]){
                if(k >= arr[low] && k < arr[mid]){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            else{
                if(k > arr[mid] && k <= arr[high]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
                
            }
        }
        return -1;  
    }
};

int main(){
    vector<int> arr = {4,5,6,7,0,1,2};
    int target = 0;

    Solution sol;
    int index = sol.search(arr, target, arr.size());

    if(index != -1){
        cout<<"Element found at index: "<<index<<endl;
    }
    else{
        cout<<"Element not found in the array."<<endl;
    }

    return 0;
}