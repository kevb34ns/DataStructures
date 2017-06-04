/**  
 * @class BinaryTree
 * @brief A simple binary tree implementation.
 * @author Kevin K. Yang
 */

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "BinaryTreeNode.h"
#include <stdexcept>
#include <iostream> //TODO

template <class T>
class BinaryTree
{
private:
    BinaryTreeNode<T>* rootPtr;

protected:
    /** 
     * Recursively calculates the height of the tree.
     * @param subTreePtr the root of the subtree to calculate the height of.
     * @return the height of the tree rooted at @c subTreePtr.
     */
    virtual int treeHeightHelper(BinaryTreeNode<T>* subTreePtr) const;

    /**
     * Recursively find the number of nodes in the tree.
     * @param subTreePtr the root of the subtree to act on.
     * @return the number of nodes in the tree rooted at @c subTreePtr.
     */
    virtual int numNodesHelper(BinaryTreeNode<T>* subTreePtr) const;
    
    /**
     * Deletes each node in the tree, including the root.
     * @param the root of the subtree to be deleted.
     * @note uses postorder traversal.
     */
    virtual void destroyTree(BinaryTreeNode<T>* subTreePtr);

    /**
     * Recursively adds a new node to the tree in a balanced manner, 
     * by adding to the shorter of the root node’s two subtrees.
     * @param subTreePtr the root of the tree to add to.
     * @param newNodePtr the new node to add.
     * @return the root of the tree.
     */
    virtual BinaryTreeNode<T>* balancedAdd(BinaryTreeNode<T>* subTreePtr,
        BinaryTreeNode<T>* newNodePtr);

    /**
     * Removes a value from the tree.
     * @param subTreePtr, the root of the subtree to search.
     * @param target The data item of the node to delete.
     * @param success True if the value existed in the tree and was removed, 
     *                     false otherwise.
     * @return the root of the subtree.
     */
    virtual BinaryTreeNode<T>* removeValue(BinaryTreeNode<T>* subTreePtr,
        const T& target, bool& success);

    /**
     * Overwrites the value of the node pointed to by @c subTreePtr by moving 
     * values from its descendant nodes upwards, and deletes the resulting 
     * empty leaf node.
     * @param subTreePtr A pointer to the node with the value to be overwritten.
     * @return A pointer to the node with the old value replaced by a new one.
     */
    virtual BinaryTreeNode<T>* moveValuesUpTree(BinaryTreeNode<T>* subTreePtr);

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
    virtual void preorderHelper(void (* visit)(T&), BinaryTreeNode<T>* treePtr) 
        const;

    /**
     * Inorder traversal helper method.
     */
    virtual void inorderHelper(void (* visit)(T&), BinaryTreeNode<T>* treePtr) 
        const;

    /**
     * Postorder traversal helper method.
     */
    virtual void postorderHelper(void (* visit)(T&), BinaryTreeNode<T>* treePtr) 
        const;

public:
    // Constructors
    BinaryTree();
    BinaryTree(const T& rootItem);
    BinaryTree(const T& rootItem, 
        const BinaryTree<T>* leftSubTreePtr,
        const BinaryTree<T>* rightSubTreePtr);
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
    rootPtr = new BinaryTreeNode<T>(rootItem);
}

