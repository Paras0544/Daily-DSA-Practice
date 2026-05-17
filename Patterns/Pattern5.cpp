#include<iostream>
using namespace std;

class Solution{
    public:
    void Pattern5(int n){
        for(int i=0; i<n; i++){
            for(int j=n; j>i; j--){
                cout <<"*";
            }
        cout<<endl;
        }
    }
};
int main(){
    int n = 7;
    Solution obj;
    obj.Pattern5(n);
    return 0;
}
