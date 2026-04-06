#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
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
}
void print(){
    ListNode* temp = head;
    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout <<"-> NULL" << endl;
}
};

class Solution {
    public:
    ListNode* ReverseList (ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    ListNode* addOne(ListNode* head){
        head = ReverseList(head);
        ListNode* curr = head;
        int carry = 1; // we want to add 1

        while(curr != NULL && carry > 0){
            int sum = curr->val + carry;
            curr->val = sum % 10;
            carry = sum / 10;

            if(curr->next == NULL && carry > 0){
                curr->next = new ListNode(carry);
                carry = 0; // we have added the carry as a new node, so we can stop
            }
            curr = curr->next;
        }
        return ReverseList(head);
    }
};

int main(){
    LinkedList list;

    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);

    cout << "Original List: "<<endl;
    list.print();

    Solution sol;
    list.head = sol.addOne(list.head);

    cout << "List after adding 1: ";
    list.print();

    return 0;
}