#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> primeFactors(vector<int>& queries) {
        vector<vector<int>> ans;

        for(int num : queries) {
            vector<int> factors;
            for(int i = 2; i * i <= num; i++) {
                
                while(num % i == 0) {
                    factors.push_back(i);
                    num /= i;
                }
            }

            if(num > 1) {
                factors.push_back(num);
            }
            ans.push_back(factors);
        }
        return ans;
    }
};