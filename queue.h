#pragma once
#include "Singly.h"

template<typename T>
class Queue
{
protected:
    Singly<T> *list;

public:
    Queue();
    Singly<T>* getList();
    void setList(Singly<T>* newList);
    void Enqueue(T data);
    T Dequeue();
    T peek();
    bool isEmpty();
};