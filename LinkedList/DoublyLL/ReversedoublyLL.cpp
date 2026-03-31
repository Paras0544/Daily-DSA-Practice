#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class Solution {
    public:

    Node* ReverseDoublyLinkedList(Node* head){
    if(head == NULL || head -> next == NULL){
        return head; // No reversal needed
    }
    Node* current = head;
    Node* temp = NULL;

    while(current != NULL) {
        // Swap next and prev pointers
        Node* temp = current -> next;
        current->next = current->prev;
        current->prev = temp;

        head = current;          
        current = temp;  

    }
    return head;
}
};

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    Solution obj;
    head = obj.ReverseDoublyLinkedList(head);

    // Print reversed list
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
};