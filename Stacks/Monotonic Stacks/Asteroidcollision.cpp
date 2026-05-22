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

            if(asteroid[i] > 0) {
                st.push(asteroid[i]);
            }
            else {
                while(!st.empty() && st.top() > 0 &&
                      st.top() < abs(asteroid[i])) {
                    st.pop();
                }

                if(!st.empty() && st.top() > 0 &&
                   st.top() == abs(asteroid[i])) {
                    st.pop();
                }
                else if(st.empty() || st.top() < 0) {
                    st.push(asteroid[i]);
                }
            }
        }

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