/*
 * Implentation of a generic Node class which is used in a Singly Linked List
 * This node Consists of:
 * data -> This field is in the form of a generic type T. (Note that we should always overlaod the required operators required for whatever operations that we need)
 * next -> A pointer to the next node of 'this' in the data structure. This field is contained in both Singly as well as Doubly Linked List.
*/

#include "Node.h"

/* Defulat constructor of the class 'Node' */
template <typename T>
Node<T>::Node()
{
    data = NULL;
    next = nullptr;
}

/* 
 * Parameterized constructor of the class 'Node' 
 * @Param newData -> The data to be contained in the node.
 */
template <typename T>
Node<T>::Node(T newData)
{
    data = newData;
    next = nullptr;
}

/* 
 * Getter for the data in the Node.
 * @return data -> The data contained in the Node class.
 */ 
template <typename T>
T Node<T>::getData()
{
    return data;
}

/*
 * Setter for the data in the Node.
 * @param newData -> The data to be inserted into the Node.
 */
template <typename T>
void Node<T>::setData(T newData)
{
    data = newData;
}

/* 
 * Getter for next pointer of this Node
 * @return next -> A pointer to the next Node.
 */
template <typename T>
Node<T> *Node<T>:: getNext()
{
    return next;
}

template <typename T>
void Node<T>::setNext(Node<T> *newNext)
{
    next = newNext;
}