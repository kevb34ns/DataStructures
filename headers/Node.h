#ifndef NODE_H
#define NODE_H

template <class T>
class Node
{
private:
   const T& item;
   Node<T>* nextPtr;

public:
   Node(const T& item, Node<T>* nextPtr);

   virtual const T& getItem() const;

   virtual Node<T>* getNext() const;

   virtual void setNext(Node<T>* nextPtr);   
};

template <class T>
Node<T>::Node(const T& item, Node<T>* nextPtr)
   : item(item), nextPtr(nextPtr)
{

}

template <class T>
const T& Node<T>::getItem() const
{
   return item;
}

template <class T>
Node<T>* Node<T>::getNext() const
{
   return nextPtr;
}

template <class T>
void Node<T>::setNext(Node<T>* nextPtr)
{
   this->nextPtr = nextPtr;
}

#endif
