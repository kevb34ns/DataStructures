#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "BinaryTreeNode.h"
#include "BinaryTree.h"

template <class T>
class BinarySearchTree : private BinaryTree<T>
{
private:
    /**
     * Recursively inserts a new node into the tree, at the correct position as
     * defined by the properties of a binary search tree.
     * @param subtreePtr Pointer to the root of the subtree to insert into.
     * @param newNodePtr Pointer to the node to be inserted.
     * @return A pointer to the root of the subtree.
     */
    virtual BinaryTreeNode<T>* orderedInsert(BinaryTreeNode<T>* subtreePtr,
            BinaryTreeNode<T>* newNodePtr);

    /**
     * TODO doc
     */
    virtual BinaryTreeNode<T>* removeLeftmostNode(BinaryTreeNode<T>* nodePtr,
            T& inorderSuccessor);
    
    /**
     * TODO doc
     */
    virtual BinaryTreeNode<T>* removeNode(BinaryTreeNode<T>* nodePtr);

    /**
     * TODO doc
     */
    virtual BinaryTreeNode<T>* removeHelper(BinaryTreeNode<T>* subtreePtr,
            const T& target, bool& success);


public:
    BinarySearchTree();
    BinarySearchTree(const T& rootItem);
    BinarySearchTree(const BinarySearchTree<T>& other);

    virtual ~BinarySearchTree();

    virtual BinarySearchTree<T>& operator=(const BinarySearchTree<T>& other);
    
    /**
     * TODO doc
     */
    virtual bool add(const T& item);

    /**
     * TODO doc
     */
    virtual bool remove(const T& target);

    /**
     * TODO doc
     */
    virtual bool contains(const T& item) const;

    // interfaces to derived methods
    virtual bool empty() const;
    virtual int getTreeHeight() const;
    virtual int getNumNodes() const;
    virtual void clear();
    virtual void preorderTraverse(TraversalFunction<T>* func) const; 
    virtual void inorderTraverse(TraversalFunction<T>* func) const;
    virtual void postorderTraverse(TraversalFunction<T>* func) const;
};

template <class T>
BinarySearchTree<T>::BinarySearchTree() : rootPtr(nullptr)
{

}

template <class T>
BinarySearchTree<T>::BinarySearchTree(const T& rootItem)
{
    rootPtr = new BinaryTreeNode<T>(rootItem);
}

template <class T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& other)
{

}

template <class T>
BinarySearchTree<T>::~BinarySearchTree()
{

}

template <class T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(
        const BinarySearchTree<T>& other)
{

}

template <class T>
BinaryTreeNode<T>* BinarySearchTree<T>::orderedInsert(
        BinaryTreeNode<T>* subtreePtr, BinaryTreeNode<T>* newNodePtr)
{

}

template <class T>
bool BinarySearchTree<T>::add(const T& item)
{

}

template <class T>
BinaryTreeNode<T>* BinarySearchTree<T>::removeLeftmostNode(
            BinaryTreeNode<T>* nodePtr, T& inorderSuccessor)
{

}

template <class T>
BinaryTreeNode<T>* BinarySearchTree<T>::removeNode(BinaryTreeNode<T>* nodePtr)
{

}

template <class T>
BinaryTreeNode<T>* BinarySearchTree<T>::removeHelper(
        BinaryTreeNode<T>* subtreePtr, const T& target, bool& success)
{

}

template <class T>
bool BinarySearchTree<T>::remove(const T& target)
{

}

template <class T>
bool BinarySearchTree<T>::contains(const T& item) const
{
   
}

template <class T>
bool BinarySearchTree<T>::empty() const
{
    return BinaryTree::empty();
}

template <class T>
int BinarySearchTree<T>::getTreeHeight() const
{
    return BinaryTree::getTreeHeight();
}

template <class T>
int BinarySearchTree<T>::getNumNodes() const
{
    return BinaryTree::getNumNodes();
}

template <class T>
void BinarySearchTree<T>::clear()
{
    BinaryTree::clear();
}

template <class T>
void BinarySearchTree<T>::preorderTraverse(TraversalFunction<T>* func) const
{
    BinaryTree::preorderTraverse(func);
}

template <class T>
void BinarySearchTree<T>::inorderTraverse(TraversalFunction<T>* func) const
{
    BinaryTree::inorderTraverse(func);
}

template <class T>
void BinarySearchTree<T>::postorderTraverse(TraversalFunction<T>* func) const
{
    BinaryTree::postorderTraverse(func);
}

#endif
