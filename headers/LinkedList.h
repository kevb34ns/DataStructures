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
   int count;

   const Node<T>* getPointerTo(const T& item) const;

public:
   LinkedList();

   ~LinkedList();

   virtual void add(const T& item);

   virtual bool remove(const T& item);

   virtual int size() const;

   virtual bool empty() const;

   virtual bool contains(const T& item) const;

   virtual void clear();

   virtual std::vector<T> toVector() const;
};

template <class T>
LinkedList<T>::LinkedList() : headPtr(nullptr), count(0)
{

}

template <class T>
LinkedList<T>::~LinkedList()
{
   clear();
}

template <class T>
const Node<T>* LinkedList<T>::getPointerTo(const T& item) const
{
   return nullptr;
}

template <class T>
void LinkedList<T>::add(const T& item)
{
   //TODO should be making a copy of 'item' to prevent The Calamity from ever happening again.
   Node<T>* newNode = new Node<T>(item, nullptr);
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
      count++;
   }
}

template <class T>
bool LinkedList<T>::remove(const T& item)
{
   return false;
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
   return false;
}

template <class T>
void LinkedList<T>::clear()
{

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
