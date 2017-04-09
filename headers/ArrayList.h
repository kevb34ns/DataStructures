#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include "List.h"

template <class T>
class ArrayList : public List<T> 
{
private:
    T* array;
    int defaultCapacity;
    int count;
    int capacity;

    virtual int indexOf(const T& item) const;

    virtual void resize();

public:
    ArrayList();

    ArrayList(const int capacity);

    ~ArrayList();

    virtual void add(const T& item);

    virtual void remove(const T& item);

    virtual int size() const;

    virtual bool empty() const;

    virtual bool contains(const T& item) const;

    virtual void clear();

    virtual std::vector<T> toVector() const;
};

template <class T>
ArrayList<T>::ArrayList() : defaultCapacity(100), count(0), capacity(100) 
{
    array = new T[capacity];
}

template <class T>
ArrayList<T>::ArrayList(const int capacity) : defaultCapacity(capacity), 
    count(0), capacity(100) 
{
    array = new T[capacity];
}

template <class T>
ArrayList<T>::~ArrayList() 
{
    delete[] array;
}

template <class T>
int ArrayList<T>::indexOf(const T& item) const
{

}

template<class T>
void ArrayList<T>::resize()
{

}

template <class T>
void ArrayList<T>::add(const T& item) 
{
    if (count == capacity)
    {
        resize();
    }

    array[count] = item;
    count++;
}

template <class T>
void ArrayList<T>::remove(const T& item) 
{

}

template <class T>
int ArrayList<T>::size() const 
{
    return count;
}

template <class T>
bool ArrayList<T>::empty() const 
{
    return count == 0;
}

template <class T>
bool ArrayList<T>::contains(const T& item) const 
{

}

template <class T>
void ArrayList<T>::clear() 
{
    count = 0;
}

template <class T>
std::vector<T> ArrayList<T>::toVector() const 
{
    std::vector<T> vec;
    for (int i = 0; i < count; ++i)
    {
        vec.push_back(array[i]);
    }
    
    return vec;
}

#endif