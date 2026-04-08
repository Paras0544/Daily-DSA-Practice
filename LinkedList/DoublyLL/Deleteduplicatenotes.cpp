// Simple traversal and comparing adjacent nodes to remove duplicates in a sorted doubly linked list
#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode* prev;

    ListNode(int x) {
        val = x;
        next = NULL;
        prev = NULL;
    }
};

class LinkedList{
    public:
    ListNode* head;

    LinkedList() { // constructor to initialize empty linked list
        head = NULL;
    }

    void insert(int val){ // helper function to insert new node at end
    ListNode* newNode = new ListNode(val);
    if(head == NULL){
        head = newNode;
        return;
    }
    ListNode* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp; // set the previous pointer of the new node
}
};

class Solution {
    public:
    void deleteDuplicates(ListNode* head){
        if(head == NULL)
            return;
        ListNode* curr = head;
        while(curr != NULL && curr->next != NULL){
            if(curr->val == curr->next->val){
                curr->next = curr->next->next; // skip the duplicate node
                if(curr->next != NULL){
                    curr->next->prev = NULL;
                }
            } else {
                curr = curr->next; // move to the next node
            }
        }
    }
};

int main(){
    LinkedList list;
    list.insert(1);
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(3);

    Solution sol;
    sol.deleteDuplicates(list.head);

    // Print the modified linked list
    ListNode* temp = list.head;
    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << "-> NULL" << endl;

    return 0;
}