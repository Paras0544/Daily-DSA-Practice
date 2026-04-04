// Remove Nth Node from End of List , fast and slow pointer approach 

#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    ListNode* next;
    int val;
    ListNode(int x){
        val = x;
        next = NULL;
    }
};

class Solution{
    public:
    void printList(ListNode* head){
        while(head != NULL){
            cout << head->val << " ";
            head = head->next;
        }
    }
    ListNode* removeNthFromEnd(ListNode* head, int n){

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* slow = dummy;
        ListNode* fast = dummy;

        for(int i=0; i<n; i++){
            fast = fast->next;
        }
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
};

// Main driver code
int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int N = 3;

    // Create linked list manually
    ListNode* head = new ListNode(arr[0]);
    head->next = new ListNode(arr[1]);
    head->next->next = new ListNode(arr[2]);
    head->next->next->next = new ListNode(arr[3]);
    head->next->next->next->next = new ListNode(arr[4]);

    // Create Solution object
    Solution sol;

    // Delete the Nth node from the end
    head = sol.removeNthFromEnd(head, N);

    // Print the modified linked list
    sol.printList(head);
}