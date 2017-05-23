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
   virtual void preorderHelper(void (* visit)(T&), BinaryTreeNode<T>* treePtr);
   virtual void inorderHelper(void (* visit)(T&), BinaryTreeNode<T>* treePtr);
   virtual void postorderHelper(void (* visit)(T&), BinaryTreeNode<T>* treePtr);

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
   virtual BinaryTreeNode& operator=(const BinaryTreeNode<T>& other);

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


#endif
