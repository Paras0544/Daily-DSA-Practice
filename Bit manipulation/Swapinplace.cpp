#include<iostream>
using namespace std;

class Solution{
public:
    void SwapXOR(int &a, int &b){
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
};

int main(){
    int a = 5, b = 10;   // initialize
    Solution obj;        // create object

    obj.SwapXOR(a, b);   // call function

    cout << a << " " << b << endl;
    return 0;
}