#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    vector<int> getDivisor(int N){
        vector<int> res;

        for(int i=1; i*i <= N; i++){
            if(N % i == 0){
                res.push_back(i);

            if(i != N/i){
                res.push_back(N/i);
            }
            }
        }
    return res;
    }
};

int main() {
    Solution sol;
    int N = 36;
    vector<int> result = sol.getDivisor(N);
    cout << "Divisors of " << N << ": ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
