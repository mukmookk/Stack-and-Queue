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

#include <singly.h>

/* Default constructor of the singly class */
template <typename T>
Singly<T>::Singly()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

/*
 * Getter for the head node of the linked list
 * @return head -> the head node of the linked list
 */
template <typename T>
Node<T>* Singly<T>::getHead()
{
    return head;
}

/*
 * Setter for the head node of the Linked List.
 * @param newHead -> A pointer to teh Node that is to be set as the haed node of the linked list
 */
template <typename T>
void Singly<T>::setHead(Node<T> *newHead)
{
    head = newHead;
}

/*
 * Getter for the tail node of the linked List.
 * @return tail -> The tail node of the Linked List
 */
template <typename T>
Node<T>* Singly<T>::getTail()
{
    return tail;
}

/*
 * Setter for the tail node of the Linked List
 * @param newTail -> A pointer to the node that is to be set as the tail of the linked list
 */
template <typename T>
void Singly<T>::setTail(Node<T> *newtail)
{
    tail = newTail;
}
/*
 * Getter for the size of the Linked List.
 * @return size -> The size of the Linked List
 */
template <typename T>
int Singly<T>::getSize()
{
    return size;
}

/*
 * A function that adds a node to the end of the Linked List.
 * @param data -> The data that is contained in the node to be added to the end
 * The function takes care of creting a Node from the data
 */
template <typename T>
void Singly<T>::addEnd(T data)
{
    Node<T> *n_node = new Node<T>(data);
    if (head == nullptr)
    {
        head = n_node;
        tail = n_node;
        size++;
    }
    else
    {
        tail->setNext(n_node);
        tail = n_node;
        size++;
    }
}

/*
 * A function that adds a node to the start of the Linked List.
 * @param data -> The data that is contained in the node to be added to the start
 * The function takes care of creating a Node from the data
 */
template <typename T>
void Singly<T>::addStart(T data)
{
    Node<T> *n_node = new Node<T>(data);
    if (head == nullptr)
    {
        head = n_node;
        tail = n_node;
        size++;
    }
    else
    {
        n_node->setNext(head);
        head = n_node;
        size++;
    }
}

/*
 * A private helper function that gets the penultimate node of the linked list.
 * @return temp -> The penultimate node of the linked list
 */
template <typename T>
Node<T>* Singly<T>::getBeforeLast()
{
    Node<t> *temp = head;
    if (temp->getNext() == nullptr)
    {
        return nullptr;
    }
    while (temp->getNext() != tail)
    {
        temp = temp->getNext();
    }
    return temp;
}

/*
 * A function that gets the ultimate node of the linked list.
 * @return tail -> the tail is the last node of the linked list
 */
template <typename T>
Node<T>* Singly::<T>::getLast()
{
    return tail;
}

/*
 * A function that deletes the end node of the linked list
 */
template<typename T>
void Singly<T>::deleteEnd()
{
    Node *temp = getBeforeLast();
    if (temp == nullptr)        // there is only one node in the list
    {
        delete head;            // destroy and initialize
        delete tail;
        tail = nullptr;
        head = nullptr;
        return;
    }
}

/*
 * A function to delte the first node of the linked list.
 */
template <typename T>
void Singly<T>::deleteStart()
{
    Node<T> *temp = head;
    if (temp == nullptr)
    {
        return;
    }
    else if (temp->getNext() == nullptr)
    {
        delete temp;
        temp = nullptr;
    }
    else
    {
        Node<T> *second = head->getNext();
        delete head;
        head = second;
    }
}