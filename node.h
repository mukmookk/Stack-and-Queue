/*
* Implentation of a generic Node class which is used in a Singly Linked List
* This node Consists of:
* data -> This field is in the form of a generic type T. (Note that we should always overlaod the required operators required for whatever operations that we need)
* next -> A pointer to the next node of 'this' in the data structure. This field is contained in both Singly as well as Doubly Linked List.
*/

#pragma once
#include <iostream>

template <typename T>
class Node
{
protected:
    T data;         // Geneic data of the Node
    Node <T> *next; // Next pointer of 'this' in the linked list 

public:
    Node();
    Node(T data);
    T getData();
    void setData(T newData);
    Node<T> *getNext();
    void setNext(Node<T> *newNext);
};
