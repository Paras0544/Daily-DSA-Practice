#include<iostream>
#include<stack>
using namespace std;

string PostfixtoPrefix(string postfix){
    int n = postfix.size();
    stack <string> s;

    for(int i=0; i<n; i++){
        char c = postfix[i];

    if(isalnum(c)){
        s.push(string(1,c));
    }

    else{
        string op2 = s.top(); s.pop();
        string op1 = s.top(); s.pop();

        s.push(c + op1 + op2);
    }
}
    return s.top();
};

int main() {
    string postfix = "ABC/-AK/L-*";
    cout << "Prefix Expression: " << PostfixtoPrefix(postfix) << endl;
    return 0;
}