/**
 * A binary search tree implementation of a Dictionary.
 */
#ifndef BST_MAP_H
#define BST_MAP_H

#include "Dictionary.h"
#include "Entry.h"
#include "BinarySearchTree.h"

template <class K, class V>
class BSTMap : public Dictionary<K,V>
{
private:
    BinarySearchTree<Entry<K,V>> searchTree;

public:
};

#endif
