#include <iostream>
#include <initializer_list>
#include <algorithm>
#include <string.h>


class Point
{
private:
    int x,y,z;
public:
    Point()
    {
        std::cout<<"Point's 0 argument constructor"<<std::endl;
        x = 0;
        y = 0;
        z = 0;
    }
    Point(int x,int y,int z):x(x),y(y),z(z){};

    Point(const Point& other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
    }
    
    Point& operator=(const Point& rhs)
    {
        std::cout<<"Copied"<<std::endl;
        if(&rhs == this)return *this;
        x = rhs.x;
        y = rhs.y;
        z = rhs.z;
        return *this;
    }

    Point& operator=(Point&& rhs)
    {
        std::cout<<"Moved"<<std::endl;
        x = rhs.x;
        y = rhs.y;
        z = rhs.z;
        rhs.x = 0;
        rhs.y = 0;
        rhs.z = 0;
        return *this;
    }
    void print()
    {
        std::cout<<"x "<<x<<" y "<<y<<" z "<<z<<std::endl;
    }
};

template <typename T>
class Vector
{
private:
    T *p = NULL;

    int back_idx = 0;

    int memslots = 0;

    void Realloc(int new_capacity)
    {
        T *ptr = new T[new_capacity];
        if(back_idx!=0){
            for (int i = 0; i < back_idx; i++)
            {
                *(ptr + i) = std::move(*(p + i));
            }
        }
        memset(ptr+memslots,0,sizeof(T)*(new_capacity-memslots));
        delete[] p;
        p = ptr;
        memslots = new_capacity;
    }

public:
    Vector()
    {
        Realloc(2);
    }
    Vector(std::initializer_list<T> l)
    {
        Realloc(l.size());
        for (int i = 0; i < l.size(); i++)
        {
            *(p + i) = *(l.begin() + i);    // copy assignment
            back_idx++;
        }
        
    }
    ~Vector()
    {
        delete[] p;
    }
    void push_back(const T& val)
    {
        if (back_idx >= memslots)           // realloc 50% more slots
        {
            Realloc(memslots + (memslots / 2));
        }
        *(p + back_idx) = val;
        back_idx++;
    }

    void push_back(T&& val)
    {
        if(back_idx >= memslots)Realloc(memslots+(memslots/2)); 
        *(p + back_idx) = std::move(val);
        back_idx++;
    }

    constexpr size_t size() { return back_idx; }


    T *begin() { return p; }

    T *end() { return (p + back_idx); }

    void erase(int idx)
    {
        int nxt_idx = idx+1;
        T* nxt_ptr = begin()+nxt_idx;
        if((nxt_ptr) != end()) memmove(begin()+idx,nxt_ptr,sizeof(T) * (back_idx-nxt_idx));
        back_idx--;
    }

    void insert(int idx,T new_value)    // More optimal to use linked list but whatever!
    {
        if(idx < 0 || idx >= size()) throw std::logic_error("index provided not with valid bounds");
        if(back_idx >= memslots) Realloc(memslots+(memslots/2));
        int nxt_idx = idx + 1;
        memmove(begin()+nxt_idx,begin()+idx,sizeof(T)*(back_idx-idx));
        *(begin()+idx) = new_value;
        back_idx++;
    }

    void reserve(int amt)
    {
        if (amt <= 2)
            return;
        Realloc(amt);
    }

    T &operator[](size_t idx)
    {
        if (idx >= back_idx) throw std::logic_error("index not within valid bounds");
        return *(p + idx);
    }

    void print()
    {
        for (int i = 0; i < size(); i++)
        {
            std::cout << *(p + i) << std::endl;
        }
    }
};




int main()
{
    // Vector<Point> v;
    // v.push_back(Point{1,2,3});
    // v.push_back(Point{5,0,14});
    // v.push_back(Point{7,3,6});
    // std::cout<<v[1]<<std::endl;
    Vector<int> v{1,2,3,4,5};
    v.insert(4,100);
    v.print();
    
    

    return 0;
}