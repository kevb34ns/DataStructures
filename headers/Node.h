#ifndef NODE_H
#define NODE_H

template <class T>
class Node
{
private:
   const T item;
   Node<T>* nextPtr;
   Node<T>* prevPtr;

public:
   Node(const T item, Node<T>* nextPtr, Node<T>* prevPtr);

   virtual ~Node();

   virtual const T& getItem() const;

   virtual Node<T>* getNext() const;

   virtual void setNext(Node<T>* nextPtr);   

   virtual Node<T>* getPrev() const;

   virtual void setPrev(Node<T>* prevPtr);
};

template <class T>
Node<T>::Node(const T item, Node<T>* nextPtr, Node<T>* prevPtr)
   : item(item), nextPtr(nextPtr), prevPtr(prevPtr)
{

}

template <class T>
Node<T>::~Node()
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

template <class T>
Node<T>* Node<T>::getPrev() const
{
   return prevPtr;
}

template <class T>
void Node<T>::setPrev(Node<T>* prevPtr)
{
   this->prevPtr = prevPtr;
}

#endif
