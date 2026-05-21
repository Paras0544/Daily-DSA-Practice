#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:

    vector<int> countNGEs(vector<int>& arr) {

        int n = arr.size();

        vector<int> ans(n, 0);

        for(int i = 0; i < n; i++) {

            int count = 0;

            for(int j = i + 1; j < n; j++) {

                if(arr[j] > arr[i]) {
                    count++;
                }
            }

            ans[i] = count;
        }

        return ans;
    }
};

int main() {

    vector<int> arr = {1, 3, 2, 4};

    Solution sol;

    vector<int> ans = sol.countNGEs(arr);

    for(int val : ans) {
        cout << val << " ";
    }
}