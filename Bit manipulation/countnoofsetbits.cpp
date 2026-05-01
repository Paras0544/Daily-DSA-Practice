#include<iostream>
using namespace std;

class Solution {
    public:
    int countsetbits(int n){
        int count = 0;

        while(n > 0){
            n &= (n-1);
            count++;
        }
        return count;
    }
};

int main() {
    int n = 29;  // Example input for n (binary: 11101)

    Solution sol;
    int result = sol.countsetbits(n);

    cout << "The number of set bits is: " << result << endl;

    return 0;
}