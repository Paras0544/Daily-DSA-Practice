#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> AsteroidCollision(vector<int>& asteroid) {

        stack<int> st;

        for(int i = 0; i < asteroid.size(); i++) {

            // Positive asteroid
            if(asteroid[i] > 0) {
                st.push(asteroid[i]);
            }

            // Negative asteroid
            else {

                // Destroy smaller positive asteroids
                while(!st.empty() && st.top() > 0 &&
                      st.top() < abs(asteroid[i])) {
                    st.pop();
                }

                // Equal size -> both destroy
                if(!st.empty() && st.top() > 0 &&
                   st.top() == abs(asteroid[i])) {
                    st.pop();
                }

                // Push negative asteroid if:
                // stack empty OR top is negative
                else if(st.empty() || st.top() < 0) {
                    st.push(asteroid[i]);
                }
            }
        }

        // Convert stack to vector
        vector<int> ans(st.size());

        for(int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};

int main() {

    vector<int> asteroid = {10, 20, -10};

    Solution sol;

    vector<int> ans = sol.AsteroidCollision(asteroid);

    cout << "The state of asteroids after collisions is: ";

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}