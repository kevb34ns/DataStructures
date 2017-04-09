#ifndef LIST_H
#define LIST_H

#include <vector>

template <class T>
class List 
{
public:
    virtual void add(const T& item) = 0;

    virtual bool remove(const T& item) = 0;

    virtual int size() const = 0;

    virtual bool empty() const = 0;

    virtual bool contains(const T& item) const = 0;

    virtual void clear() = 0;

    virtual std::vector<T> toVector() const = 0;
};

#endif