#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = NULL;
    }
};

class Solution {
public:
    Node* insertAtHead(Node* &head, int Newdata) {
        Node* newnode = new Node(Newdata, head);
        head = newnode;
        return newnode;
    }
};

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {

    Solution sol;

    Node* head = new Node(2);
    head->next = new Node(3);

    cout << "Original List: " << endl;
    printList(head);

    cout << "List after inserting at head: " << endl;
    sol.insertAtHead(head, 1);
    printList(head);
}