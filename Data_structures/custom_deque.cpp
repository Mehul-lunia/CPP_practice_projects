#include <iostream>
#include "./Header_files/Deque.hpp"

bool Deque::is_empty() { return m_size == 0 ? 1 : 0; }

// deque Back functions

void Deque::push_back(int value)
{
    Node *new_node = new Node(value);
    if (is_empty())
    {
        m_head = new_node;
        m_tail = new_node;
        m_size++;
        std::cout << "[INFO] Successfully inserted value at the back!" << std::endl;
        return;
    }
    m_tail->next = new_node;
    new_node->prev = m_tail;
    m_tail = new_node;
    m_size++;
    std::cout << "[INFO] Successfully inserted value at the back!" << std::endl;
}

void Deque::pop_back()
{
    if (is_empty())
    {
        std::cout << "[WARNING] no elements in Deque to pop!" << std::endl;
        return;
    }
    // if only one element present
    if (m_head == m_tail)
    {
        delete m_tail;
        m_head = nullptr;
        m_tail = nullptr;
        m_size--;
        std::cout << "[INFO] popped element from the back!" << std::endl;
        return;
    }

    // <1 Elements present
    Node *prev_node = m_tail->prev;
    prev_node->next = nullptr;
    delete m_tail;
    m_tail = prev_node;
    m_size--;
    std::cout << "[INFO] popped element from the back!" << std::endl;
}

int Deque::back()
{
    if (!is_empty())
    {
        return m_tail->value;
    }
    return -1;
}

Deque::~Deque()
{
    Node *curr = m_head;
    while (curr != nullptr)
    {
        Node *nxt = curr->next;
        delete curr;
        curr = nxt;
    }
}


// deque Front functions
void Deque::push_front(int value)
{
    Node* new_node = new Node(value);
    // If linked list is empty
    if(is_empty())
    {
        m_head = new_node;
        m_tail = new_node;
        std::cout<<"[INFO] Successfully inserted node at the front!"<<std::endl;
        m_size++;
        return;
    }
    new_node->next = m_head;
    m_head->prev = new_node;
    m_head = new_node;
    m_size++;
    std::cout<<"[INFO] Successfully inserted node at the front!"<<std::endl;

}

void Deque::pop_front()
{
    if(is_empty())
    {
        std::cout<<"[WARNING] No Items to pop!"<<std::endl;
        return;
    }
    Node* nxt = m_head->next;
    m_head->next = nullptr;
    delete m_head;
    m_head = nxt;
    m_size--;
    std::cout<<"[INFO] Item popped from the front!"<<std::endl;
}

int Deque::front()
{
    if(!is_empty())
    {
        return m_head->value;
    }
    return -1;
}

