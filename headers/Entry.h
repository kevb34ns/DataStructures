/**
 * An entry abstraction for a Dictionary data structure.
 */
#ifndef ENTRY_H
#define ENTRY_H

template <class K, class V>
class Entry
{
private:
    K key;
    V value;

protected:
    virtual void setKey(const K& newKey);

public:

    Entry(const K& key, const K& value);

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

Entry<K,V>::Entry(const K& key, const K& value)
    : key(key), value(value)
{

}

Entry<K,V>::~Entry()
{

}

const K& Entry<K,V>::getKey()
{
    return key;
}

void Entry<K,V>::setKey(const K& newKey)
{
    key = newKey;
}

const V& Entry<K,V>::getValue()
{
    return value;
}

void Entry<K,V>::setValue(const V& newValue)
{
    value = newValue;
}

bool operator<(const Entry<K,V>& lhs, const Entry<K,V>& rhs) const
{
    return lhs.key < rhs.key;
}

bool operator>(const Entry<K,V>& lhs, const Entry<K,V>& rhs) const
{
    return rhs < lhs;
}

bool operator<=(const Entry<K,V>& lhs, const Entry<K,V>& rhs) const
{
    return !(rhs < lhs);
}

bool operator>=(const Entry<K,V>& lhs, const Entry<K,V>& rhs) const
{
    return !(lhs > rhs);
}

bool operator==(const Entry<K,V>& lhs, const Entry<K,V>& rhs) const
{
    return lhs.key == rhs.key;
}

bool operator!=(const Entry<K,V>& lhs, const Entry<K,V>& rhs) const
{
    return !(lhs == rhs);
}

#endif
