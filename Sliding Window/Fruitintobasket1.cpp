#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution{
    public:
    int Fruitintobasket(vector<int>& fruits){
        int n = fruits.size();
        unordered_map<int,int> basket;
        int maxLen = 0;
        int left = 0;

        for(int right = 0; right < n; right++){
            basket[fruits[right]]++;

            while(basket.size() > 2){
                basket[fruits[left]]--;

                if(basket[fruits[left]] == 0){
                    basket.erase(fruits[left]);
                }
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};

int main(){
    vector<int> fruits = {1,2,2,1,3};
    Solution obj;
    cout<< obj.Fruitintobasket(fruits) << endl;
    return 0;
}