#include "./Header_files/hash.hpp"
#include "./Header_files/Deque.hpp"
#include <iostream>

int main()
{
    // HASHMAP
    hashmap h;
    h.Add("Mehul","Lunia");
    h.Add("Cherno","C++");
    h.Add("Michael","jackson");
    h.Add("Michael","jackson");


    hashmap h2(h);
    
    h["Mehul"] = "ibn khalid";

    // VECTOR

    // ARRAY

    // DEQUE
    Deque d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    d.push_front(4);
    d.push_front(5);
    d.push_back(6);
    d.pop_back();
}