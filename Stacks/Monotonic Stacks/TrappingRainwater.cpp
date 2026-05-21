#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int Trappedwater(vector<int>& height) {

        int n = height.size();

        int left = 0;
        int right = n - 1;

        int maxLeft = 0;
        int maxRight = 0;

        int totalwater = 0;

        while(left <= right) {

            if(height[left] <= height[right]) {

                if(height[left] >= maxLeft) {
                    maxLeft = height[left];
                }
                else {
                    totalwater += maxLeft - height[left];
                }

                left++;
            }

            else {

                if(height[right] >= maxRight) {
                    maxRight = height[right];
                }
                else {
                    totalwater += maxRight - height[right];
                }

                right--;
            }
        }

        return totalwater;
    }
};

int main() {

    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    Solution sol;

    int result = sol.Trappedwater(height);

    cout << "Trapped Rainwater: " << result << endl;

    return 0;
}