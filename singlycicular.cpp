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

class SinglyCircularList
{
    Node *head;
    Node *tail;

public:
    SinglyCircularList() { head = tail = nullptr; }

    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = tail = newNode;
            tail->setNext(head);
        }
        else
        {
            newNode->setNext(head);
            head = newNode;
            tail->setNext(head);
        }
    }
    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = tail = newNode;
            tail->setNext(head);
        }
        else
        {
            tail->setNext(newNode);
            tail = newNode;
            tail->setNext(head);
        }
    }
    void pop_front()
    {
        if (head == nullptr)
            return;
        if (head == tail)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            Node *temp = head;
            head = head->getNext();
            tail->setNext(head);
            delete temp;
        }
    }
    void pop_back()
    {
        if (head == nullptr)
            return;
        if (head == tail)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            Node *temp = head;
            while (temp->getNext() != tail)
                temp = temp->getNext();
            temp->setNext(head);
            delete tail;
            tail = temp;
        }
    }
    void erase(int val)
    {
        if (!head)
            return;
        while (head->getData() == val)
        {
            if (head == tail)
            {
                delete head;
                head = tail = nullptr;
                return;
            }
            else
            {
                Node *temp = head;
                head = head->getNext();
                tail->setNext(head);
                delete temp;
            }
        }
        Node *temp = head;
        while (temp != tail && temp->getNext() != head)
        {
            Node *nextNode = temp->getNext();
            if (nextNode->getData() == val)
            {
                if (nextNode == tail)
                {
                    delete tail;
                    tail = temp;
                    tail->setNext(head);
                    break;
                }
                else
                {
                    temp->setNext(nextNode->getNext());
                    delete nextNode;
                }
            }
            else
            {
                temp = temp->getNext();
                if (temp == head)
                    break;
            }
        }
    }
    void display()
    {
        if (head == nullptr)
        {
            cout << endl;
            return;
        }
        Node *temp = head;
        while (true)
        {
            cout << temp->getData() << " ";
            temp = temp->getNext();
            if (temp == head)
                break;
        }
        cout << endl;
    }
};

int main()
{
    SinglyCircularList L1;
    L1.push_front(7);
    L1.push_front(6);
    L1.push_back(5);
    L1.display();
    L1.pop_back();
    L1.display();
    L1.erase(7);
    L1.display();
}
