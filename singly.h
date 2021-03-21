/* 
 * An implementation of a generic LinkedList class which constructs a singly linked list
 * where each Node of the Linked list is the generic Node class defined in the headers.
 * This Linked list consists of two fields
 * size -> The current size of the linked list.
 * head -> The pointer to the head Node of this Linked List.
 * 
 * The reason why we use a singly linked list for the implementation of a stack is that a 
 * doubly linked list has more overheads than a singly linked list as we have to store two pointers in a doubly linked List
 * compare to one pointer in a singly linked list.
 * The only motivation for using a doubly linked list is that it offers constant time insertion and deletion of middle node.
 * Since a stack is only concerned about insertion O(1) and deletion O(n) at end,
 * so we proceed with a singly linked list and use a tail pointer to point at the end of the linked list.
 */
 
#pragma once
#include "Node.h"
#include "Node.cpp"

template <typename T>
class Singly
{
    Node<T> *head;              // The head node of the linked list
    Node<T> *tail;              // The tail node of the linked list

    int size;

    Node<T> *getBeforeLast();   // A private helper function to get the penulimate node of the linked list.

public:
    Singly();
    Node<T> *getHead();
    Node<T> *getTail();
    int getSize();
    Node<T>* getBeforeLast()
    void setHead(Node<T> *newHead);
    void setTail(Node<T> *newTail);
    Node<T> *getLast();
    void addEnd(T data);
    void addStart(T data);
    void deleteEnd();
    void deleteStart();
};