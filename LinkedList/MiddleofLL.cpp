// Fast and Slow pointer approach
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class Solution {
public:

Node* findMiddle(Node* head){
    if(head == NULL){
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
};

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Solution obj;
    Node* middleNode = obj.findMiddle(head);

    if (middleNode) {
        cout << "Middle node data: " << middleNode->data << endl;
    } else {
        cout << "The linked list is empty." << endl;
    }

    return 0;
};