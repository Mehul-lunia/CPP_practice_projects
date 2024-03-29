#include <iostream>
#ifndef HASH_h
#define HASH_H

// TODO : Store key,value in std::pair as STL uses them
// TODO : implement templates, so hashmap can take any type of parameters

class hashmap
{
private:
    static const int tablesize = 10;
    int m_size = 0;
    struct Node
    {
        std::string key;
        std::string value;
        Node *next;
        Node() : key("empty"), value("empty"), next(nullptr){};                 // -
        Node(std::string k) : key(k), value("empty"), next(nullptr){};          // Key
        Node(std::string k, std::string v) : key(k), value(v), next(nullptr){}; // key value
    };
    Node *HashTable[tablesize];
public:

    hashmap();

    ~hashmap();

    int hash(std::string key);

    bool isEmpty();

    std::string &operator[](const std::string &key);

    void Add(std::string key, std::string value);

    std::string get(std::string key);

    void Remove(std::string key);

    void printMap();

    int size();

    int get_bucketsize(int);
};

#endif