#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

     Node(int data1){
        data = data1;
        next = NULL;
    }
};

class Solution {
    public:
    int Lengthoflinkedlist(Node* &head){
        int cnt = 0;
        Node* temp = head;

        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
};

int main() {
    Node* head = new Node(1);
    head ->next = new Node(2);
    head->next->next = new Node(3);

    Solution sol;

    cout<<"Length of the linked list is: "<<sol.Lengthoflinkedlist(head)<<endl;
}