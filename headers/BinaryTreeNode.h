#ifndef BINARY_TREE_NODE_H
#define BINARY_TREE_NODE_H

template <class T>
class BinaryTreeNode
{
private:
   T item;
   BinaryTreeNode<T>* leftPtr;
   BinaryTreeNode<T>* rightPtr;

public:
   BinaryTreeNode(const T item);

   BinaryTreeNode(const T item, BinaryTreeNode<T>* leftPtr, 
      BinaryTreeNode<T>* rightPtr);

   virtual ~BinaryTreeNode();

   virtual const T& getItem() const;

   virtual void setItem(const T& newItem);

   virtual BinaryTreeNode<T>* getLeft() const;

   virtual BinaryTreeNode<T>* getRight() const;

   virtual void setLeft(BinaryTreeNode<T>* leftPtr);

   virtual void setRight(BinaryTreeNode<T>* rightPtr);
};

template <class T>
BinaryTreeNode<T>::BinaryTreeNode(const T item)
   : item(item), leftPtr(nullptr), rightPtr(nullptr)
{

}

template <class T>
	BinaryTreeNode<T>::BinaryTreeNode(const T item, 
      BinaryTreeNode<T>* leftPtr, 
      BinaryTreeNode<T>* rightPtr)
   : item(item), leftPtr(leftPtr), rightPtr(rightPtr)
{

}

template <class T>
BinaryTreeNode<T>::~BinaryTreeNode()
{

}

template <class T>
const T& BinaryTreeNode<T>::getItem() const
{
   return item;
}

template <class T>
void BinaryTreeNode<T>::setItem(const T& newItem)
{
   item = T(newItem);
}

template <class T>
BinaryTreeNode<T>* BinaryTreeNode<T>::getLeft() const
{
   return leftPtr;
}

template <class T>
BinaryTreeNode<T>* BinaryTreeNode<T>::getRight() const
{
   return rightPtr;
}

template <class T>
void BinaryTreeNode<T>::setLeft(BinaryTreeNode<T>* leftPtr)
{
   this->leftPtr = leftPtr;
}

template <class T>
void BinaryTreeNode<T>::setRight(BinaryTreeNode<T>* rightPtr)
{
   this->rightPtr = rightPtr;
}

#endif
