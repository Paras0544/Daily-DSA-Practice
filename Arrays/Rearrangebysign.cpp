#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    vector<int> Reaarrangearraybysign(vector<int>& A){
        int n = A.size();
        vector<int> ans(n,0);

        int posIndex =0;
        int negIndex = 1;

        for(int i=0; i<n; i++){
            if(A[i] > 0){
                ans[posIndex] = A[i];
                posIndex+=2;
            }
            else{
                ans[negIndex] = A[i];
                negIndex+=2;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> A = {-1,1,-2,2,-3,3};
    Solution sol;
    vector<int> ans = sol.Reaarrangearraybysign(A);
    cout<<"The rearranged array is: ";
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}