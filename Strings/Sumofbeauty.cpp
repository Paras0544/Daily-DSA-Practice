#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
int SumofBeauty(string s){
    int n = s.size();
    int sum = 0;

    for(int i=0; i<n; i++){ // outer loop to fix the starting point of the substring
        unordered_map<char,int> freq; // to store the frequency of characters in the current substring

        for(int j=i; j<n; j++){ // inner loop to fix the ending point of the substring
            freq[s[j]]++; // increment the frequency of the current character

            int mini = INT_MAX;
            int maxi = INT_MIN;

            for(auto it:freq){// it is the freq pair of character and its frequency
                mini = min(mini, it.second); // second in it is the frequency of the character
                maxi = max(maxi, it.second);
            }
            sum += (maxi - mini);
        }
    }
    return sum;
}
};

int main(){
    string s = "aabcb";
    Solution ob;
    cout<<"The sum of beauty of all substrings is: "<<ob.SumofBeauty(s)<<endl;
    return 0;
};