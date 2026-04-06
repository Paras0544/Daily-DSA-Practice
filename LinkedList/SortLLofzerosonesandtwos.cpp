 // Dutch National Flag on Linked List (Three Dummy Heads / Partition into 3 buckets
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
    void sortzeroonestwo(LinkedList& List){
        ListNode* zerodummy = new ListNode(-1);
        ListNode* onedummy = new ListNode(-1);
        ListNode* twodummy = new ListNode(-1);
        
        ListNode* zeroTail = zerodummy;
        ListNode* oneTail = onedummy;
        ListNode* twoTail = twodummy;

        ListNode* curr = List.head;

        while(curr != NULL){
            if(curr->val == 0){
                zeroTail->next = curr;
                zeroTail = zeroTail->next;
            }
            else if(curr->val == 1){
                oneTail->next = curr;
                oneTail = oneTail->next;
            }
            else{
                twoTail->next = curr;
                twoTail = twoTail->next;
            }
            curr = curr->next;
        }
        zeroTail->next = onedummy->next;
        oneTail->next = twodummy->next;
        twoTail->next = NULL;

        List.head = zerodummy->next;

        delete zerodummy;
        delete onedummy;
        delete twodummy;
    }
};

int main(){
    LinkedList List;
    List.insert(1);
    List.insert(2);
    List.insert(0);
    List.insert(1);
    List.insert(2);
    List.insert(0);

    cout << "Original list: ";
    List.print();

    Solution sol;
    sol.sortzeroonestwo(List);

    cout << "Sorted list: ";
    List.print();

    return 0;
}