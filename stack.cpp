#include <iostream>
using namespace std;

class Node
{

    friend class stack;
    Node *next;
    int data;

public:
    Node(int data = 0)
    {
        this->data = data;
        this->next = NULL;
    }
};

class stack
{
    Node *head;
    int tsize;
    int usize;

public:
    stack(int size);
    bool isEmpty();
    int getSize();
    void push(int data);
    void pop();
    void printStack();
    int peek();
};

stack ::stack(int size)
{
    this->head = NULL;
    this->usize = 0;
    this->tsize = size;
}

bool stack::isEmpty()
{
    if (this->head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int stack::getSize()
{
    return this->usize;
}

void stack::push(int data)
{
    if (this->usize >= this->tsize)
    {
        cout << "Stack Overflow" << endl;
    }
    else
    {
        Node *n1 = new Node(data);

        if (isEmpty())
        {
            this->head = n1;
        }
        else
        {
            n1->next = head;
            this->head = n1;
            this->usize++;
        }
    }
}

int stack:: peek(){
    return this->head->data;
}

void stack::pop()
{
    if (isEmpty())
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        Node *x = this->head;
        this->head = this->head->next;
        delete x;
        this->usize--;
    }
}

void stack::printStack()
{
    Node *temp = this->head;
    while (temp->next != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << temp->data;
}

int main()
{

    stack *stack1 = new stack(5);
    stack1->push(20);
    cout<<stack1->peek();

    return 0;
}
