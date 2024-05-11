//
// Created by Matthew Dylewski on 2/6/22.
//

#ifndef LAB_3_ABQ_H
#define LAB_3_ABQ_H
#include <iostream>
using namespace std;
template<typename T>
class ABQ{
private:
    unsigned int capacity = 1;
    unsigned int size = 0;
    T* line;
    float scale_factor = 2.0f;
public:
    ABQ();
    ABQ(int capacity);
    ABQ(const ABQ &d);
    ABQ &operator=(const ABQ &d);
    ~ABQ();
    void enqueue(T data);
    T dequeue();
    T peek();
    unsigned int getSize();
    unsigned int getMaxCapacity();
    T* getData();
    void SetData(const ABQ &d);
    T* array(const ABQ &d, int size);
};
#endif //LAB_3_ABQ_H
template<typename T>
ABQ<T>::ABQ(){
    line = new T[capacity];
}
template<typename T>
ABQ<T>::ABQ(int capacity){
    this->capacity = capacity;
    line = new T[this->capacity];
}
template<typename T>
ABQ<T>::ABQ(const ABQ<T> &d){
    delete[] line;
    this-> capacity = d.capacity;
    this->size = d.size;
    line = new T[capacity];
    for(unsigned int i = 0; i < size; i++){
        line[i] = d.line[i];
    }
}
template<typename T>
void ABQ<T>::SetData(const ABQ<T> &d){
    this-> capacity = d.capacity;
    this->size = d.size;
    delete[] line;
    line = new T[capacity];
    for(unsigned int i = 0; i < size; i++){
        line[i] = d.line[i];
    }
}
template<typename T>
ABQ<T>& ABQ<T>::operator=(const ABQ<T> &d){
    delete[] line;
    SetData(d);
}
template<typename T>
ABQ<T>::~ABQ(){
    delete[] line;
}
template<typename T>
void ABQ<T>::enqueue(T data){
    if(size == capacity){
        capacity*=scale_factor;
        T* newArray = new T[capacity];
        for(unsigned int i = 0; i < size; i++){
            newArray[i+1] = line[i];
        }
        delete[] line;
        line = newArray;
    }
    else if(size > 0){
        T* newArray = new T[capacity];
        for(unsigned int i = 0; i < size; i++){
            newArray[i+1] = line[i];
        }
        delete[] line;
        line = newArray;
    }
    size++;
    line[0] = data;
}
template<typename  T>
T ABQ<T>::dequeue(){
    if(size == 0){
        throw runtime_error("An error has occured.");
    }
    size--;
    if((float)size/(float)capacity < (float)1/scale_factor){
        capacity/=scale_factor;
    }
    return line[size];
}
template<typename T>
T ABQ<T>::peek(){
    if(size == 0){
        throw runtime_error("An error has occured.");
    }
    return line[size-1];
}
template<typename T>
unsigned int ABQ<T>::getSize(){
    return size;
}
template<typename T>
unsigned int ABQ<T>::getMaxCapacity(){
    return capacity;
}
template<typename T>
T* ABQ<T>::getData(){
    return line;
}
