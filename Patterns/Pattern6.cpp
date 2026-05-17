#include<iostream>
using namespace std;

class Solution{
    public:
    void Pattern5(int n){
        for(int i=0; i<n; i++){
            for(int j=n; j>i; j--){
                cout <<n-j+1;
            }
        cout<<endl;
        }
    }
};
int main(){
    int n = 5;
    Solution obj;
    obj.Pattern5(n);
    return 0;
}
