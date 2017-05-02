#include "Node.h"
#include <stdexcept>

template <class T>
class Stack
{
private:
   Node<T>* topPtr;

public:
   Stack();
   Stack(const Stack<T>& other);
   ~Stack();

   Stack<T>& operator=(const Stack<T>& other);

   virtual bool push(const T& item);

   virtual bool pop();

   virtual const T& top() const;

   virtual bool empty() const;

   virtual void clear();

};

template <class T>
Stack<T>::Stack() : topPtr(nullptr)
{

}

template <class T>
Stack<T>::Stack(const Stack<T>& other)
{
   *this = other;
}

template <class T>
Stack<T>::~Stack()
{
   clear();
}

template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
   clear();

   Node<T>* otherPtr = other.topPtr;
   Node<T>* thisPtr = nullptr;
   Node<T>* prevPtr = nullptr;
   while (otherPtr != nullptr)
   {
      thisPtr = new Node<T>(otherPtr->getItem(), nullptr, nullptr);
      if (otherPtr == other.topPtr)
      {
         topPtr = thisPtr;
      }
      else
      {
         prevPtr->setNext(thisPtr);
      }

      prevPtr = thisPtr;
      otherPtr = otherPtr->getNext();
   }

   return *this;
}

template <class T>
bool Stack<T>::push(const T& item)
{
   Node<T>* newTopPtr = new Node<T>(item, topPtr, nullptr);
   topPtr = newTopPtr;
   newTopPtr = nullptr;
   return true;
}

template <class T>
bool Stack<T>::pop()
{
   if (empty())
   {
      return false;
   }

   Node<T>* tempPtr = topPtr;
   topPtr = topPtr->getNext();
   delete tempPtr;
   tempPtr = nullptr;
   return true;
}

template <class T>
const T& Stack<T>::top() const
{
   if (empty())
   {
      throw std::range_error("Attempt to call Stack<T>::top() on an empty stack.");
   }

   return topPtr->getItem();
}

template <class T>
bool Stack<T>::empty() const
{
   return topPtr == nullptr;
}

template <class T>
void Stack<T>::clear()
{
   Node<T>* curPtr = topPtr;
   while (curPtr != nullptr)
   {
      Node<T>* nextPtr = curPtr->getNext();
      delete curPtr;
      curPtr = nextPtr;
   }
   topPtr = nullptr;
}
