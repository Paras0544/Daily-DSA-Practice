#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(int data1, Node* next1, Node* prev1){
        data = data1;
        next = next1;
        prev = prev1;
    }
    Node(int data1){
        data = data1;
        next = NULL;
        prev = NULL;
    }
};

class Solution {
    public:
    Node* insertAtTail(Node* &head, int Newdata){
        Node* newnode = new Node(Newdata);
        if(head == NULL){
            head = newnode;
            return head;
        }
        Node* temp = head;

        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
        return head;
    }
};

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
};

int main() {
    Solution sol;

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    cout << "Original List: " << endl;
    printList(head);

    cout << "List after inserting at tail: " << endl;
    sol.insertAtTail(head, 4);
    printList(head);
}