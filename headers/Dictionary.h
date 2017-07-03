/**
 * An abstract Dictionary interface.
 */
#ifndef DICTIONARY_H
#define DICTIONARY_H

template <class K, class V>
class Dictionary
{
public:
    virtual bool isEmpty() const = 0;

    virtual int getSize() const = 0;

    virtual bool add(const K& key, const V& value) = 0;

    virtual bool remove(const K& key) = 0;

    virtual const V& getValue(const K& key) const = 0;

    virtual bool contains(const K& key) const = 0;

    virtual void clear() = 0;
};

#endif
