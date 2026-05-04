#include<iostream>
using namespace std;

class Solution {
    public:
    int minimumbitsflipped(int start, int goal){
        int num = start ^ goal;
        int count = 0;

        for(int i=0; i<32; i++){
            count += (num & 1);
            num = num >> 1;
        }
        return count;
    }
};

int main(){
    int start = 10;
    int goal = 7;
    Solution obj;

    int ans = obj.minimumbitsflipped(start,goal);

    cout<< ans << endl;


    return 0;
}