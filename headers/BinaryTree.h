#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "BinaryTreeNode.h"

template <class T>
class BinaryTree
{
private:
   BinaryTreeNode<T>* rootPtr;

protected:
   virtual int treeHeightHelper(BinaryTreeNode<T>* subTreePtr) const;

   virtual int numNodesHelper(BinaryTreeNode<T>* subTreePtr) const;

   virtual void destroyTree(BinaryTreeNode<T>* subTreePtr);

   virtual BinaryTreeNode<T>* balancedAdd(BinaryTreeNode<T>* subTreePtr,
      BinaryTreeNode<T>* newNodePtr);

   virtual BinaryTreeNode<T>* removeValue(BinaryTreeNode<T>* subTreePtr,
      const T target, bool& success);

   virtual BinaryTreeNode<T>* moveValuesUpTree(BinaryTreeNode<T>* subTreePtr);

   virtual BinaryTreeNode<T>* findNode(BinaryTreeNode<T>* treePtr, 
      const T& target, bool& success) const;

   virtual BinaryTreeNode<T>* copyTree(const BinaryTreeNode<T>* treePtr);

   // Traversal helper methods
   virtual void preorderHelper(void (* visit)(T&), BinaryTreeNode<T>* treePtr) const;
   virtual void inorderHelper(void (* visit)(T&), BinaryTreeNode<T>* treePtr) const;
   virtual void postorderHelper(void (* visit)(T&), BinaryTreeNode<T>* treePtr) const;

public:
   // Constructors
   BinaryTree();
   BinaryTree(const T& rootItem);
   BinaryTree(const T& rootItem, 
      const BinaryTree<T>* leftSubTreePtr,
      const BinaryTree<T>* rightSubTreePtr);
   BinaryTree(const BinaryTree<T>& other);

   virtual ~BinaryTreeNode();

   // Overloaded operators
   virtual BinaryTreeNode<T>& operator=(const BinaryTreeNode<T>& other);

   virtual bool empty() const;

   virtual int getTreeHeight() const;

   virtual int getNumNodes() const;

   virtual const T& getRootData() const;

   virtual void setRootData(const T& rootItem);

   virtual bool add(const T& item);

   virtual bool remove(const T& item);

   virtual bool contains(const T& item);

   virtual void clear();

   // Traversal operations
   virtual void preorderTraverse(void (* visit)(T&)) const; 
   virtual void inorderTraverse(void (* visit)(T&)) const;
   virtual void postorderTraverse(void (* visit)(T&)) const;
   
};

template <class T>
BinaryTree<T>::BinaryTree() : rootPtr(nullptr)
{

}

template <class T>
BinaryTree<T>::BinaryTree(const T& rootItem)
{
   rootPtr = new BinaryTreeNode(rootItem);
}

template <class T>
BinaryTree<T>::BinaryTree(const T& rootItem, 
      const BinaryTree<T>* leftSubTreePtr,
      const BinaryTree<T>* rightSubTreePtr)
{
   rootPtr= new BinaryTreeNode(rootItem, leftSubTreePtr, rightSubTreePtr);
}

template <class T>
BinaryTree<T>::(const BinaryTree<T>& other)
{
   //TODO
}

template <class T>
BinaryTree<T>::~BinaryTree()
{
   
}

template <class T>
BinaryTreeNode<T>& BinaryTree<T>::operator=(const BinaryTreeNode<T>& other)
{
   
}

template <class T>
bool BinaryTree<T>::empty() const
{
   return rootPtr == nullptr;
}

template <class T>
int BinaryTree<T>::treeHeightHelper(BinaryTreeNode<T>* subTreePtr) const
{
   
}

template <class T>
int BinaryTree<T>::getTreeHeight() const
{
   return treeHeightHelper(rootPtr);
}

template <class T>
int BinaryTree<T>::numNodesHelper(BinaryTreeNode<T>* subTreePtr) const
{
   
}

template <class T>
int BinaryTree<T>::getNumNodes() const
{
   return numNodesHelper(rootPtr);
}

template <class T>
const T& BinaryTree<T>::getRootData() const
{
   if (empty())   
   {
      //TODO throw appropriate exception
   }
   else
   {
      return rootPtr->getItem();
   }
}

template <class T>
void BinaryTree<T>::setRootData(const T& rootItem)
{
   if (empty())   
   {
      //TODO throw appropriate exception
   }
   else
   {
      rootPtr->setItem(rootItem);
   }
}

template <class T>
BinaryTreeNode<T>* BinaryTree<T>::balancedAdd(BinaryTreeNode<T>* subTreePtr,
   BinaryTreeNode<T>* newNodePtr)
{
   
}

template <class T>
bool BinaryTree<T>::add(const T& item)
{
   
}

template <class T>
BinaryTreeNode<T>* BinaryTree<T>::removeValue(BinaryTreeNode<T>* subTreePtr,
   const T& target, bool& success)
{
   
}

template <class T>
BinaryTreeNode<T>* BinaryTree<T>::moveValuesUpTree(
   BinaryTreeNode<T>* subTreePtr)
{
   
}

template <class T>
bool BinaryTree<T>::remove(const T& item)
{
   
}

template <class T>
BinaryTreeNode<T>* BinaryTree<T>::findNode(BinaryTreeNode<T>* treePtr,
   const T& target, bool& success) const
{
   
}

template <class T>
bool BinaryTree<T>::contains(const T& item)
{
   
}

template <class T>
void BinaryTree<T>::destroyTree(BinaryTreeNode<T>* subTreePtr, 
   BinaryTreeNode<T>* newNodePtr)
{
   
}

template <class T>
void BinaryTree<T>::clear()
{
   
}

template <class T>
BinaryTreeNode<T>* BinaryTree<T>::copyTree(const BinaryTreeNode<T>* treePtr)
{
   
}

template <class T>
void BinaryTree<T>::preorderHelper(void (* visit)(T&), 
   BinaryTreeNode<T>* treePtr) const
{
   
}

template <class T>
void BinaryTree<T>::inorderHelper(void (* visit)(T&), 
   BinaryTreeNode<T>* treePtr) const
{
   
}

template <class T>
void BinaryTree<T>::postorderHelper(void (* visit)(T&), 
   BinaryTreeNode<T>* treePtr) const
{
   
}

template <class T>
void BinaryTree<T>::preorderTraverse(void (* visit)(T&)) const
{
   
}

template <class T>
void BinaryTree<T>::inorderTraverse(void (* visit)(T&)) const
{
   
}

template <class T>
void BinaryTree<T>::postorderTraverse(void (* visit)(T&)) const
{
   
}


#endif
