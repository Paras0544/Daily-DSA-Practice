#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    int maxProfit(vector<int>& prices){
        int min = INT_MAX;
        int max =0;
        int n = prices.size();

        for(int i=0; i<n; i++){
            if(prices[i]<min){
                min = prices[i];
            }
            else if(prices[i]-min > max){
                max = prices[i]-min;
            }
            }
        return max;
        }
    };

int main(){
    vector<int> prices = {7,1,5,3,6,4};
    Solution sol;
    int ans = sol.maxProfit(prices);
    cout<<"The maximum profit is: "<<ans<<endl;
    return 0;
};