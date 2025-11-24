#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *next;

public:
    Node(int val)
    {
        data = val;
        next = nullptr;
    }

    void setData(int val) { data = val; }
    int getData() { return data; }
    void setNext(Node *Next) { next = Next; }
    Node *getNext() { return next; }
};

class List
{
    Node *head;
    Node *tail;

public:
    List() { head = tail = nullptr; }

    void push_front(int val)
    {
        Node *newNode = new Node(val);
        newNode->setNext(head);
        head = newNode;
        if (tail == nullptr)
            tail = newNode;
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->setNext(newNode);
            tail = newNode;
        }
    }

    void pop_front()
    {
        if (head == nullptr)
        {
            return;
        }
        else
        {
            Node *temp = head;
            head = head->getNext();
            delete temp;
            if (head == nullptr)
            {
                tail = nullptr;
            }
        }
    }

    void pop_back()
    {
        if (head == nullptr)
        {
            return;
        }
        if (head == tail)
        {
            delete head;
            head = tail = nullptr;
            return;
        }
        Node *temp = head;
        while (temp->getNext() != tail)
        {
            temp = temp->getNext();
        }
        delete tail;
        tail = temp;
        tail->setNext(nullptr);
    }

    void erase(int val)
    {
        if (head == nullptr)
        {
            return;
        }
        if (head->getData() == val)
        {
            pop_front();
            return;
        }
        Node *temp = head;
        while (temp->getNext() && temp->getNext()->getData() != val)
        {
            temp = temp->getNext();
        }
        if (temp->getNext())
        {
            Node *toDelete = temp->getNext();
            temp->setNext(toDelete->getNext());
            if (toDelete == tail)
                tail = temp;
            delete toDelete;
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
    List L1;
    L1.push_front(7);
    L1.push_back(6);
    L1.display();
    L1.push_front(7);
    L1.push_front(5);
    L1.push_front(7);
    L1.display();
    L1.pop_back();
    L1.pop_back();
    L1.display();
    L1.display();
    L1.erase(5);
    L1.display();
}
