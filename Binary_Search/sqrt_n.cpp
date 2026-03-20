#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
int mysqrt(int x){
    if(x < 2){
        return x;
    }
    int left = 1, right = x/2, ans = 0;

    while(left<=right){
        int mid = left + (right - left) / 2;

        if (mid*mid <= x){
            ans = mid;
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return ans;
}
};

int main() {
    Solution s;
    cout << s.mysqrt(8) << endl;
    return 0;
}