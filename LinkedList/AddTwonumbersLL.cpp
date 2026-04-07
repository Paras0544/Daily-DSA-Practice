//pattern used is Digit-wise Simulation with Carry (Linked List)
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
};

class Solution {
    public:
    ListNode* AddtwoLinkedList(ListNode* l1, ListNode* l2){
        ListNode dummy(0);
        ListNode* curr = &dummy;
        int carry = 0;

        while(l1 != NULL || l2 != NULL || carry != 0){
            int sum = carry;
            if(l1 != NULL){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }
        return dummy.next;
    }
};

int main(){
    LinkedList list1;
    list1.insert(2);
    list1.insert(4);
    list1.insert(3);

    LinkedList list2;
    list2.insert(5);
    list2.insert(6);
    list2.insert(4);

    Solution sol;
    ListNode* result = sol.AddtwoLinkedList(list1.head, list2.head);

    // Print the result
    while(result != NULL){
        cout << result->val << " ";
        result = result->next;
    }
    cout << "-> NULL" << endl;

    return 0;
}