template <class T>
BinaryTree<T>::BinaryTree(const T& rootItem, 
        const BinaryTree<T>* leftSubTreePtr,
        const BinaryTree<T>* rightSubTreePtr)
{
    rootPtr= new BinaryTreeNode<T>(rootItem, leftSubTreePtr, rightSubTreePtr);
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
int BinaryTree<T>::treeHeightHelper(BinaryTreeNode<T>* subTreePtr) const
{
    if (subTreePtr == nullptr)   
    {
        return 0;
    }
    else
    {
        int leftHeight = treeHeightHelper(subTreePtr->getLeft());
        int rightHeight = treeHeightHelper(subTreePtr->getRight());

        return 1 + ((leftHeight > rightHeight) ? leftHeight : rightHeight);
    }
}

template <class T>
int BinaryTree<T>::getTreeHeight() const
{
    return treeHeightHelper(rootPtr);
}

template <class T>
int BinaryTree<T>::numNodesHelper(BinaryTreeNode<T>* subTreePtr) const
{
    if (subTreePtr == nullptr)   
    {
        return 0;
    }
    else
    {
        return 1 + numNodesHelper(subTreePtr->getLeft()) + 
            numNodesHelper(subTreePtr->getRight());
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
BinaryTreeNode<T>* BinaryTree<T>::balancedAdd(BinaryTreeNode<T>* subTreePtr,
    BinaryTreeNode<T>* newNodePtr)
{
    if (subTreePtr == nullptr)
    {
        return newNodePtr;
    }

    BinaryTreeNode<T>* leftSubTree = subTreePtr->getLeft();
    BinaryTreeNode<T>* rightSubTree = subTreePtr->getRight();
    if (treeHeightHelper(leftSubTree) > treeHeightHelper(rightSubTree))
    {
        rightSubTree = balancedAdd(rightSubTree, newNodePtr);
        subTreePtr->setRight(rightSubTree);
    }
    else
    {
        leftSubTree = balancedAdd(leftSubTree, newNodePtr);
        subTreePtr->setLeft(leftSubTree);
    }

    return subTreePtr;
}

template <class T>
bool BinaryTree<T>::add(const T& item)
{
    BinaryTreeNode<T>* newNodePtr = new BinaryTreeNode<T>(item);
    rootPtr = balancedAdd(rootPtr, newNodePtr);

    return rootPtr != nullptr;
}

template <class T>
BinaryTreeNode<T>* BinaryTree<T>::removeValue(BinaryTreeNode<T>* subTreePtr,
    const T& target, bool& success)
{
    //ERROR does not set nodeToRemove's parent's childptr to nullptr, causing errors
    BinaryTreeNode<T>* nodeToRemove = findNode(subTreePtr, target, success);
    if (success)
    {
        nodeToRemove = moveValuesUpTree(nodeToRemove);
    }
    
    return subTreePtr;
}

template <class T>
BinaryTreeNode<T>* BinaryTree<T>::moveValuesUpTree(
    BinaryTreeNode<T>* subTreePtr)
{
    if (subTreePtr == nullptr)
    {
        return subTreePtr;
    }

    BinaryTreeNode<T>* leftSubTree = subTreePtr->getLeft();
    BinaryTreeNode<T>* rightSubTree = subTreePtr->getRight();

    if (leftSubTree == nullptr && rightSubTree == nullptr)
    {
        delete subTreePtr;
        subTreePtr = nullptr;
        return subTreePtr;
    }

    if (treeHeightHelper(leftSubTree) > treeHeightHelper(rightSubTree))
    {
        // move value from left subtree
        subTreePtr->setItem(leftSubTree->getItem());
        leftSubTree = moveValuesUpTree(leftSubTree);
        subTreePtr->setLeft(leftSubTree);
    }
    else 
    {
        // move value from right subtree
        subTreePtr->setItem(rightSubTree->getItem());
        rightSubTree = moveValuesUpTree(rightSubTree);
        subTreePtr->setRight(rightSubTree);
    }

    return subTreePtr;
}

template <class T>
bool BinaryTree<T>::remove(const T& item)
{
    bool success = false;
    rootPtr = removeValue(rootPtr, item, success);

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
bool BinaryTree<T>::contains(const T& item)
{
    bool success = false;
    findNode(rootPtr, item, success);

    return success;
}

template <class T>
void BinaryTree<T>::destroyTree(BinaryTreeNode<T>* subTreePtr)
{
    if (subTreePtr == nullptr)
    {
        return;
    }

    destroyTree(subTreePtr->getLeft());
    destroyTree(subTreePtr->getRight());
    delete subTreePtr;
    subTreePtr = nullptr;
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
void BinaryTree<T>::preorderHelper(void (* visit)(T&), 
    BinaryTreeNode<T>* treePtr) const
{
    if (treePtr == nullptr)
    {
        return;
    }

    T item(treePtr->getItem());

    visit(item);
    preorderHelper(visit, treePtr->getLeft());
    preorderHelper(visit, treePtr->getRight());
}

template <class T>
void BinaryTree<T>::inorderHelper(void (* visit)(T&), 
    BinaryTreeNode<T>* treePtr) const
{
    if (treePtr == nullptr)
    {
        return;
    }

    T item(treePtr->getItem());

    inorderHelper(visit, treePtr->getLeft());
    visit(item);
    inorderHelper(visit, treePtr->getRight());    
}

template <class T>
void BinaryTree<T>::postorderHelper(void (* visit)(T&), 
    BinaryTreeNode<T>* treePtr) const
{
    if (treePtr == nullptr)
    {
        return;
    }
    
    T item(treePtr->getItem());

    postorderHelper(visit, treePtr->getLeft());
    postorderHelper(visit, treePtr->getRight());
    visit(item);
}

template <class T>
void BinaryTree<T>::preorderTraverse(void (* visit)(T&)) const
{
    preorderHelper(visit, rootPtr);
}

template <class T>
void BinaryTree<T>::inorderTraverse(void (* visit)(T&)) const
{
    inorderHelper(visit, rootPtr);
}

template <class T>
void BinaryTree<T>::postorderTraverse(void (* visit)(T&)) const
{
    postorderHelper(visit, rootPtr);
}

#endif
