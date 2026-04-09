// sorting a stack recursively without using any extra space, recursion + backtracking + insertion
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
    public:
    void insert(stack<int> &s, int temp) { // helper function to insert an element in the sorted stack
        if(s.empty() || s.top() <= temp){
            s.push(temp);
            return;
        }
        else{
            int val = s.top();
            s.pop();
            insert(s, temp);
            s.push(val);
        }
    }
    void sortStack(stack<int> &s){
        if(!s.empty()){ // here we are doing recursion until the stack is empty and then we will insert the elements back in sorted order
            int temp = s.top();
            s.pop();
            sortStack(s);
            insert(s, temp);
        }
    }
};

int main(){
    Solution sol;
    stack<int> s;
    s.push(3);
    s.push(1);
    s.push(4);
    s.push(2);
    sol.sortStack(s);
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}