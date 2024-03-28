#include <iostream>
#include <stdexcept>
#include <cstring>
#include <initializer_list>



template <typename T,size_t req_size>
class Array
{
    T arr[req_size];
public:
    Array()
    {
        memset(&arr[0],0,sizeof(int));
    }
    Array(std::initializer_list<T> l)
    {
        if(l.size() > req_size){throw std::invalid_argument("Array is allocated for less elements but initializer list contains  elements!");}
        for(int i=0;i<req_size;i++){*(arr+i) = *(l.begin()+i);}
    }
    constexpr  Get_req_size(){return req_size;}
    T& operator [](int idx)
    {
        if(idx < req_size)
        {
        return *(arr+idx);
        }
        else
        {
            throw std::invalid_argument("This Memory address can't be accessed as it was not alloted!");
        }
    }

    void print()
    {
        for(int i=0;i<req_size;i++){std::cout<< *(arr+i) <<std::endl;}        
    }
};



int main()
{
    Array<int,2> arr;
    arr.print();
    
}
