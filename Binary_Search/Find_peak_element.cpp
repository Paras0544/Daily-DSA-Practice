#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
   int findpeakelement(vector<int>& arr){
    int n = arr.size();
    int low = 0, high = n - 1;

    while(low < high){
        int mid = low + (high - low) / 2;

        if(arr[mid] < arr[mid+1]){
            low = mid + 1;
        }
        else{
            high = mid;
        }
    }
    return low;
   }
};

   int main(){
    vector<int> arr = {1, 2, 3, 1};

    Solution obj;
    int ans = obj.findpeakelement(arr);

    cout << "The peak element is: " << ans << "\n";

    return 0;
   }