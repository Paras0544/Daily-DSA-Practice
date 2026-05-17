#include<iostream>
using namespace std;

class Solution{
    public:
    void Pattern2(int n){
        for(int i=0; i<n; i++){
            for(int j=0; j<=i; j++){ // inner loop j makes it print only the required amount of stars
                cout<<i;
            }
            cout << endl;
        }
    }
};

int main(){
    int n = 7;
    Solution obj;
    obj.Pattern2(n);
    return 0;
}

