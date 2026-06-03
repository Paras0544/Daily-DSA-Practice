// find all valid substrings containing char 'a' , 'b' and 'c'
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
    int numberofsubstring(string s){
        int n = s.size();
        int count = 0;
        int left = 0;
        vector<int> freq(3,0);

        for(int right = 0; right < n; right++){
            freq[s[right] - 'a']++;

            while(freq[0] > 0 && freq[1] > 0 && freq[2] > 0){
                count += (n-right);

                freq[s[left] - 'a']--;
                left++;
            }
        }
        return count;
    }
};

int main(){
    string s = "abcabc";
    Solution obj;
    cout << obj.numberofsubstring(s) << endl;
    return 0;
}