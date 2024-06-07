#include <iostream>
#include <stack>
using namespace std;

class Node
{
    friend class Tree;
    Node *left;
    Node *right;
    Node *parent;
    int data;

public:
    Node(int data)
    {
        this->parent = NULL;
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class Tree
{
private:
    Node *root;

    bool isEmpty() { return (this->root == NULL) ? true : false; }

public:
    Tree() { this->root = NULL; }

    //  void recursiveInsert(int data);
    void iterativeInsert(int data);
    void deleteByValue(int data);
    bool searchByValue(int data);
    void preorderTraversal();
    void inorderTraversal();

    // void traverse
};

void Tree::iterativeInsert(int data)
{

    Node *node = new Node(data);
    Node *temp = this->root;
    Node *y = NULL;

    while (temp != NULL)
    {
        y = temp;
        if (node->data <= temp->data)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }

    node->parent = y;

    if (isEmpty())
    {
        this->root = node;
    }
    else if (node->data <= y->data)
    {
        y->left = node;
    }
    else
    {
        y->right = node;
    }
}

bool Tree ::searchByValue(int data)
{
    if (isEmpty())
    {
        return false;
    }
    else
    {
        Node *temp = this->root;

        while (temp != NULL)
        {
            if (data == temp->data)
            {
                return true;
            }
            else if (data <= temp->data)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        return false;
    }
}

void Tree:: preorderTraversal(){
    stack<Node*> st;
    st.push(this->root);

    while(!st.empty()){
        Node* temp = st.top();
        st.pop();

        cout<<temp->data;
        cout<<"->";
// We push both left and right nodes inside the stack. But we push right first so that the left node is at the top of the stack.
        if(temp->right!=NULL){
            st.push(temp->right);
        }

        if(temp->left!=NULL){
            st.push(temp->left);
        }
        
    }
}


void Tree:: inorderTraversal(){
    stack<Node*> st;
    st.push(this->root);

    while(!st.empty()){
        Node* temp = st.top();
        st.pop();

        cout<<temp->data;
        cout<<"->";
// We push both left and right nodes inside the stack. But we push right first so that the left node is at the top of the stack.
        if(temp->right!=NULL){
            st.push(temp->right);
        }

        if(temp->left!=NULL){
            st.push(temp->left);
        }
        
    }
}


int main()
{
    Tree* tree = new Tree();
    tree->iterativeInsert(50);
    tree->iterativeInsert(70);
    tree->iterativeInsert(30);
    tree->iterativeInsert(90);
    tree->iterativeInsert(15);
    tree->iterativeInsert(20);

    //cout<<tree->searchByValue(10);
    tree->preorderTraversal();

    return 0;
}
