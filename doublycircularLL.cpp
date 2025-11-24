#include <iostream>
using namespace std;

class DNode
{
    int data;
    DNode *next;
    DNode *prev;

public:
    DNode(int val)
    {
        data = val;
        next = prev = nullptr;
    }
    void setData(int val) { data = val; }
    int getData() { return data; }
    void setNext(DNode *n) { next = n; }
    void setPrev(DNode *p) { prev = p; }
    DNode *getNext() { return next; }
    DNode *getPrev() { return prev; }
};

class DoublyCircularList
{
    DNode *head;
    DNode *tail;

public:
    DoublyCircularList() { head = tail = nullptr; }

    void push_front(int val)
    {
        DNode *newNode = new DNode(val);
        if (head == nullptr)
        {
            head = tail = newNode;
            head->setNext(head);
            head->setPrev(head);
        }
        else
        {
            newNode->setNext(head);
            newNode->setPrev(tail);
            head->setPrev(newNode);
            tail->setNext(newNode);
            head = newNode;
        }
    }

    void push_back(int val)
    {
        DNode *newNode = new DNode(val);
        if (head == nullptr)
        {
            head = tail = newNode;
            head->setNext(head);
            head->setPrev(head);
        }
        else
        {
            newNode->setPrev(tail);
            newNode->setNext(head);
            tail->setNext(newNode);
            head->setPrev(newNode);
            tail = newNode;
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
            DNode *temp = head;
            head = head->getNext();
            head->setPrev(tail);
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
            delete tail;
            head = tail = nullptr;
        }
        else
        {
            DNode *temp = tail;
            tail = tail->getPrev();
            tail->setNext(head);
            head->setPrev(tail);
            delete temp;
        }
    }

    void erase(int val)
    {
        if (head == nullptr)
            return;
        while (head && head->getData() == val)
        {
            if (head == tail)
            {
                delete head;
                head = tail = nullptr;
                return;
            }
            else
            {
                DNode *temp = head;
                head = head->getNext();
                head->setPrev(tail);
                tail->setNext(head);
                delete temp;
            }
        }

        DNode *temp = head->getNext();
        while (temp != head)
        {
            if (temp->getData() == val)
            {
                DNode *toDelete = temp;
                DNode *nextNode = temp->getNext();
                temp->getPrev()->setNext(nextNode);
                nextNode->setPrev(temp->getPrev());
                if (temp == tail)
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
        if (head == nullptr)
        {
            cout << endl;
            return;
        }
        DNode *temp = head;
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
    DoublyCircularList L1;
    L1.push_front(1);
    L1.push_back(2);
    L1.push_back(3);
    L1.push_front(4);
    L1.display();
    L1.pop_front();
    L1.display();
    L1.pop_back();
    L1.display();
    L1.erase(1);
    L1.display();
    return 0;
}
