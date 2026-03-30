#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(int data1, Node* next1, Node* prev1){
        data = data1;
        next = next1;
        prev = prev1;
    }
      Node(int data1){
        data = data1;
        next = NULL;
        prev = NULL;
    }
};

int main(){
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    // Print the list in forward direction
    cout<<"Forward Traversal: "<<endl;
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;

    // Print the list in backward direction
    cout<<"Backward Traversal: "<<endl;
    temp = third;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->prev;
    }
}