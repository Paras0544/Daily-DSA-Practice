#include<iostream>
using namespace std;

class Solution {
    public:
    bool powerof2(int n){
        return n > 0 && (n & (n-1)) == 0;
    }
};

int main() {
    Solution sol;
    int num = 8;

    if (sol.powerof2(num)) {
        cout << num << " is a power of two." << endl;
    } else {
        cout << num << " is not a power of two." << endl;
    }

    return 0;
}