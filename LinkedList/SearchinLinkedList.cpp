#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = NULL;
    }
};

class Solution {
    public:
    bool SearchinLinkedList(Node* &head, int key){

        Node* temp = head;

        while(temp != NULL){
            if(temp->data == key){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
};

int main(){
    Node* head = new Node(1);
    head ->next = new Node(2);
    head->next->next = new Node(3);

    Solution sol;

    cout<<"Enter the key to search in the linked list: "<<endl;
    int key;
    cin>>key;
    if(sol.SearchinLinkedList(head, key)){
        cout<<"Key is present in the linked list."<<endl;
    }
    else{
        cout<<"Key is not present in the linked list."<<endl;
    }
};