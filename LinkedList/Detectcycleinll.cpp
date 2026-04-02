// fast and slow pointers (floyd's cycle detection algorithm)

#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int value, Node* next1){
        data = value;
        next = next1;
    }
};

class Solution {
    public:
    bool cycledetection(Node* head){
        if(head == NULL || head->next == NULL){
            return false;
        }
        Node* slow = head;
        Node* fast = head;

        while(slow != NULL && fast != NULL && fast ->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                return true;
            }
        }
        return false;
    }
};

int main(){
    Node* head = new Node(1, NULL);
    head->next = new Node(2, NULL);
    head->next->next = new Node(3, NULL);
    head->next->next->next = new Node(4, NULL);
    head->next->next->next->next = new Node(5, NULL);

    // Creating a cycle for testing
    head->next->next->next->next->next = head->next; // Cycle here

    Solution obj;
    bool hasCycle = obj.cycledetection(head);

    if (hasCycle) {
        cout << "Cycle detected in the linked list." << endl;
    } else {
        cout << "No cycle detected in the linked list." << endl;
    }

    return 0;
};