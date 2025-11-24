#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *next;
    Node *prev;

public:
    Node(int val)
    {
        data = val;
        next = prev = nullptr;
    }

    void setData(int val)
    {
        data = val;
    }
    int getData()
    {
        return data;
    }
    void setNext(Node *Next)
    {
        next = Next;
    }
    void setPrev(Node *previous)
    {
        prev = previous;
    }
    Node *getNext()
    {
        return next;
    }
    Node *getPrev()
    {
        return prev;
    }
};

class DoublyList
{
    Node *head;
    Node *tail;

public:
    DoublyList()
    {
        head = tail = nullptr;
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);
        newNode->setNext(head);
        if (head)
            head->setPrev(newNode);
        head = newNode;
        if (tail == nullptr)
            tail = newNode;
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);
        newNode->setPrev(tail);
        if (tail)
            tail->setNext(newNode);
        tail = newNode;
        if (head == nullptr)
            head = newNode;
    }

    void pop_front()
    {
        if (head == nullptr)
        {
            return;
        }
        Node *temp = head;
        head = head->getNext();
        if (head)
            head->setPrev(nullptr);
        else
            tail = nullptr;
        delete temp;
    }

    void pop_back()
    {
        if (tail == nullptr)
            return;
        Node *temp = tail;
        tail = tail->getPrev();
        if (tail)
        {
            tail->setNext(nullptr);
        }
        else
        {
            head = nullptr;
        }
        delete temp;
    }

    void erase(int val)
    {
        Node *temp = head;
        while (temp)
        {
            if (temp->getData() == val)
            {
                Node *toDelete = temp;
                Node *nextNode = temp->getNext();
                if (temp->getPrev())
                    temp->getPrev()->setNext(nextNode);
                else
                    head = nextNode;
                if (nextNode)
                    nextNode->setPrev(temp->getPrev());
                else
                    tail = temp->getPrev();
                temp = nextNode;
                delete toDelete;
            }
            else
            {
                temp = temp->getNext();
            }
        }
    }

    void display()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->getData() << " ";
            temp = temp->getNext();
        }
        cout << endl;
    }
};

int main()
{
    DoublyList L1;
    L1.push_front(10);
    L1.push_back(20);
    L1.push_front(10);
    L1.display(); 
    L1.erase(10);
    L1.display(); 
}
