#include<iostream>
#include<string>
using namespace std;

class Solution {
    private:

    double power(double x, long long n){ // here we take long  long n because we need to handle the case when n is INT_MIN, which is -2^31, and if we take int n, then -n will overflow and become 2^31, which is out of range for int
        if(n == 0){
            return 1.0;
        }
        if(n == 1){
            return x;
        }
        if(n % 2 == 0){
            return power(x*x, n/2); // if n is even, we can calculate x^n as (x^2)^(n/2)
        }
        else{
            return x*power(x*x, n/2); // if n is odd, we can calculate x^n as x * (x^2)^(n/2)
        }
        return x*power(x*x, n/2);
    }

    public:
    double myPow(double x, int n){
        int num = n;

        if(n < 0){
            return 1/power(x, -num); // if n is negative, we can calculate x^n as 1/(x^-n)
        }
        return power(x, num);
}
};

int main(){
    Solution sol;
    double x = 2;
    int n = 2;
    cout << sol.myPow(x, n) << endl;
    return 0;
}
