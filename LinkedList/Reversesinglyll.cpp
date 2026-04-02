// 2 pointer approach

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

class Solution{
    public:
    Node* reverse(Node* head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        Node* curr = head;
        Node* front = head->next;
        curr->next = NULL;
        while(front != NULL){
            Node* temp = front->next;
            front->next = curr;
            curr = front;
            front = temp;
        }
        return curr;
    }
};

int main(){
    Node* head = new Node(1, NULL);
    head->next = new Node(2, NULL);
    head->next->next = new Node(3, NULL);
    head->next->next->next = new Node(4, NULL);
    head->next->next->next->next = new Node(5, NULL);

    Solution obj;
    Node* reversedHead = obj.reverse(head);

    cout << "Reversed linked list: ";
    Node* current = reversedHead;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
};