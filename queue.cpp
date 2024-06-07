#include <iostream>
using namespace std;

class Node
{
    friend class queue;
    Node *next;
    int data;

public:
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class queue
{
    Node *head;
    Node *tail;
    int usedSize;
    int totalSize;

public:
    queue(int size);
    bool isEmpty();
    void enqueue(int data);
    int dequeue();
    int getSize();
    int peek();

    void printQueue();
};

queue ::queue(int size)
{
    this->head = NULL;
    this->tail = NULL;

    this->usedSize = 0;
    this->totalSize = size;
}

bool queue ::isEmpty()
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

int queue::getSize()
{
    return this->usedSize;
}

void queue ::enqueue(int data)
{
    Node *temp = new Node(data);
    if (isEmpty())
    {
        this->tail = temp;
        this->head = temp;
        this->usedSize++;
    }
    else
    {
        if (usedSize >= totalSize)
        {
            cout << "Queue Full";
        }
        else
        {
            this->tail->next = temp;
            this->tail = this->tail->next;
            this->usedSize++;
        }
    }
}

int queue ::peek()
{
    if (this->head == NULL)
    {
        return -1;
    }

    return this->head->data;
}

int queue ::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty";
        return -1;
    }
    else
    {
        int tempData = this->head->data;
        Node *temp = this->head;
        this->head = this->head->next;
        delete temp;
        this->usedSize--;
        return tempData;
    }
}

void queue ::printQueue()
{
    Node *temp = this->head;

    while (temp != this->tail)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << temp->data << endl;
}

int main()
{

    queue *q = new queue(5);
    q->enqueue(5);
    q->enqueue(69);
    q->enqueue(97);
    q->dequeue();
    q->enqueue(12);

    q->printQueue();

    cout << "When I call peek the output is :\n"
         << q->peek() << endl;

    return 0;
}
