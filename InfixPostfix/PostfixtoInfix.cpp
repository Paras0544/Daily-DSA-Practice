#include<iostream>
#include<stack>
using namespace std;

string PostfixtoInfix(string Postfix){
    stack<string> s;
    int n = Postfix.size();

    for(int i=0; i<n; i++){
        char c = Postfix[i];

    if(isalnum(c)){
        s.push(string(1,c));
    }

    else{
        string op2 = s.top(); s.pop();
        string op1 = s.top(); s.pop();

        s.push("(" + op1 + c + op2 + ")");
    }
}
return s.top();
}

int main() {
    string postfix = "AB*C+";
    cout << "Infix Expression: " << PostfixtoInfix(postfix) << endl;
    return 0;
}