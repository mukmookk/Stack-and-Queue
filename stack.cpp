/*
 * An Implementation of a generic stack using a Singly Linked List
 * The core fields of the stack are:
 * List -> The singly linked list which acts as a LIFO (last in first out)
 *          container where the last end of the linked list is top of the stack
 * minMap -> The singly linked list which acts as as seperate stack to keep track 
 *          of the smallest element of the main stack.
 */

#include "stack.h"

/*
 * Explicit instantiation for int class
 */
template class Node<int>;
template class Singly<int>;
template class Stack<int>;


/* Default constructor to initialize the two singly linked lists */
template <typename T>
Stack<T>::Stack()
{
    list = new Singly<T>();
    minMap = new Singly<T>();
}

/*
 * Getter for the Singly Linked List which is used as a stack
 * @return list -> The Singly linked list used as a stack
 */
template <typename T>
Singly<T>* Stack<T>::getList()
{
    return list;
}

template <typename T>
Singly<T>* Stack<T>::getMinMap()
{
    return minMap;
}

/*
 * Function to pop the data present at top of the stack
 * @return topData -> return NULL if popping an empty stack
 *                      return top of the stack and remove the top element from the stack
 */
template <typename T>
T Stack<T>::pop()
{
    if (isEmpty())
    {
        cerr << "Attempting to pop an empty stack. Returning NULL \n" << endl;
        return NULL;
    }
    else
    {
        T topData = list->getTail()->getData();
        if (topData == minMap->getTail()->getData())
        {
            minMap->delteEnd();
        }
        list->deleteEnd();
        return topData;
    }
}

/*
 * Function to peek at the data present at top of the stack
 * @return topData -> return NULL if peeking an empty stack
 *                      return top of the stack
 */

template <typename T>
T Stack<T>::peek()
{
    if(isEmpty())
    {
        return NULL;
    }
    else 
    {
        T topData = list->getTail()->getData();
        return topData;
    }
}

/*
 * Function to check if the stack is empty or not
 * @return true if stack is empty, false otherwise
 */
template <typename T>
bool Stack<T>::isEmpty()
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

/*
 * Function that returns the minimum element of the stack
 * @return min -> The minimum element on the stack
 */
template <typename T>
T Stack<T>::getmin()
{
    if (list->getHead() == nullptr)
    {
        cerr << "Called min on an empty stack. Returning NULL \n";
        return NULL;
    }
    T min = minMap->getTail()->getData();
    return min;
}

/*
 * A function that sorts a stack without using any additional data structure except another stack
 * @return temp -> The sorted stack
 */
template <typename T>
Stack<T>* Stack<T>::sortStack()
{
    Stack<T>* temp = new Stack();
    int count = 0;
    while (!isEmpty())
    {
        T data = this->pop();
        if (temp->isEmpty())
        {
            temp->push(data);
        }
        else
        {
            while (temp->peek() > data && !(temp->isEmpty()))
            {
                T data_temp = temp->pop();
                count++;
                push(data_temp);
            }
            temp->push(data);
            while (count > 0)
            {
                T newData = pop();
                temp->push(newData);
                count--;
            }
        }
        count = 0;
    }
    return temp;
}