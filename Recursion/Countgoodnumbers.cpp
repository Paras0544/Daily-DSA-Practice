#include<iostream>
#include<vector>
using namespace std;

int MOD = 1e9 + 7; // as the number of good numbers can be very large, we will take the result modulo 10^9 + 7

class Solution {
    public:
    int countGoodNumbers(int index, int n){
        if(index == n){ 
            return 1;
        }
        int result = 0;
        if(index % 2 == 0){
            for(int digit : {0, 2, 4, 6, 8}){
                result = (result+ countGoodNumbers(index + 1, n)) % MOD; // here we do index + 1 to move to the next position and we take modulo to avoid overflow
            }
        }
        else{
            for(int digit : {2, 3, 5, 7}){
            result = (result + countGoodNumbers(index + 1, n)) % MOD;
        }
    }
    return result;
    }
};

int main(){
    Solution sol;
    int n = 1;
    cout << sol.countGoodNumbers(0, n) << endl;
    return 0;
}