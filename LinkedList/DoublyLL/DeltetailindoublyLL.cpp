#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;

    Node(int data1, Node* next1, Node* prev1){
        data = data1;
        next = next1;
        prev = prev1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};

class Solution {
    public:
    Node* DeleteTail(Node* head){
        if(head == NULL || head->next == NULL){
            delete head;
            return NULL;
        }
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->prev->next = NULL;
        delete temp;
        return head;
    }
    };

int main() {
    Solution sol;
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    cout << "Original list: ";
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    head = sol.DeleteTail(head);

    cout << "List after deleting tail: ";
    temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}