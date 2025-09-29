#pragma once
#include <iostream>
#include <algorithm>  //for std::max

namespace dsa{

template <typename T>
class Vector {

private:
    int cap{0};
    int sz{0};
    T* data{nullptr};

   //Helper function useful for reallocating the array
    void reallocate(int new_cap){
        if (new_cap == cap) return;

        T* temp_data = new T[new_cap];
        for (int k=0; k < sz ;k++){
            temp_data[k] = data[k];
        }
        delete[] data;
        data = temp_data;
        cap = new_cap;
    }

public:
    //empty
    Vector() = default; //this is a default constructor

    //Adding a destriuctor
    ~Vector(){
        delete[] data;
    }

    //copy constructor
    Vector(const Vector& other){
        if(this  != &other){
            delete[] data;
            cap = other.cap;
            sz = other.sz;
            data = new T[cap];
            for(int k=0; k < sz; k++){
                data[k] = other.data[k];
            }
        }
    }

    //copyinng assignment operator 
    Vector& operator=(const Vector& other){
        if(this != &other){
            delete[] data;
            cap = other.cap;
            sz = other.sz;
            data = new T[cap];
            for(int k=0; k < sz; k++){
                data[k] = other.data[k];
            }
        }
        return *this;
    }


    //capacity
    int capacity() const{
        return cap;
    }

    //elements stored
    int size() const{
        return sz;
    }
    // True is empty
    bool empty() const {
        return sz == 0;
    }
    
    //element at index when vector is const
    const T& operator[](int i) const{
        return data[i];
    }
    
    //element at index when vector is non-const
    T& operator[](int i){
        return data[i];
    }

    // at function for const
    const T& at(int i) const{
        if(i < 0 || i >= sz){
            throw std::out_of_range("Index is out of range");
        }
        return data[i];
    }
    
    // at function for non const
    T& at(int i){
        if(i < 0 || i >= sz){
            throw std::out_of_range("Index is out of range");
        }
        return data[i];
    }
    
    // first element
    const T& front() const{
        return data[0];
    }

    // first element
    T& front(){
        return data[0];
    }
    
    // last element
    const T& back() const{
        return data[sz-1];
    }

    // last element
    T& back(){
        return data[sz-1];
    }

    // insert at end
    void push_back(const T& elem){
        if (sz == cap){
            int new_cap = std::max(1, 2*cap);
            reallocate(new_cap);
        }
        data[sz] = elem;
        sz++;
    }

    // remove from end
    void pop_back(){
        if (sz > 0){
            sz--;
            if (sz <= cap/4){
                shrink();
            }
        }
    }

    // insert at index
    void insert(int i, const T& elem){
        if(i < 0 || i > sz){
            throw std::out_of_range("Index is out of range");
        }

        if (sz == cap){
            int new_cap = std::max(1, 2*cap);
            reallocate(new_cap);
        }
        for(int k = sz; k > i; k--){
            data[k] = data[k-1];
        }
        data[i] = elem;
        sz++;
    }

    // removes at index
    void erase(int i){
        if(i < 0 || i >= sz){
            throw std::out_of_range("Index is out of range");
        }
        for(int k = i; k < sz-1; k++){
            data[k] = data[k+1];
        }
        sz--;
        if (sz <= cap/4){
            shrink();
        }
    }

    //capacity >= minimum
    void reserve(int minimum){
        if (cap < minimum){
            T* temp_data = new T[minimum];
            for (int k=0; k < sz ;k++){
                temp_data[k] = data[k];
            }
            delete[] data;
            data = temp_data;
            cap = minimum;
        }
    }

    // called by other functions to reduce cap by half 
    // when sz <= cap/4 
    void shrink(){
        if(cap > 0 && sz <= cap/4){
            int new_cap = std::max(1, cap/2);
            reallocate(new_cap);
        }   

    }
    
    // explicitly reduce the cap to sz and keep at least 1 slot
    void shrink_to_fit(){
        if(cap > sz){
            int new_cap = std::max(1, sz);
            reallocate(new_cap);
        }
    }

}; //end class Vector
}//end namespace dsa

