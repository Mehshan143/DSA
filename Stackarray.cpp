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
    int getData() { 
    return data; 
    }
    Node *getNext() { 
    return next;
    }
    void setNext(Node *n) { 
    next = n; 
}
};

class Stack
{
    Node *topNode;

public:
    Stack() { topNode = nullptr; }

    void push(int val)
    {
        Node *newNode = new Node(val);
        newNode->setNext(topNode);
        topNode = newNode;
    }

    void pop()
    {
        if (topNode == nullptr)
        {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node *temp = topNode;
        topNode = topNode->getNext();
        delete temp;
    }

    int top()
    {
        if (topNode == nullptr)
        {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return topNode->getData();
    }

    bool isEmpty()
    {
        return topNode == nullptr;
    }

    void display()
    {
        Node *temp = topNode;
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
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    s.pop();
    s.display();
    s.pop();
    s.display();
    s.pop();
    s.display();
    s.pop();
    return 0;
}
