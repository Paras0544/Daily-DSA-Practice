#include<iostream>
using namespace std;

class Solution {
    public:
    int setrightmostbit(int n){
        return n | (n + 1);
    }
};

int main(){
    int n = 10;
    Solution obj;
    int result = obj.setrightmostbit(n);
    cout << result << endl;
    return 0;
}