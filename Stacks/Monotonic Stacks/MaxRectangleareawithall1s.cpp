#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

class Solution {
public:

    int largestRectangle(vector<int>& heights) {

        int n = heights.size();
        int maxArea = 0;
        stack<int> st;
        heights.push_back(0); // we add a 0 at the end to make sure we pop all the elements from the stack at the end

        for(int i = 0; i < n; i++) {

            while(!st.empty() && heights[i] < heights[st.top()]) {

                int height = heights[st.top()];
                st.pop();

                int width = st.empty() ? i : i - st.top() - 1;

                maxArea = max(maxArea, height * width);
            }

            st.push(i);
        }

        // IMPORTANT PART, wither add 0 at the end to prov=cess all elemenst 
        while(!st.empty()) {

            int height = heights[st.top()];
            st.pop();

            int width = st.empty() ? n : n - st.top() - 1;

            maxArea = max(maxArea, height * width);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        if(matrix.empty()) return 0;

        int m = matrix[0].size();

        vector<int> height(m, 0);

        int maxArea = 0;

        for(auto& row : matrix) {

            for(int i = 0; i < m; i++) {

                if(row[i] == '1')
                    height[i]++;
                else
                    height[i] = 0;
            }

            maxArea = max(maxArea, largestRectangle(height));
        }

        return maxArea;
    }
};

int main() {

    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };

    Solution obj;

    cout << obj.maximalRectangle(matrix) << endl;

    return 0;
}