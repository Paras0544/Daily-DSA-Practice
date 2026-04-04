#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
    ListNode* dummyNode = new ListNode(-1);
    ListNode* temp = dummyNode;

    while(list1 != NULL && list2 != NULL){
        if(list1->val <= list2->val){
            temp->next = list1;
            list1 = list1->next;
        }
        else{
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }
    if (list1 != nullptr) {
            temp->next = list1;
        } else {
            temp->next = list2;
        }

        // Return head of merged list
        return dummyNode->next;
}

ListNode* findMiddle(ListNode* head) {
        // If list empty or single node
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head->next;

        // Move fast twice as fast as slow
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Return middle node
        return slow;
    }

        // Function to perform merge sort
    ListNode* sortLL(ListNode* head) {
        // Base case: empty or single node
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Find middle node
        ListNode* middle = findMiddle(head);

        // Split into two halves
        ListNode* right = middle->next;
        middle->next = nullptr;
        ListNode* left = head;

        // Recursively sort both halves
        left = sortLL(left);
        right = sortLL(right);

        // Merge sorted halves
        return mergeTwoLists(left, right);
    }
};

void printLinkedList(ListNode* head) {
    // Temp pointer to traverse
    ListNode* temp = head;

    // Traverse and print nodes
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create linked list: 3 -> 2 -> 5 -> 4 -> 1
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(5);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(1);

    // Print original list
    cout << "Original Linked List: ";
    printLinkedList(head);

    // Create Solution object
    Solution obj;

    // Sort the linked list
    head = obj.sortLL(head);

    // Print sorted list
    cout << "Sorted Linked List: ";
    printLinkedList(head);

    return 0;
}