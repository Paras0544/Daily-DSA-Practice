#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    int numberappearingonce(vector<int> &arr){
        int n = arr.size();
        int xorr = 0;

        for(int i=0; i<n; i++){
            xorr = xorr ^ arr[i];
        }
        return xorr;
    }
};

int main(){
    vector<int> arr = {1,2,1};
    Solution obj;
    int ans = obj.numberappearingonce(arr);
    cout << ans << endl;
    return 0;
}