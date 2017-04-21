#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "List.h"
#include "Node.h"
#include <vector>

template <class T>
class LinkedList : public List<T>
{
private:
   Node<T>* headPtr;
   Node<T>* tailPtr;
   int count;

   Node<T>* getPointerTo(const T& item) const;

public:
   LinkedList();

   LinkedList(const LinkedList<T>& other);

   ~LinkedList();

   LinkedList<T>& operator=(const LinkedList<T>& other);

   virtual void add(const T& item);

   virtual bool remove(const T& item);

   virtual int size() const;

   virtual bool empty() const;

   virtual bool contains(const T& item) const;

   virtual void clear();

   virtual std::vector<T> toVector() const;
};

template <class T>
LinkedList<T>::LinkedList() : headPtr(nullptr), tailPtr(nullptr), count(0)
{

}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& other) :
      count(other.count)
{
   Node<T>* otherPtr = other.headPtr;
   Node<T>* thisPtr = nullptr;
   Node<T>* prevPtr = nullptr;
   while (otherPtr != nullptr)
   {
      thisPtr = new Node<T>(otherPtr->getItem(), nullptr, prevPtr);
      if (otherPtr == other.headPtr)
      {
         headPtr = thisPtr;
      } 
      else
      {  // if implemented correctly, prevPtr != nullptr at this point
         prevPtr->setNext(thisPtr);
      }

      prevPtr = thisPtr;
      otherPtr = otherPtr->getNext();
   }
   tailPtr = thisPtr;
}

template <class T>
LinkedList<T>::~LinkedList()
{
   clear();
}

//TODO can you just use the assignment operator in the copy constructor or vice versa?
template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other)
{
   clear();

   Node<T>* otherPtr = other.headPtr;
   Node<T>* thisPtr = nullptr;
   Node<T>* prevPtr = nullptr;
   while (otherPtr != nullptr)
   {
      thisPtr = new Node<T>(otherPtr->getItem(), nullptr, prevPtr);
      if (otherPtr == other.headPtr)
      {
         headPtr = thisPtr;
      } 
      else
      {  // if implemented correctly, prevPtr != nullptr at this point
         prevPtr->setNext(thisPtr);
      }

      prevPtr = thisPtr;
      otherPtr = otherPtr->getNext();
   }
   tailPtr = thisPtr;

   return *this;
}

template <class T>
Node<T>* LinkedList<T>::getPointerTo(const T& item) const
{
   Node<T>* curPtr = headPtr;
   while (curPtr != nullptr)
   {
      if (curPtr->getItem() == item)
      {
         return curPtr;
      }
      else
      {
         curPtr = curPtr->getNext();
      }
   }

   return nullptr;
}

//TODO add to Doxygen documentation: type T MUST have a fully working copy constructor, as Node will make a copy of the item to prevent memory errors
template <class T>
void LinkedList<T>::add(const T& item)
{
   Node<T>* newNode = new Node<T>(item, nullptr, nullptr);
   if (headPtr == nullptr)
   {
      headPtr = newNode;
      count = 1;   
   }
   else
   {
      Node<T>* curPtr = headPtr;
      while(curPtr->getNext() != nullptr)
      {
         curPtr = curPtr->getNext();
      }
      curPtr->setNext(newNode);
      newNode->setPrev(curPtr);
      count++;
   }

   tailPtr = newNode;
}

template <class T>
bool LinkedList<T>::remove(const T& item)
{
   Node<T>* toRemove = getPointerTo(item);
   if (toRemove != nullptr)
   {
      if (toRemove == headPtr)
      {
         headPtr = toRemove->getNext();
      }
      else
      {
         toRemove->getPrev()->setNext(toRemove->getNext());
         if (toRemove->getNext() != nullptr)
         {
            toRemove->getNext()->setPrev(toRemove->getPrev());
         }        
      }

      if (toRemove == tailPtr)
      {
         tailPtr = toRemove->getPrev();
      }

      count--;
      delete toRemove;
      toRemove = nullptr;
      return true;
   }
   else
   {
      return false;
   }
}

template <class T>
int LinkedList<T>::size() const
{
   return count;
}

template <class T>
bool LinkedList<T>::empty() const
{
   return count == 0;
}

template <class T>
bool LinkedList<T>::contains(const T& item) const
{
   if (getPointerTo(item) != nullptr)
   {
      return true; 
   } 
   else
   {
      return false;
   }
}

template <class T>
void LinkedList<T>::clear()
{
   Node<T>* curPtr = headPtr;
   while (curPtr != nullptr)
   {
      Node<T>* nextPtr = curPtr->getNext();
      delete curPtr;
      curPtr = nextPtr;
      count--;
   }
   headPtr = nullptr;
   tailPtr = nullptr;
}

template <class T>
std::vector<T> LinkedList<T>::toVector() const
{
   std::vector<T> vec;
   if (!empty())
   {
      Node<T>* curPtr = headPtr;
      while(curPtr != nullptr)
      {
         vec.push_back(curPtr->getItem());
         curPtr = curPtr->getNext();
      }
   }

   return vec;
}

#endif
