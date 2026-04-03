// Fast and slow pointers and when they meet we initalize a counter and move the fast pointer until it meets the slow pointer again and count the number of nodes in the loop

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class Solution{
    public:
    int LengthofLoop(Node* head){
        if(head == NULL) return 0;

        Node* slow = head;
        Node* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                int count = 1;
                fast = fast->next;
                while(slow != fast){
                    count++;
                    fast = fast->next;
                }
            return count;
            }
        }
        return 0;
    }
};

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = head->next; // creating a loop

    Solution obj;
    int loopLength = obj.LengthofLoop(head);

    cout << "Length of the loop in the linked list is: " << loopLength << endl;

    return 0;
};