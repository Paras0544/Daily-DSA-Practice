#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int value){
        data = value;
        next = NULL;
    }
};

class Solution {
    public:
    Node* deleteLastNode(Node* head){
        if(head == NULL || head ->next == NULL){
            delete head;
            return NULL;
        }
    
    Node* curr = head;
    while(curr->next->next != NULL){
        curr = curr->next; 
       }
     delete curr->next;
    curr-> next = NULL;
    return head;
    }

};

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    Solution obj;
    head = obj.deleteLastNode(head);

    // Print list after deletion
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
};