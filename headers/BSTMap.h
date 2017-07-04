/**
 * A binary search tree implementation of a Dictionary.
 */
#ifndef BST_MAP_H
#define BST_MAP_H

#include "Dictionary.h"
#include "Entry.h"
#include "BinarySearchTree.h"
#include <stdexcept>

template <class K, class V>
class BSTMap : public Dictionary<K,V>
{
private:
    BinarySearchTree<Entry<K,V>>* searchTree;

public:
    BSTMap();

    BSTMap(const BSTMap<K,V>& other);

    ~BSTMap();

    virtual bool isEmpty() const;

    virtual int getSize() const;

    virtual bool add(const K& key, const V& value);

    virtual bool remove(const K& key);

    virtual const V& getValue(const K& key) const;

    virtual bool contains(const K& key) const;

    virtual void clear();
};

template <class K, class V>
BSTMap()
{
    searchTree = nullptr;
}

template <class K, class V>
BSTMap(const BSTMap<K,V>& other)
{
    if (other.searchTree != nullptr) 
    {
        searchTree = new BinarySearchTree<Entry<K,V>>(other.searchTree);
    }
    else
    {
        searchTree = nullptr;
    }
}

template <class K, class V>
~BSTMap()
{
    clear();
}

template <class K, class V>
bool isEmpty() const
{
    if (searchTree == nullptr)
    {
        return true;
    }
    else
    {
        return searchTree->empty();
    }
}

template <class K, class V>
int getSize() const
{
    if (isEmpty())
    {
        return 0;
    }
    else
    {
        return searchTree->getNumNodes();
    }
}

template <class K, class V>
bool add(const K& key, const V& value)
{
    if (contains(key))
    {
        return false;
    }

    Entry<K,V> newEntry(key, value);
    if (searchTree == nullptr)
    {
        searchTree = new BinarySearchTree<Entry<K,V>>(newEntry);
    }
    else
    {
        searchTree->add(newEntry);
    }
}

template <class K, class V>
bool remove(const K& key)
{
    if (searchTree == nullptr)
    {
        return false;
    }

    Entry<K,V> searchKeyEntry(key);
    return searchTree->remove(searchKeyEntry);
}

template <class K, class V>
const V& getValue(const K& key) const
{
    if (searchTree == nullptr)
    {
        throw runtime_error("Called BSTMap<K,V>::getValue on an empty tree.");
    }

    return searchTree->getItem().getValue();
}

template <class K, class V>
bool contains(const K& key) const
{
     if (searchTree == nullptr)
    {
        return false;
    }

    Entry<K,V> searchKeyEntry(key);
    return searchTree->contains(searchKeyEntry);
}

template <class K, class V>
void clear()
{
    delete searchTree;
}

#endif
