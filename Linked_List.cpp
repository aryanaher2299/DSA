#include<stdio.h>
#include<iostream>

using namespace std;


// Class Node for linked list's Nodes.
class Node
{
    friend class linkedList;
    
    private:
        int data;
        Node* next;

    public:
    // if user creates a node with no parameters also it will take default value of data for that node as 0.
        Node(int data = 0);
        //~Node();

};

// constructor
Node::Node(int data){
    this->data = data;
    this->next = NULL;
}

// Node class ends.

// Class Linked List implementation
class linkedList{
    Node* head;

    public:
    // constructor
    linkedList(){
        head = NULL;
    }

    // Methods for linkedlist operations
    // Insertion at end
    void insertAtEnd(int data){
        Node* node = new Node(data);
        
        if (head == NULL){
            head = node;
        }
        else{
            Node* x = head;
            while(x->next != NULL){
                x = x->next;
            }
            x->next = node;
        }
    }

    //Insert at Head
    void insertAtHead(int data){
        Node* node = new Node(data);
        if (head == NULL){
            head = node;
        }
        else{
            node->next = this->head;
            this->head = node;
        }
    }

    //Insert at Index 

    // Print the list 
    void printList();
    
};


void linkedList :: printList(){
    Node* temp = head;
    while(temp->next != NULL){
        cout<<temp->data<<endl;
        temp = temp->next; 
    }
    cout<<temp->data<<endl;
} 

// Class Linked List ends

int main(){

    linkedList* list1 = new linkedList();
    
    list1->insertAtEnd(10);
    list1->insertAtEnd(20);
    list1->insertAtEnd(30);
    list1->insertAtEnd(50);
    list1->insertAtHead(9);
    list1->insertAtHead(7);
    list1->printList();

    return 0;
}