/**
 * An entry abstraction for a Dictionary data structure.
 */
#ifndef ENTRY_H
#define ENTRY_H

#include <stdexcept>

template <class K, class V>
class Entry
{
private:
    K* keyPtr;
    V* valuePtr;

protected:
    virtual void setKey(const K& newKey);

public:

    Entry(const K& key);

    Entry(const K& key, const V& value);

    Entry(const Entry<K,V>& other);

    virtual ~Entry();

    virtual const K& getKey();

    virtual const V& getValue();

    virtual void setValue(const V& newValue);

    friend bool operator<(const Entry<K,V>& lhs, const Entry<K,V>& rhs) const;

    friend bool operator>(const Entry<K,V>& lhs, const Entry<K,V>& rhs) const;

    friend bool operator<=(const Entry<K,V>& lhs, const Entry<K,V>& rhs) const;
    
    friend bool operator>=(const Entry<K,V>& lhs, const Entry<K,V>& rhs) const;

    friend bool operator==(const Entry<K,V>& lhs, const Entry<K,V>& rhs) const;
    
    friend bool operator!=(const Entry<K,V>& lhs, const Entry<K,V>& rhs) const;
};

template <class K, class V>
Entry<K,V>::Entry(const K& key) : valuePtr(nullptr)
{
    keyPtr = new K(key);
}

template <class K, class V>
Entry<K,V>::Entry(const K& key, const V& value)
{
    keyPtr = new K(key);
    valuePtr = new V(value);
}

template <class K, class V>
Entry<K,V>::Entry(const Entry<K,V>& other)
{
    keyPtr = new K(*(other.keyPtr));
    valuePtr = new V(*(other.valuePtr));
}

template <class K, class V>
Entry<K,V>::~Entry()
{
    if (keyPtr != nullptr)
    {
        delete keyPtr;
    }

    if (valuePtr != nullptr)
    {
        delete valuePtr;
    }
}

template <class K, class V>
const K& Entry<K,V>::getKey()
{
    if (keyPtr == nullptr)
    {
        throw runtime_error("Entry<K,V>::getKey called on Entry with no key.");
    }

    return *keyPtr;
}

template <class K, class V>
void Entry<K,V>::setKey(const K& newKey)
{
    if (keyPtr != nullptr)
    {
        delete keyPtr;
    }

    keyPtr = new K(newKey);
}

template <class K, class V>
const V& Entry<K,V>::getValue()
{
    if (valuePtr == nullptr)
    {
        throw runtime_error("Entry<K,V>::getValue called on Entry " + 
                            "with no value.");
    }

    return *valuePtr;
}

template <class K, class V>
void Entry<K,V>::setValue(const V& newValue)
{
    if (valuePtr != nullptr)
    {
        delete valuePtr;
    }

    valuePtr = new V(newValue);
}

template <class K, class V>
bool operator<(const Entry<K,V>& lhs, const Entry<K,V>& rhs) const
{
    return *lhs.key < *rhs.key;
}

template <class K, class V>
bool operator>(const Entry<K,V>& lhs, const Entry<K,V>& rhs) const
{
    return rhs < lhs;
}

template <class K, class V>
bool operator<=(const Entry<K,V>& lhs, const Entry<K,V>& rhs) const
{
    return !(rhs < lhs);
}

template <class K, class V>
bool operator>=(const Entry<K,V>& lhs, const Entry<K,V>& rhs) const
{
    return !(lhs < rhs);
}

template <class K, class V>
bool operator==(const Entry<K,V>& lhs, const Entry<K,V>& rhs) const
{
    return *lhs.key == *rhs.key;
}

template <class K, class V>
bool operator!=(const Entry<K,V>& lhs, const Entry<K,V>& rhs) const
{
    return !(lhs == rhs);
}

#endif
