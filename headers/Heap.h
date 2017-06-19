/**
 * Array-based Binary Max-heap Implementation
 */

template <class T>
class Heap
{
private:
    const int ROOT_INDEX = 0; ///< index of the root
    const int DEFAULT_CAPACITY = 31; ///< default capacity to initialize array 

    T* items; ///< the array of items representing a heap
    int itemCount; ///< the number of items in the heap
    int capacity; ///< the maximum capacity of the current array

    /**
     * Calculate the index of the left child of an item in the array.
     * @param parentIndex The index of the parent.
     * @return the index of the left child of the specified item. 
     */
    virtual int getLeftChildIndex(const int parentIndex) const;

    /**
     * Calculate the index of the right child of an item in the array.
     * @param parentIndex The index of the parent.
     * @return the index of the right child of the specified item. 
     */
    virtual int getRightChildIndex(const int parentIndex) const;

    /**
     * Calculate the index of the parent of an item in the array.
     * @param childIndex The index of the child.
     * @return the index of the parent of the specified item.
     */
    virtual int getParentIndex(const int childIndex) const;

    /**
     * Determine if a node is a leaf node (has no children).
     * @param index The index of the node in question.
     * @return true if the node is a leaf, false otherwise.
     */
    virtual bool isLeaf(const int index) const;

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
     * Creates a valid heap out of an arbitrarily ordered array.
     * @param array A pointer to the array of T which will be transformed into
     * a heap.
     */
    virtual void heapCreate(T* array);

public:
    Heap();
    Heap(T* array, const int size);
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

template <class T>j
Heap<T>::Heap()
{

}

template <class T>j
Heap<T>::Heap(int* array, const int size)
{

}

template <class T>j
Heap<T>::~Heap()
{

}

template <class T>j
int Heap<T>::getLeftChildIndex(const int parentIndex) const
{

}

template <class T>j
int Heap<T>::getRightChildIndex(const int parentIndex) const
{

}

template <class T>j
int Heap<T>::getParentIndex(const int childIndex) const
{

}

template <class T>
bool Heap<T>::isLeaf(const int index) const
{

}

template <class T>
void Heap<T>::heapRebuild(int subtreeIndex)
{

}

template <class T>
void Heap<T>::heapCreate()
{

}

template <class T>
bool Heap<T>::isEmpty() const
{

}

template <class T>
int Heap<T>::getNumNodes() const
{

}

template <class T>
int Heap<T>::getHeight() const
{

}

template <class T>
const T& Heap<T>::peekTop() const
{

}

template <class T>
bool Heap<T>::add(const T& newData)
{

}

template <class T>
bool Heap<T>::remove()
{

}

template <class T>
void Heap<T>::clear()
{

}
