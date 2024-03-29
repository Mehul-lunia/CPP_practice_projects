#include <iostream>
#include <vector>
#include <string.h>
#include "./Header_files/hash.hpp"


// TODO : copy constructor not working properly
// TODO : Makefile not executing commands properly




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
    memset(HashTable, 0, sizeof(Node *) * tablesize);
}

// hashmap::hashmap(const hashmap& other)
// {
//     memset(HashTable,0,sizeof(Node*)*tablesize);
//     for(int i=0;i<tablesize;i++)
//     {
//         Node* curr = other.HashTable[i];
//         std::vector<Node*> vect;
//         while(curr != nullptr)
//         {
//            Node* new_node = new Node(curr->key,curr->value);
//            vect.push_back(new_node);
//            curr = curr->next;
//         }
//         for(int i=0;i<(vect.size()-1);i++)
//         {
//             vect[i]->next = vect[i+1];
//         }
//         if(!vect.empty())HashTable[i] = vect[0];
//         m_size += vect.size();

//     }
// }

// hashmap::hashmap(hashmap&& other)
// {}

// hashmap& hashmap::operator=(const hashmap& rhs)
// {}

// hashmap& hashmap::operator=(hashmap&& rhs)
// {}

int hashmap::hash(std::string key)
{
    return String_hasher(key, tablesize);
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
        std::cout << "[INFO] successfully added new Element!" << std::endl;
        return;
    }
    Node *curr = HashTable[idx];
    Node *prev = nullptr;
    while (curr != nullptr)
    {
        if (curr->key == key)
        {
            std::cout << "[WARNING] Insertion of duplicate Element in HashTable.Rejected!" << std::endl;
            return; // duplicate
        }
        prev = curr;
        curr = curr->next;
    }
    prev->next = new_node;
    m_size++;
    std::cout << "[INFO] successfully added new Element!" << std::endl;
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

hashmap::~hashmap()
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
        std::cout << "[WARNING] No such Item exists!" << std::endl;
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
    bool item_found_removed = false;
    while (curr != nullptr)
    {
        if (curr->key == key)
        {
            prev->next = curr->next;
            item_found_removed = true;
            m_size--;
            break;
        }
        prev = curr;
        curr = curr->next;
    }
    if (!item_found_removed)
    {
        std::cout << "[Warning] no such item exists!" << std::endl;
    }
    else
    {
        std::cout << "[INFO] Removed Item successfully!" << std::endl;
    }
}

void hashmap::printMap()
{
    for (int i = 0; i < tablesize; i++)
    {
        if (HashTable[i] == nullptr)
        {
            std::cout << i + 1 << std::endl; // idx
            continue;
        }
        std::cout << i + 1 << "    "; // idx
        Node *curr = HashTable[i];
        while (curr != nullptr)
        {
            std::cout << "Key: " << curr->key << " value: " << curr->value << "    ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }
}

int hashmap::get_bucketsize(int bucket_idx)
{
    if (HashTable[bucket_idx] == nullptr)
        return 0;
    Node *curr = HashTable[bucket_idx];
    int bucket_size = 0;
    while (curr != nullptr)
    {
        bucket_size++;
        curr = curr->next;
    }
    return bucket_size;
}

bool hashmap::isEmpty()
{
    return m_size == 0 ? 1 : 0;
}