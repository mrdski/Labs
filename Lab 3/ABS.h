//
// Created by Matthew Dylewski on 2/5/22.
//

#ifndef LAB_3_ABS_H
#define LAB_3_ABS_H
#include <iostream>
using namespace std;
template<typename T>
class ABS{
private:
    unsigned int capacity = 1;
    unsigned int size = 0;
    T* line;
    float scale_factor = 2.0f;
public:
    ABS();
    ABS(int capacity);
    ABS(const ABS &d);
    ABS &operator=(const ABS &d);
    ~ABS();
    void push(T data);
    T peek();
    T pop();
    unsigned int getSize();
    unsigned int getMaxCapacity();
    T* getData();
    void SetData(const ABS &d);
};

#endif //LAB_3_ABS_H
template<typename T>
ABS<T>::ABS(){
    line = new T[capacity];
}
template<typename T>
ABS<T>::ABS(int capacity){
    this->capacity = capacity;
    line = new T[this->capacity];
}
template<typename T>
ABS<T>::ABS(const ABS<T> &d){
    delete[] line;
    this-> capacity = d.capacity;
    this->size = d.size;
    line = new T[capacity];
    for(unsigned int i = 0; i < size; i++){
        line[i] = d.line[i];
    }
}
template<typename T>
void ABS<T>::SetData(const ABS<T> &d){
    this-> capacity = d.capacity;
    this->size = d.size;
    delete[] line;
    line = new T[capacity];
    for(unsigned int i = 0; i < size; i++){
        line[i] = d.line[i];
    }
}
template<typename T>
ABS<T>& ABS<T>::operator=(const ABS<T> &d){
    delete[] line;
    SetData(d);

}
template<typename T>
ABS<T>::~ABS(){
    delete[] line;
}
template<typename T>
void ABS<T>::push(T data){
    if(size == capacity){
        capacity*=scale_factor;
        T* newArray = new T[capacity];
        for(unsigned int i = 0; i < size; i++){
            newArray[i] = line[i];
        }
        delete[] line;
        line = newArray;
    }
    else if(size > 0){
        T* newArray = new T[capacity];
        for(unsigned int i = 0; i < size; i++){
            newArray[i] = line[i];
        }
        delete[] line;
        line = newArray;
    }
    size++;
    line[size-1] = data;
}
template<typename  T>
T ABS<T>::pop(){
    if(size == 0){
        throw runtime_error("An error has occured.");
    }
    size--;
    if((float)size/(float)capacity < 1/scale_factor){
        capacity/=scale_factor;
    }
    return line[size];
}
template<typename T>
T ABS<T>::peek(){
    if(size == 0){
        throw runtime_error("An error has occured.");
    }
    return line[size-1];
}
template<typename T>
unsigned int ABS<T>::getSize(){
    return size;
}
template<typename T>
unsigned int ABS<T>::getMaxCapacity(){
    return capacity;
}
template<typename T>
T* ABS<T>::getData(){
    return line;
}
