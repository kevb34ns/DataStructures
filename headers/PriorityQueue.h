/**
 * A priority queue implementation using an underlying heap.
 */

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "Heap.h"

template<class T>
class PriorityQueue : private Heap<T>
{
public:
    PriorityQueue();

    virtual ~PriorityQueue();

    virtual bool isEmpty() const;

    virtual bool add(const T& item);

    virtual bool remove();

    virtual const T& peek() const;

    virtual void clear();
};

template <class T>
PriorityQueue<T>::PriorityQueue()
{

}

template <class T>
PriorityQueue<T>::~PriorityQueue()
{

}

template <class T>
bool PriorityQueue<T>::isEmpty()
{
    return Heap::isEmpty();
}

template <class T>
bool PriorityQueue<T>::add(const T& item)
{
    return Heap::add(item);
}

template <class T>
bool PriorityQueue<T>::remove()
{
    return Heap::remove();
}

template <class T>
const T& PriorityQueue<T>::peek()
{
    return Heap::peekTop();
}

template <class T>
void PriorityQueue<T>::clear()
{
    Heap::clear();
}

#endif
