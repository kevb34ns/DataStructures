/**  
 * @class BinaryTree
 * @brief A simple binary tree implementation.
 * @author Kevin K. Yang
 */

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "BinaryTreeNode.h"
#include <stdexcept>

/**
 * @class TraversalFunction
 * @brief A functional interface used with the @c BinaryTree traversal methods.
 * 
 * Pass an object derived from this abstract class to the traversal methods.
 * The traversal method will call @c TraversalFunction::visit at each node.
 */
template <class T>
class TraversalFunction
{
public:
    /**
     * The function called at each node of the tree.
     * @param item The data item held by the node.
     */
    virtual void visit(T& item) = 0;
};

template <class T>
class BinaryTree
{
protected:
    BinaryTreeNode<T>* rootPtr;

    /** 
     * Recursively calculates the height of the tree.
     * @param subtreePtr the root of the subtree to calculate the height of.
     * @return the height of the tree rooted at @c subtreePtr.
     */
    virtual int treeHeightHelper(BinaryTreeNode<T>* subtreePtr) const;

    /**
     * Recursively find the number of nodes in the tree.
     * @param subtreePtr the root of the subtree to act on.
     * @return the number of nodes in the tree rooted at @c subtreePtr.
     */
    virtual int numNodesHelper(BinaryTreeNode<T>* subtreePtr) const;
    
    /**
     * Deletes each node in the tree, including the root.
     * @param the root of the subtree to be deleted.
     * @note uses postorder traversal.
     */
    virtual void destroyTree(BinaryTreeNode<T>* subtreePtr);

    /**
     * Recursively adds a new node to the tree in a balanced manner, 
     * by adding to the shorter of the root node’s two subtrees.
     * @param subtreePtr the root of the tree to add to.
     * @param newNodePtr the new node to add.
     * @return the root of the tree.
     */
    virtual BinaryTreeNode<T>* addHelper(BinaryTreeNode<T>* subtreePtr,
        BinaryTreeNode<T>* newNodePtr);

    /**
     * Removes a value from the tree.
     * @param subtreePtr, the root of the subtree to search.
     * @param target The data item of the node to delete.
     * @param success True if the value existed in the tree and was removed, 
     *                     false otherwise.
     * @return the root of the subtree.
     */
    virtual BinaryTreeNode<T>* removeHelper(BinaryTreeNode<T>* subtreePtr,
        const T& target, bool& success);

    /**
     * Overwrites the data item of the node pointed to by @c subtreePtr by 
     * moving items from its descendant nodes upwards, and deletes the resulting 
     * empty leaf node.
     * @param subtreePtr A pointer to the node with the value to be overwritten.
     * @return A pointer to the node with the old value replaced by a new one.
     */
    virtual BinaryTreeNode<T>* shiftItemsUp(BinaryTreeNode<T>* subtreePtr);

    /**
     * Searches for a node with the specified value.
     * @param treePtr The pointer to the root of the tree to search.
     * @param target The value to search for.
     * @param success True if it was found, false otherwise.
     * @return The node with the desired value, or @c nullptr if none was found.
     */
    virtual BinaryTreeNode<T>* findNode(BinaryTreeNode<T>* treePtr, 
        const T& target, bool& success) const;

    /**
     * Creates a deep copy of a tree.
     * @param treePtr The root of the tree to copy.
     * @return The root of the copied tree.
     */
    virtual BinaryTreeNode<T>* copyTree(const BinaryTreeNode<T>* treePtr) 
        const;

    /**
     * Preorder traversal helper method.
     */
    virtual void preorderHelper(TraversalFunction<T>* func, 
        BinaryTreeNode<T>* treePtr) const;

    /**
     * Inorder traversal helper method.
     */
    virtual void inorderHelper(TraversalFunction<T>* func, 
        BinaryTreeNode<T>* treePtr) const;

    /**
     * Postorder traversal helper method.
     */
    virtual void postorderHelper(TraversalFunction<T>* func, 
        BinaryTreeNode<T>* treePtr) const;

public:
    // Constructors
    BinaryTree();
    BinaryTree(const T& rootItem);
    BinaryTree(const T& rootItem, 
        const BinaryTree<T>* leftSubtreePtr,
        const BinaryTree<T>* rightSubtreePtr);
    BinaryTree(const BinaryTree<T>& other);

    virtual ~BinaryTree();

    // Overloaded operators
    virtual BinaryTree<T>& operator=(const BinaryTree<T>& other);

    virtual bool empty() const;

    virtual int getTreeHeight() const;

    virtual int getNumNodes() const;

    virtual const T& getRootData() const;

