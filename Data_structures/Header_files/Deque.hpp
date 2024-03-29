#include <iostream>

#ifndef DEQUE_H
#define DEQUE_H

// using doubly linked list, maintaining two pointers head and tail
class Deque
{
private:
    struct Node // Doubly-linked Linked list
    {
        int value;
        Node *prev;
        Node *next;
        Node(int v) : value(v), prev(nullptr), next(nullptr){};
    };
    int m_size = 0;
    Node *m_head = nullptr;
    Node *m_tail = nullptr;

public:
    Deque();                            // Normal constructor
    Deque(const Deque& other);          // Copy constructor
    Deque(Deque&& other);               // Move constructor
    Deque& operator=(const Deque& rhs); // Copy assignment operator overload
    Deque& operator=(Deque&& rhs);      // r-value move assignment operator overload
    ~Deque();
    bool is_empty();
    int size();
    int &operator[](int idx);
    void push_front(int value);
    void push_back(int value);
    void pop_front();
    void pop_back();
    int front();
    int back();
};

#endif