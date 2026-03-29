#include<iostream>
using namespace std;

class Node{
    public:
    int data; // data of the node
    Node* next; // pointer to the next node

    Class Node(int data1, Node* next1){ // constructor to initialize the data and next pointer of the node
        data = data1;
        next = next1;
    }
    Class Node(int data1){ // constructor to initialize the data of the node and set the next pointer to NULL
        data = data1;
        next = NULL;
    }
};
