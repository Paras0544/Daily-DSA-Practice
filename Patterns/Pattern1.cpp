#include<iostream>
using namespace std;

class Solution{
    public:
    void Pattern1(int n){
        for(int i=0; i<n; i++) { // no of rows
            for(int j=0; j<n; j++){
                cout<<"*";
            }
            cout<<endl;
        }
    }
};

int main(){
    int n = 7;
    Solution obj;
    obj.Pattern1(n);
    return 0;
}