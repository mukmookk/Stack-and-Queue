#include "queue.h"

template class Node<int>;
template class Singly<int>;
template class Queue<int>;

/* An defuault constructor */
template <typename T>
Queue<T>::Queue()
{
    list = new Singly<T>();
}

/*
 * Getter for the singly linked list which acts as a queue
 * @return list -> A pointer to the start of the singly linked list which acts as a queue
 */
template <typename T>
Singly<T>* Queue<T>::getList()
{
    return list;
}

/* 
 * Setter for the Singly linked which acts as a queue
 * @param newList -> A pointer to the start of the singly linked list which acts as s queue
 */
template <typename T>
void Queue<T>::setList(Singly<T>* newList)
{
    list = newList;
}

/*
 * A function to add data to the end of the queue
 * @param data -> The data to be enqueued
 */
template <typename T>
void Queue<T>::Enqueue(T data)
{
    list->addEnd(data);
}

/*
 * A function to remove data from the start of the queue
 * @return val -> The data that has been dequeued
 */
template <typename T>
T Queue<T>::Dequeue()
{
    T val = list->getHead()->getData();
    list->deleteStart();
    return val;
}

/*
 * A function that peeks at the data at the start of the queue.
 * @return val -> The data is the first element of the queue
 */
template <typename T>
T Queue<T>::peek()
{
    T val = list->getHead()->getData();
    return val;
}

/* 
 * A function that checks wheter the queue is empty or not
 * @return true if the queue is empty, false otherwise
 */
template <typename T>
bool Queue<T>::isEmpty()
{
    if (list->getHead() == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}