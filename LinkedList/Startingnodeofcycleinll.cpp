// fast and slow pointers with additional logic to find the starting node of the cycle

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
    Node* startingnodeofcycle(Node* head){
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        Node* slow = head;
        Node* fast = head;

        while(slow != NULL && fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                slow = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
            }
            return slow;
        }
        return NULL;}
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
    Node* cycleStartNode = obj.startingnodeofcycle(head);

    if (cycleStartNode) {
        cout << "Cycle starts at node with value: " << cycleStartNode->data << endl;
    } else {
        cout << "No cycle detected in the linked list." << endl;
    }

    return 0;
};