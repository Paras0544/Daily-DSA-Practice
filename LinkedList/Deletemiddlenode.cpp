// fast and slow pointers 

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
    public:
    ListNode* deleteMiddle(ListNode* head){
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        // Now slow is pointing to the middle node, we need to delete it
        ListNode* temp = head;
        while(temp->next != slow){
            temp = temp->next;
        }
        temp->next = slow->next;
        delete slow; // free the memory of the deleted node
        return head;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution obj;
    head = obj.deleteMiddle(head);

    // Print the modified linked list
    ListNode* curr = head;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;

    return 0;
}