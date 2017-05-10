#include "Node.h"
#include <stdexcept>

template <class T>
class Queue
{
private:
   // circular back pointer (backPtr->getNext() is the 'front')
   Node<T>* backPtr;

public:
   Queue();

   Queue(const Queue<T>& other);

   ~Queue();

   Queue<T>& operator=(const Queue<T>& other);

   virtual bool push(const T& item);

   virtual bool pop();

   virtual const T& front() const;

   virtual bool empty() const;

   virtual void clear();
};

template <class T>
Queue<T>::Queue()
{
   backPtr = nullptr;
}

template <class T>
Queue<T>::Queue(const Queue<T>& other)
{
   *this = other;
}

template <class T>
Queue<T>::~Queue()
{
   clear();
}

template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other)
{
   clear();

   Node<T>* otherPtr = other.backPtr;
   if (otherPtr == nullptr)
   {
      return *this;
   }

   Node<T>* thisPtr = nullptr;
   Node<T>* prevPtr = nullptr;
   do
   {
      thisPtr = new Node<T>(otherPtr->getItem(), nullptr, nullptr);
      thisPtr->setNext(thisPtr);
      prevPtr = thisPtr;
      otherPtr = otherPtr->getNext();

   } while (otherPtr != other.backPtr);

   return *this;
}

template <class T>
bool Queue<T>::push(const T& item)
{
   if (backPtr == nullptr)
   {
      backPtr = new Node<T>(item, nullptr, nullptr);
      backPtr->setNext(backPtr);
   }
   else
   {
      Node<T>* tempPtr = backPtr;
      backPtr = new Node<T>(item, tempPtr->getNext(), nullptr);
      tempPtr->setNext(backPtr);
   }
   return true;
}

template <class T>
bool Queue<T>::pop()
{
   if (empty())
   {
      return false;
   }

   if (backPtr->getNext() == backPtr)
   {
      // only one item in the queue
      clear();
   }
   else
   {
      Node<T>* tempPtr = backPtr->getNext();
      backPtr->setNext(tempPtr->getNext());
      delete tempPtr;
      tempPtr = nullptr;   
   }

   return true;
}

template <class T>
const T& Queue<T>::front() const
{
   if (empty())
   {
      throw std::range_error("Attempt to call Queue<T>::front() on an empty queue.");
   }

   return backPtr->getNext()->getItem();
}

template <class T>
bool Queue<T>::empty() const
{
   return backPtr == nullptr;
}

template <class T>
void Queue<T>::clear()
{
   if (backPtr == nullptr)
   {
      return;
   }

   Node<T>* curPtr = backPtr->getNext();
   while (curPtr != backPtr)
   {
      Node<T>* tempPtr = curPtr->getNext();
      delete curPtr;
      curPtr = tempPtr;
   }
   delete backPtr;
   backPtr = nullptr;
}
