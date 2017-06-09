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
     * @brief Removes the leftmost ancestor of a node, in order to facilitate 
     * removal of a node with two children. 
     * 
     * For the parent of @c nodePtr, theleftmost ancestor of @c nodePtr is its
     * inorder successor in the BST. In a sorted list of all the values in the
     * BST, the inorder successor of some value x is the value immediately
     * following x.
     * 
     * @param nodePtr The node whose leftmost ancestor will be removed, which is
     *                assumed to be non-null.
     * @param inorderSuccessr A reference to a variable of type T, which will be
     *                        set to the value of the leftmost ancestor.
     * @return a pointer to the location of the removed node, which should be
     *         @c nullptr.
     */
    virtual BinaryTreeNode<T>* removeLeftmostAncestor(
            BinaryTreeNode<T>* nodePtr, T& inorderSuccessor);
    
    /**
     * Removes the specified node from the tree, while maintaining the sorted
     * nature of the BST.
     * @param nodePtr The node to remove.
     * @return A pointer to the node now located at the position previously
     *         occupied by @c nodePtr, or @c nullptr if there is no node there.
     */
    virtual BinaryTreeNode<T>* removeNode(BinaryTreeNode<T>* nodePtr);

    /**
     * Recursively removes a node with the target value, if it exists.
     * @param subtreePtr Pointer to the root of the subtree to search.
     * @param target The target value to remove.
     * @param success A boolean reference, which is set to true if the target
     *                exists and was removed, or false otherwise.
     * @return A pointer to root of the subtree.
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
     * Removes a node from the tree with the specified value, if it exists.
     * @param target The target value to search for.
     * @return true if a node was removed, false otherwise.
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
BinarySearchTree<T>::BinarySearchTree()
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
        subtreePtr->setLeft(nodePtr);
    }
    else if (subtreePtr->getItem() < newNodePtr->getItem())
    {
        BinaryTreeNode<T>* nodePtr = orderedInsert(subtreePtr->getRight(),
                newNodePtr, success);
        subtreePtr->setRight(nodePtr);
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
BinaryTreeNode<T>* BinarySearchTree<T>::removeLeftmostAncestor(
            BinaryTreeNode<T>* nodePtr, T& inorderSuccessor)
{
    if (nodePtr->getLeft() == nullptr)
    {
        inorderSuccessor = nodePtr->getItem();
        return removeNode(nodePtr);
    }

    BinaryTreeNode<T>* leftPtr = removeLeftmostAncestor(
            nodePtr->getLeft(), inorderSuccessor);
    nodePtr->setLeft(leftPtr);
    return nodePtr;
}

template <class T>
BinaryTreeNode<T>* BinarySearchTree<T>::removeNode(BinaryTreeNode<T>* nodePtr)
{
    if (nodePtr == nullptr)
    {
        return nullptr;
    }

    BinaryTreeNode<T>* leftPtr = nodePtr->getLeft();
    BinaryTreeNode<T>* rightPtr = nodePtr->getRight();

    if (!leftPtr && !rightPtr)
    {
        delete nodePtr;
        return nullptr;
    }
    else if (!leftPtr)
    {
        BinaryTreeNode<T>* rightPtr = nodePtr->getRight();
        delete nodePtr;
        return rightPtr;
    }
    else if (!rightPtr)
    {
        BinaryTreeNode<T>* leftPtr = nodePtr->getLeft();
        delete nodePtr;
        return leftPtr;
    }
    else
    {
        T inorderSuccessor;
        BinaryTreeNode<T>* rightPtr = removeLeftmostAncestor(
                nodePtr->getRight(), inorderSuccessor);
        nodePtr->setRight(rightPtr);
        nodePtr->setItem(inorderSuccessor);
        return nodePtr;
    }
}

template <class T>
BinaryTreeNode<T>* BinarySearchTree<T>::removeHelper(
        BinaryTreeNode<T>* subtreePtr, const T& target, bool& success)
{
    if (subtreePtr == nullptr)
    {
        success = false;
        return nullptr;
    }

    if (subtreePtr->getItem() == target)
    {
        success = true;
        return removeNode(subtreePtr);
    }

    if (subtreePtr->getItem() > target)
    {
        BinaryTreeNode<T>* nodePtr = 
                removeHelper(subtreePtr->getLeft(), target, success);
        subtreePtr->setLeft(nodePtr);
    }
    else
    {
        BinaryTreeNode<T>* nodePtr = 
                removeHelper(subtreePtr->getRight(), target, success);
        subtreePtr->setRight(nodePtr);
    }

    return subtreePtr;
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

    if (subtreePtr->getItem() == target)
    {
        return subtreePtr;
    }

    if (subtreePtr->getItem() > target)
    {
        return containsHelper(subtreePtr->getLeft(), target);
    }
    
    if (subtreePtr->getItem() < target)
    {
        return containsHelper(subtreePtr->getRight(), target);
    }

    // if this point is reached, there were duplicate items in the tree.
    return nullptr;
}

template <class T>
bool BinarySearchTree<T>::contains(const T& item) const
{
    return containsHelper(rootPtr, item) != nullptr;
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
