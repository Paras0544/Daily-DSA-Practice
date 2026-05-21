#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
private:

    // Next Smaller Element
    vector<int> findNSE(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);

        for(int i = n-1; i >= 0; i--) {

            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            ans[i] = !st.empty() ? st.top() : n;

            st.push(i);
        }

        return ans;
    }

    // Previous Smaller or Equal Element
    vector<int> findPSEE(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);

        for(int i = 0; i < n; i++) {

            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            ans[i] = !st.empty() ? st.top() : -1;

            st.push(i);
        }

        return ans;
    }

public:

    int sumSubarrayMins(vector<int>& arr) {

        int n = arr.size();
        int mod = 1e9 + 7;

        vector<int> nse = findNSE(arr);
        vector<int> psee = findPSEE(arr);

        long long sum = 0;

        for(int i = 0; i < n; i++) {

            long long left = i - psee[i];
            long long right = nse[i] - i;

            long long freq = left * right;

            long long val = (freq * arr[i]) % mod;

            sum = (sum + val) % mod;
        }

        return sum;
    }
};

int main() {

    vector<int> arr = {3, 1, 2, 5};

    Solution sol;

    int ans = sol.sumSubarrayMins(arr);

    cout << "The sum of minimum value in each subarray is: " << ans;

    return 0;
}