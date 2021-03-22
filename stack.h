/*
 * An implementation of a generic stack using a singly linked list
 * The core fields of the stacks are:
 * list -> The singly linked list which acts as a LIFO (Last In First Out)
 *         container where the last end of the linked list is top of the stack
 * minMap -> The singly linked list which acts as a seperate stack
 *          to keep track of the smallest element of the main stack
 */

#pragma once
#include "singly.h"
#include "singly.cpp"

template <typename T>
class Stack
{
    Singly<T> *list;    // The singly linked list which acts as a LIFO stack
    Singly<T> *minMap;  // The LIFO stack that keeps track of the min value of the main stack
public:
    Stack();
    Singly<T> getList();
    void setList(Singly<T> newList);
    Singly<T>* getMinMap();
    void setMinMap(Singly<T> newMinMap);
    void push(T data);
    T pop();
    T Peek();
    bool isEmpty();
    Stack<T> sortStack();
};
