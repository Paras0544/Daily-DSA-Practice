// recursion + backtracking + insertion
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
    public:
    void insertAtBottom(stack<int> &s, int temp){
        if(s.empty()){
            s.push(temp);
            return;
        }
        else {
            int val = s.top();
            s.pop();
            insertAtBottom(s,temp);
            s.push(val);
        }
    }
    void reverseStack(stack<int> &s){
        if(!s.empty()){
            int temp = s.top();
            s.pop();
            reverseStack(s);
            insertAtBottom(s, temp);
        }
    }
};

int main(){
    Solution sol;
    stack<int> s;
    s.push(4);
    s.push(5);
    s.push(7);
    s.push(9);
    sol.reverseStack(s);
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}