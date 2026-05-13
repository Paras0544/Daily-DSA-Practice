#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class MinStack {
    private:
    stack <int> st;
    int mini;

    public:
    MinStack(){
    }

    void push(int value){
        if(st.empty()) {
            mini = value;

            st.push(value);
            return;
        }
        if(value < mini){
            st.push(value);
        }
        else{
            st.push(2*value-mini);
            mini = value;
        }
    }

    void pop(){
        if(st.empty()){
            return;
        }
        int x = st.top();
        st.pop();

        if(x < mini){
            mini = 2 * mini - x;
        }
    }

    int top(){
        if(st.empty()){
            return -1;
        }

        int x = st.top();

        if(mini < x){
            return x;
        }
        return mini;
    }

    int getMin(){
        return mini;
    }
};

int main() {
    MinStack s;
    
    // Function calls
    s.push(-2);
    s.push(0);
    s.push(-3);
    cout << s.getMin() << " ";
    s.pop();
    cout << s.top() << " ";
    s.pop();
    cout << s.getMin();
    
    return 0;
}