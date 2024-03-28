#include <cstdlib>
#include <iostream>
#include <string.h>
#include "./Header_files/hash.h"

// Utility Functions
int String_hasher(std::string key, int capacity)
{
    int str_total = 0;
    for (int i = 0; i < key.length(); i++)
    {
        str_total += (int)key[i];
    }
    return str_total % capacity;
}




//  Public function Implementation
hashmap::hashmap()
{
    for (int i = 0; i < tablesize; i++)
        HashTable[i] = nullptr;
}


int hashmap::hash(std::string key)
{
    return String_hasher(key,tablesize);
}


std::string &hashmap::operator[](const std::string &key)
{
    int idx = hash(key);
    Node *curr = HashTable[idx];
    Node *prev = nullptr;
    while (curr != nullptr)
    {
        if (curr->key == key)
            return curr->value;
        prev = curr;
        curr = curr->next;
    }
    if (prev == nullptr)
    {
        HashTable[idx] = new Node(key);
        m_size++;
        return HashTable[idx]->value;
    }
    Node *new_node = new Node(key);
    prev->next = new_node;
    m_size++;
    return new_node->value;
}


void hashmap::Add(std::string key, std::string value)
{
    int idx = hash(key);
    Node *new_node = new Node(key, value);
    if (HashTable[idx] == nullptr)
    {
        HashTable[idx] = new_node;
        m_size++;
    }
    else
    {
        Node *curr = HashTable[idx];
        while (curr->next != nullptr)
        {
            if (curr->key == key)
                return; // duplicate
            curr = curr->next;
        }
        curr->next = new_node;
        m_size++;
    }
}


std::string hashmap::get(std::string key)
{
    int idx = hash(key);
    Node *curr = HashTable[idx];
    while (curr != nullptr)
    {
        if (curr->key == key)
            return curr->value;
        curr = curr->next;
    }
    return "empty";
}


int hashmap::size() { return m_size; }


hashmap::~hashmap() // TODO : check its accuracy!
{
    for (int i = 0; i < tablesize; i++)
    {
        if (HashTable[i] != nullptr)
        {
            delete HashTable[i];
        }
    }
}

void hashmap::Remove(std::string key)
{
    int idx = hash(key);
    // Linked List is empty
    if (HashTable[idx] == nullptr)
        return;
    // removed Node is first Node
    if (HashTable[idx]->key == key)
    {
        Node *nxt = HashTable[idx]->next;
        HashTable[idx]->next = nullptr;
        HashTable[idx] = nxt;
        m_size--;
        return;
    }
    // if the removed Node is not the first Node
    Node *curr = HashTable[idx];
    Node *prev = nullptr;
    while (curr != nullptr)
    {
        if (curr->key == key)
        {
            prev->next = curr->next;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    m_size--;
}

void hashmap::printMap()
{
    for(int i=0;i<tablesize;i++)
    {
        if(HashTable[i] == nullptr)
        {
            std::cout<<i+1<<std::endl;   // idx
            continue;
        }
        std::cout<<i+1<<"    ";          // idx
        Node* curr = HashTable[i];
        while(curr != nullptr)
        {
            std::cout<< "Key: "<< curr->key << " value: "<< curr->value<<"    ";
            curr = curr->next;
        }
        std::cout<<std::endl;
    }

}


int hashmap::get_bucketsize(int bucket_idx)
{
    if(HashTable[bucket_idx] == nullptr) return 0;
    Node* curr = HashTable[bucket_idx];
    int bucket_size = 0;
    while(curr)
    {
        bucket_size++;
        curr = curr->next;
    }
    return bucket_size;
}