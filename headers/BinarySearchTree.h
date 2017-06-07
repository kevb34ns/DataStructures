/**
 * @class BinarySearchTree
 * @brief A simple (non-balancing) binary search tree.
 * @author Kevin K. Yang
 */

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
     * @param success A reference to a bool which is set to true if an item
     *                was inserted, or false otherwise.
     * @return A pointer to the root of the subtree.
     */
    virtual BinaryTreeNode<T>* orderedInsert(BinaryTreeNode<T>* subtreePtr,
            BinaryTreeNode<T>* newNodePtr, bool& success);

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

    /**
     * Recursively searches for a value in the tree.
     * @param subtreePtr The root of the tree to search.
     * @param target The value to search for.
     * @return The node with the target value if it exists, or @c nullptr
     *         otherwise.
     */
     virtual BinaryTreeNode<T>* containsHelper(BinaryTreeNode<T>* subtreePtr,
            const T& target) const;

public:
    BinarySearchTree();
    BinarySearchTree(const T& rootItem);
    BinarySearchTree(const BinarySearchTree<T>& other);

    virtual ~BinarySearchTree();

    virtual BinarySearchTree<T>& operator=(const BinarySearchTree<T>& other);
    
    /**
     * Adds a new node to the tree, maintaining the sorted nature of a BST.
     * Items added to the tree must be unique (duplicate items will not be
     * added).
     * @param item The value to add to the tree.
     * @return true if the item was added, false otherwise.
     */
    virtual bool add(const T& item);

    /**
     * TODO doc
     */
    virtual bool remove(const T& target);

    /**
     * Searches the tree for the existence of a certain item.
     * @param item The item to search for.
     * @return true if the item is in the tree, false otherwise.
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
    *this = other;
}

template <class T>
BinarySearchTree<T>::~BinarySearchTree()
{
    clear();
}

template <class T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(
        const BinarySearchTree<T>& other)
{
    rootPtr = copyTree(other.rootPtr);
    return *this;
}

template <class T>
BinaryTreeNode<T>* BinarySearchTree<T>::orderedInsert(
        BinaryTreeNode<T>* subtreePtr, BinaryTreeNode<T>* newNodePtr,
        bool& success)
{
    if (subtreePtr == nullptr)
    {
        success = true;
        return newNodePtr;
    }

    if (subtreePtr->getItem() > newNodePtr->getItem())
    {
        BinaryTreeNode<T>* nodePtr = orderedInsert(subtreePtr->getLeft(),
                newNodePtr, success);
        subTreePtr->setLeft(nodePtr);
    }
    else if (subtreePtr->getItem() < newNodePtr->getItem())
    {
        BinaryTreeNode<T>* nodePtr = orderedInsert(subtreePtr->getRight(),
                newNodePtr, success);
        subTreePtr->setRight(nodePtr);
    }
    else
    {
        success = false;
    }
    
    return subtreePtr;
}

template <class T>
bool BinarySearchTree<T>::add(const T& item)
{
    BinaryTreeNode<T>* newNodePtr = new BinaryTreeNode<T>(item);
    bool success = false;
    rootPtr = orderedInsert(rootPtr, newNodePtr, success);
    return success;
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
    bool success = false;
    rootPtr = removeHelper(rootPtr, target, success);
    return success;
}

template <class T>
BinaryTreeNode<T>* BinarySearchTree<T>::containsHelper(
        BinaryTreeNode<T>* subtreePtr, const T& target) const
{
    if (subtreePtr == nullptr)
    {
        return nullptr;
    }

    if (subTreePtr->getItem() == target)
    {
        success = true;
        return subTreePtr;
    }

    if (subTreePtr->getItem() > target)
    {
        return containsHelper(subtreePtr->getLeft(), target, success);
    }
    
    if (subTreePtr->getItem() < target)
    {
        return containsHelper(subtreePTr->getRight(), target, success);
    }

    // if this point is reached, there were duplicate items in the tree.
    return nullptr;
}

template <class T>
bool BinarySearchTree<T>::contains(const T& item) const
{
    return containsHelper(rootPtr, item, success) != nullptr;
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
