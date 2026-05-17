#include<iostream>
using namespace std;

class Solution{
    public:
    void Pattern2(int n){
        for(int i=1; i<n; i++){
            for(int j=1; j<=i; j++){ // inner loop j makes it print only the required amount of stars
                cout<< j;
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

