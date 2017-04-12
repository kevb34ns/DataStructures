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

//TODO can use this to simplify remove() when you have a doubly-linked list
template <class T>
const Node<T>* LinkedList<T>::getPointerTo(const T& item) const
{
   return nullptr;
}

//TODO add to Doxygen documentation: type T MUST have a fully working copy constructor, as Node will make a copy of the item to prevent memory errors
template <class T>
void LinkedList<T>::add(const T& item)
{
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
   if (headPtr != nullptr)
   {
      Node<T>* curPtr = headPtr;
      Node<T>* prevPtr = nullptr;
      while (curPtr != nullptr)
      {
         if (curPtr->getItem() == item)
         {
            if (prevPtr == nullptr)
            { // the head contains the item to remove
               headPtr = headPtr->getNext();
            }
            else
            {
               prevPtr->setNext(curPtr->getNext());
            }

            count--;
            delete curPtr;
            curPtr = nullptr;
            return true;
         }
         else
         {
            prevPtr = curPtr;
            curPtr = curPtr->getNext();
         }
      }
   }

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