    virtual void setRootData(const T& rootItem);

    virtual bool add(const T& item);

    virtual bool remove(const T& item);

    virtual bool contains(const T& item) const;

    virtual void clear();

    // Traversal operations
    virtual void preorderTraverse(TraversalFunction<T>* func) const; 
    virtual void inorderTraverse(TraversalFunction<T>* func) const;
    virtual void postorderTraverse(TraversalFunction<T>* func) const;
   
};

template <class T>
BinaryTree<T>::BinaryTree() : rootPtr(nullptr)
{
      
}

template <class T>
BinaryTree<T>::BinaryTree(const T& rootItem)
{
    rootPtr = new BinaryTreeNode<T>(rootItem);
}

template <class T>
BinaryTree<T>::BinaryTree(const T& rootItem, 
        const BinaryTree<T>* leftSubtreePtr,
        const BinaryTree<T>* rightSubtreePtr)
{
    rootPtr= new BinaryTreeNode<T>(rootItem, leftSubtreePtr, rightSubtreePtr);
}

template <class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T>& other)
{
    *this = other;
}

template <class T>
BinaryTree<T>::~BinaryTree()
{
    clear();
}

template <class T>
BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree<T>& other)
{
    rootPtr = copyTree(other.rootPtr);
    return *this;
}

template <class T>
bool BinaryTree<T>::empty() const
{
    return rootPtr == nullptr;
}

template <class T>
int BinaryTree<T>::treeHeightHelper(BinaryTreeNode<T>* subtreePtr) const
{
    if (subtreePtr == nullptr)   
    {
        return 0;
    }
    else
    {
        int leftHeight = treeHeightHelper(subtreePtr->getLeft());
        int rightHeight = treeHeightHelper(subtreePtr->getRight());

        return 1 + ((leftHeight > rightHeight) ? leftHeight : rightHeight);
    }
}

template <class T>
int BinaryTree<T>::getTreeHeight() const
{
    return treeHeightHelper(rootPtr);
}

template <class T>
int BinaryTree<T>::numNodesHelper(BinaryTreeNode<T>* subtreePtr) const
{
    if (subtreePtr == nullptr)   
    {
        return 0;
    }
    else
    {
        return 1 + numNodesHelper(subtreePtr->getLeft()) + 
            numNodesHelper(subtreePtr->getRight());
    }
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
        throw std::range_error("Tried to access empty tree \
            with BinaryTree<T>::getRootData");
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
        throw std::range_error("Tried to access empty tree \
            with BinaryTree<T>::setRootData");
    }
    else
    {
        rootPtr->setItem(rootItem);
    }
}

template <class T>
BinaryTreeNode<T>* BinaryTree<T>::addHelper(BinaryTreeNode<T>* subtreePtr,
    BinaryTreeNode<T>* newNodePtr)
{
    if (subtreePtr == nullptr)
    {
        return newNodePtr;
    }

    BinaryTreeNode<T>* leftSubTree = subtreePtr->getLeft();
    BinaryTreeNode<T>* rightSubTree = subtreePtr->getRight();
    if (treeHeightHelper(leftSubTree) > treeHeightHelper(rightSubTree))
    {
        rightSubTree = addHelper(rightSubTree, newNodePtr);
        subtreePtr->setRight(rightSubTree);
    }
    else
    {
        leftSubTree = addHelper(leftSubTree, newNodePtr);
        subtreePtr->setLeft(leftSubTree);
    }

    return subtreePtr;
}

template <class T>
bool BinaryTree<T>::add(const T& item)
{
    BinaryTreeNode<T>* newNodePtr = new BinaryTreeNode<T>(item);
    rootPtr = addHelper(rootPtr, newNodePtr);

    return rootPtr != nullptr;
}

template <class T>
BinaryTreeNode<T>* BinaryTree<T>::removeHelper(BinaryTreeNode<T>* subtreePtr,
    const T& target, bool& success)
{
    if (subtreePtr == nullptr)
    {
        return nullptr;
    }

    if (subtreePtr->getItem() == target)
    {
        success = true;
        subtreePtr = shiftItemsUp(subtreePtr);
        return subtreePtr;
    }

    BinaryTreeNode<T>* leftPtr = removeHelper(subtreePtr->getLeft(), 
                                             target, success);
    subtreePtr->setLeft(leftPtr);
    
    if (!success)
    {
        BinaryTreeNode<T>* rightPtr = removeHelper(subtreePtr->getRight(), 
                                                  target, success);
        subtreePtr->setRight(rightPtr);
    }
    
    return subtreePtr;
}

