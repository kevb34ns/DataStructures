/**
 * Array-based Binary Max-heap Implementation
 */

#include <stdexcept>
#include <cmath>

template <class T>
class Heap
{
private:
    const int ROOT_INDEX = 0; ///< index of the root
    const int DEFAULT_CAPACITY = 15; ///< default capacity to initialize array 

    T* items; ///< the array of items representing a heap
    int itemCount; ///< the number of items in the heap
    int capacity; ///< the maximum capacity of the current array

    /**
     * Calculate the index of the left child of an item in the array.
     * @param parentIndex The index of the parent.
     * @return the index of the left child of the specified item, or -1 if the
     *         item was invalid or has no left child. 
     */
    virtual int getLeftChildIndex(const int parentIndex) const;

    /**
     * Calculate the index of the right child of an item in the array.
     * @param parentIndex The index of the parent.
     * @return the index of the right child of the specified item, or -1 if the
     *         item was invalid or has no right child. 
     */
    virtual int getRightChildIndex(const int parentIndex) const;

    /**
     * Calculate the index of the parent of an item in the array.
     * @param childIndex The index of the child.
     * @return the index of the parent of the specified item, or -1 if the item
     *         was invalid or has no parent.
     */
    virtual int getParentIndex(const int childIndex) const;

    /**
     * Determine if a node is a leaf node (has no children).
     * @param index The index of the node in question.
     * @return true if the node is a leaf, false otherwise.
     */
    virtual bool isLeaf(const int index) const;

    /**
     * Swaps two elements in the heap.
     * @param index1 The index of the first element to swap.
     * @param index2 The index of the second element to swap.
     */
    virtual void swap(int index1, int index2);

    /**
     * Uses the recursive "trickle-down" method to move a node to its correct
     * position in the heap.
     * @pre A semiheap, with at most one item out of place located at @c
     *      subTreeIndex, where both subtrees of this item are valid heaps.
     * @post A valid max-heap.
     * @param subtreeIndex The index of the item to move to its correct place.
     */
    virtual void heapRebuild(int subtreeIndex);

    /**
     * Transforms an arbitrarily ordered array into a heap.
     */
    virtual void heapify();

    /**
     * Resizes the heap when its capacity has been reached, to allow for more
     * items to be added.
     */
    virtual void resize();

public:
    Heap(); ///< Default constructor

    /**
     * A constructor which takes an array, copies it, and transforms it into a
     * heap.
     * @param array The array to copy and transform.
     * @param size The number of items in the array.
     */
    Heap(const T* array, const int size);

    virtual ~Heap();

    /**
     * Determines if the heap is empty.
     * @return true if the heap is empty, false otherwise.
     */
    virtual bool isEmpty() const;

    /**
     * Determines the number of nodes in the heap.
     * @return the number of nodes in the heap.
     */
    virtual int getNumNodes() const;

    /** 
     * Determines the height of the heap.
     * @return the height of the heap.
     */
    virtual int getHeight() const;

    /**
     * @return the item at the top of the heap, which is the largest item in the
     * heap.
     */
    virtual const T& peekTop() const;

    /**
     * Adds a new item to the heap, according to the rules of a heap.
     * @param newData The item to add.
     * @return true if the item was added, false if some problem occurred and it
     *         was not added.
     */
    virtual bool add(const T& newData);
    
    /** 
     * Removes the item at the top of the heap.
     * @return true if the item was removed, false if some problem occurred and
     *         it was not added.
     */
    virtual bool remove();

    /**
     * Removes all items from the heap.
     */
    virtual void clear();

};

template <class T>
Heap<T>::Heap() : itemCount(0), capacity(DEFAULT_CAPACITY)
{
    items = new T[capacity];
}

template <class T>
Heap<T>::Heap(const T* array, const int size) : capacity(size)
{
    items = new T[size];
    for (int i = 0; i < size; i++)
    {
        items[i] = array[i];
    }

    heapify();
}

template <class T>
Heap<T>::~Heap()
{
    clear();
}

template <class T>
int Heap<T>::getLeftChildIndex(const int parentIndex) const
{
    if (parentIndex < 0)
    {
        return -1;
    }

    int leftChildIndex = parentIndex * 2 + 1;
    return (leftChildIndex < itemCount) ? leftChildIndex : -1;
}

template <class T>
int Heap<T>::getRightChildIndex(const int parentIndex) const
{
    if (parentIndex < 0)
    {
        return -1;
    }

    int rightChildIndex = parentIndex * 2 + 2;
    return (rightChildIndex < itemCount) ? rightChildIndex : -1;
}

template <class T>
int Heap<T>::getParentIndex(const int childIndex) const
{
    if (childIndex <= 0 || childIndex >= itemCount)
    {
        return -1;
    }

    int parentIndex = childIndex / 2 - 1;
    return parentIndex;
}

template <class T>
bool Heap<T>::isLeaf(const int index) const
{
    if (index < 0 || index >= itemCount)
    {
        return false;
    }
    else
    {
        return index >= (itemCount + 1) / 2;
    }
}

template <class T>
void Heap<T>::swap(int index1, int index2)
{
    T temp = items[index1];
    items[index1] = items[index2];
    items[index2] = temp;
}

template <class T>
void Heap<T>::heapRebuild(int subtreeIndex)
{
    if (subtreeIndex < 0 || subtreeIndex >= itemCount)
    {
        throw std::range_error("Passed an invalid index parameter to\
                                Heap<T>::heapRebuild.");
    }

    int left = getLeftChildIndex(subtreeIndex);
    int right = getRightChildIndex(subtreeIndex);
    
    if (isLeaf(subtreeIndex) || (items[subtreeIndex] >= left && 
                                 items[subtreeIndex] >= right))
    {
        return;
    }

    if (left >= right)
    {
        swap(subtreeIndex, left);
        heapRebuild(left);
    }
    else
    {
        swap(subtreeIndex, right);
        heapRebuild(right);
    }
}

template <class T>
void Heap<T>::heapify()
{
    for (int i = itemCount / 2 - 1; i >= 0; i--)
    {
        heapRebuild(i);
    }
}

template <class T>
void Heap<T>::resize()
{
    capacity *= 2;
    T* newArray = new T[capacity];
    for (int i = 0; i < itemCount; ++i)
    {
        newArray[i] = items[i];
    }
    delete[] items;
    items = newArray;
}

template <class T>
bool Heap<T>::isEmpty() const
{
    return itemCount == 0;
}

template <class T>
int Heap<T>::getNumNodes() const
{
    return itemCount;
}

template <class T>
int Heap<T>::getHeight() const
{
    return ceil(log2(itemCount));
}

template <class T>
const T& Heap<T>::peekTop() const
{
    if (isEmpty())
    {
        throw std::range_error("Tried to call Heap<T>::peekTop() on an empty \
                                heap.");
    }

    return items[0];
}

template <class T>
bool Heap<T>::add(const T& newData)
{
    if (itemCount == capacity)
    {
        resize();
    }

    items[itemCount] = newData;

    // i represents the current index of the new item
    int i = itemCount;
    while (i > 0)
    {
        int parentIndex = getParentIndex(i);
        if (items[i] > items[parentIndex])
        {
            swap(i, parentIndex);
            i = parentIndex;
        }
        else
        {
            break;
        }
    }

    itemCount++;
    return true;
}

template <class T>
bool Heap<T>::remove()
{
    if (isEmpty())
    {
        return false;
    }

    swap(0, itemCount - 1);
    itemCount--;
    heapRebuild(0);

    return true;
}

template <class T>
void Heap<T>::clear()
{
    delete[] items;
    items = nullptr;
    itemCount = 0;
}
