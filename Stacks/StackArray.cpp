#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class ArrayStack { // implementing stack with arrays
    private:
    int * stackArray;
    int capacity;
    int topIndex;

    public:
    //Constructor
    ArrayStack(int size = 1000){
        capacity = size;
        stackArray = new int[capacity];
        topIndex = -1;
    }
    //Destructor
    ~ArrayStack(){
        delete[] stackArray;
    }
    // push operation
    void push(int x){
        if(topIndex >= capacity - 1){
            cout << "Stack overflow" << endl;
            return;
        }
        stackArray[++topIndex] = x;
    }
    // pop operation
    int pop(){
        if(isEmpty()){
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return stackArray[topIndex--];
    }
    //returns top element
    int top(){
        if(isEmpty()){
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return stackArray[topIndex];
    }
    bool isEmpty(){
        return topIndex == -1;
    }
};

int main() {
    ArrayStack stack;
    vector<string> commands = {"ArrayStack", "push", "push", "top", "pop", "isEmpty"};
    vector<vector<int>> inputs = {{}, {5}, {10}, {}, {}, {}};

    for (size_t i = 0; i < commands.size(); ++i) {
        if (commands[i] == "push") {
            stack.push(inputs[i][0]);
            cout << "null ";
        } else if (commands[i] == "pop") {
            cout << stack.pop() << " ";
        } else if (commands[i] == "top") {
            cout << stack.top() << " ";
        } else if (commands[i] == "isEmpty") {
            cout << (stack.isEmpty() ? "true" : "false") << " ";
        } else if (commands[i] == "ArrayStack") {
            cout << "null ";
        }
    }

    return 0;
}