template <class T>
BinaryTreeNode<T>* BinaryTree<T>::shiftItemsUp(
    BinaryTreeNode<T>* subtreePtr)
{
    if (subtreePtr == nullptr)
    {
        return subtreePtr;
    }

    BinaryTreeNode<T>* leftSubTree = subtreePtr->getLeft();
    BinaryTreeNode<T>* rightSubTree = subtreePtr->getRight();

    if (leftSubTree == nullptr && rightSubTree == nullptr)
    {
        delete subtreePtr;
        subtreePtr = nullptr;
        return subtreePtr;
    }

    if (treeHeightHelper(leftSubTree) > treeHeightHelper(rightSubTree))
    {
        // move value from left subtree
        subtreePtr->setItem(leftSubTree->getItem());
        leftSubTree = shiftItemsUp(leftSubTree);
        subtreePtr->setLeft(leftSubTree);
    }
    else 
    {
        // move value from right subtree
        subtreePtr->setItem(rightSubTree->getItem());
        rightSubTree = shiftItemsUp(rightSubTree);
        subtreePtr->setRight(rightSubTree);
    }

    return subtreePtr;
}

template <class T>
bool BinaryTree<T>::remove(const T& item)
{
    bool success = false;
    rootPtr = removeHelper(rootPtr, item, success);

    return success;
}

template <class T>
BinaryTreeNode<T>* BinaryTree<T>::findNode(BinaryTreeNode<T>* treePtr,
    const T& target, bool& success) const
{
    if (treePtr == nullptr)
    {
        return treePtr;
    }

    if (treePtr->getItem() == target)
    {
        success = true;
        return treePtr;
    }

    BinaryTreeNode<T>* targetNode = findNode(treePtr->getLeft(), target, 
                                             success);
    if (!success)
    {
        targetNode = findNode(treePtr->getRight(), target, success);
    }

    return success ? targetNode : treePtr;
}

template <class T>
bool BinaryTree<T>::contains(const T& item) const
{
    bool success = false;
    findNode(rootPtr, item, success);

    return success;
}

template <class T>
void BinaryTree<T>::destroyTree(BinaryTreeNode<T>* subtreePtr)
{
    if (subtreePtr == nullptr)
    {
        return;
    }

    destroyTree(subtreePtr->getLeft());
    destroyTree(subtreePtr->getRight());
    delete subtreePtr;
    subtreePtr = nullptr;
}

template <class T>
void BinaryTree<T>::clear()
{
    destroyTree(rootPtr);
    rootPtr = nullptr;
}

template <class T>
BinaryTreeNode<T>* BinaryTree<T>::copyTree(const BinaryTreeNode<T>* treePtr) 
    const
{
    if (treePtr == nullptr)
    {
        return nullptr;
    }

    BinaryTreeNode<T>* newNodePtr = new BinaryTreeNode<T>(treePtr->getItem());
    newNodePtr->setLeft(copyTree(treePtr->getLeft()));
    newNodePtr->setRight(copyTree(treePtr->getRight()));

    return newNodePtr;
}

template <class T>
void BinaryTree<T>::preorderHelper(TraversalFunction<T>* func, 
    BinaryTreeNode<T>* treePtr) const
{
    if (treePtr == nullptr)
    {
        return;
    }

    T item(treePtr->getItem());

    func->visit(item);
    preorderHelper(func, treePtr->getLeft());
    preorderHelper(func, treePtr->getRight());
}

template <class T>
void BinaryTree<T>::inorderHelper(TraversalFunction<T>* func, 
    BinaryTreeNode<T>* treePtr) const
{
    if (treePtr == nullptr)
    {
        return;
    }

    T item(treePtr->getItem());

    inorderHelper(func, treePtr->getLeft());
    func->visit(item);
    inorderHelper(func, treePtr->getRight());    
}

template <class T>
void BinaryTree<T>::postorderHelper(TraversalFunction<T>* func, 
    BinaryTreeNode<T>* treePtr) const
{
    if (treePtr == nullptr)
    {
        return;
    }
    
    T item(treePtr->getItem());

    postorderHelper(func, treePtr->getLeft());
    postorderHelper(func, treePtr->getRight());
    func->visit(item);
}

template <class T>
void BinaryTree<T>::preorderTraverse(TraversalFunction<T>* func) const
{
    preorderHelper(func, rootPtr);
}

template <class T>
void BinaryTree<T>::inorderTraverse(TraversalFunction<T>* func) const
{
    inorderHelper(func, rootPtr);
}

template <class T>
void BinaryTree<T>::postorderTraverse(TraversalFunction<T>* func) const
{
    postorderHelper(func, rootPtr);
}

#endif
