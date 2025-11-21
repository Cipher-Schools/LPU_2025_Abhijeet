//
// Created by Abhijeet kumar jha  on 17/11/25.
//

#include "custom_stl.h"

template <typename T>

class custom_vector {
private :
    T * arr ;
    int size ;
    int i ;

    public :
    custom_vector() {
        this->size = 10;
        this->arr = new T[this->size] ;
        this->i =0 ;
    }

    void resize() {
        this->size *= 2 ;
        this->arr = new T[this->size] ;
    }

    void push(T x) {
        if (this->i == this->size - 1) {
            this->resize() ;
        }
        this->arr[i++] = x;
    }

    void pop() {
        this->arr[--i]  ;
    }

    T get(int index) {
        return this->arr[index];
    }


};

int main() {
   custom_vector<int> v ;
    v.push(10);
    v.push(20);
    v.push(30);

}