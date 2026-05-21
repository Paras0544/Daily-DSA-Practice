#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int d){
        val = d;
        next = NULL;
    }
};

class LinkedListQueue {
    private:
    Node* start;
    Node* end;
    int size;

    public:
     LinkedListQueue(){
        start = end = NULL;
        size = 0;
    }

    void push(int x){
        Node * element = new Node(x);
        if(start == NULL) {
            start = end = element;
        }
            end -> next = element;
            element = end;
    size++;
    }

    int pop() {
        if(start == NULL){
            return -1;
        }
            int value = start->val;
            Node* temp = start;
            start = start->next;
            delete temp;
            size--;
        
        return value;
    }

    int peek(){
        if(start == NULL){
            return -1;
        }
        return start->val;
    }

    bool isEmpty(){
        return(size == 0);
    }

};

int main() {
    // Creating a queue
    LinkedListQueue q;

    // List of commands
    vector<string> commands = {"LinkedListQueue", "push", "push", 
                               "peek", "pop", "isEmpty"};
    // List of inputs
    vector<vector<int>> inputs = {{}, {3}, {7}, {}, {}, {}};

    for (int i = 0; i < commands.size(); ++i) {
        if (commands[i] == "push") {
            q.push(inputs[i][0]);
            cout << "null ";
        } else if (commands[i] == "pop") {
            cout << q.pop() << " ";
        } else if (commands[i] == "peek") {
            cout << q.peek() << " ";
        } else if (commands[i] == "isEmpty") {
            cout << (q.isEmpty() ? "true" : "false") << " ";
        } else if (commands[i] == "LinkedListQueue") {
            cout << "null ";
        }
    }

    return 0;
}