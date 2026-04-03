
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

Node* reverseList(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* newHead = reverseList(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

class Solution{
    public:
    bool isPalindrome(Node* head){
        if(head == NULL || head->next == NULL) return true;
        Node* slow = head;
        Node* fast = head;

        while(fast->next != NULL && fast->next->next != NULL){ // finding the middle of the linked list
            slow = slow->next;
            fast = fast->next->next;

        }
        Node* newHead = reverseList(slow->next); // reversing the second half of the linked list
        Node* first = head;
        Node* second = newHead;

        while(second != NULL){ // comparing the first half and the reversed second half of the linked list
            if(first->data != second->data){
                return false;
            }
            first = first->next;
            second = second->next;
        }
        return true;
}
};

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(1);

    Solution obj;
    bool result = obj.isPalindrome(head);

    if(result){
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
};