// 2pointer and switch heads when any pointer == NULL
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
    ListNode* findInstersection(ListNode* head1, ListNode* head2){
        ListNode* d1 = head1;
        ListNode* d2 = head2;

        while(d1 != d2){
            d1 = (d1 == NULL) ? head2 : d1->next;
            d2 = (d2 == NULL) ? head1 : d2->next;
        }
        return d1; // or d2, both are same at this point
    }
};

int main(){
    LinkedList list1;
    LinkedList list2;

    list1.insert(1);
    list1.insert(2);
    list1.insert(3);
    list1.insert(4);
    list1.insert(5);

    list2.insert(9);
    list2.insert(8);

    // creating intersection
    list2.head->next->next = list1.head->next->next; // 8 -> 3 

    Solution sol;

    ListNode* intersectionNode = sol.findInstersection(list1.head, list2.head);

    if(intersectionNode != NULL){
        cout << "Intersection at node with value: " << intersectionNode->val << endl;
    }
    else{
        cout << "No intersection found." << endl;
    }

    return 0;
}