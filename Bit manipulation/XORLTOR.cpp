#include<iostream>
using namespace std;

class Solution{
    private:
    int XORtillN(int n){ // XOR N % 4 cycle repeating
        if (n % 4 == 1) return 1;
        if (n % 4 == 2) return n+1;
        if (n % 4 == 3) return 0;
        return n; 
    }
    public:
    int findRange(int l, int r){
        return XORtillN(l-1) ^ XORtillN(r);
    }
};

int main() {
    int l = 3, r = 5;
    Solution sol; 
    int ans = sol.findRange(l, r);
    cout << "The XOR of numbers from " << l << " to " << r << " is: " << ans;
    return 0;
}