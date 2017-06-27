#include "gtest/gtest.h"
#include "Heap.h"

TEST(HeapTest, SimpleHeapTest)
{
    Heap<int> heap;

    EXPECT_TRUE(heap.isEmpty());

    heap.add(1);
    heap.add(2);
    heap.add(3);

    EXPECT_EQ(heap.getNumNodes(), 3);
    EXPECT_EQ(heap.getHeight(), 2);

    for (int i = 4; i <= 15; i++)
    {
        heap.add(i);
    }

    ASSERT_EQ(heap.getNumNodes(), 15);
    EXPECT_EQ(heap.getHeight(), 4);

    int* testArray = new int[15];
    for (int i = 0; i < 15; i++)
    {
        testArray[i] = heap.peekTop();
        heap.remove();
    }

    for (int i = 0; i < 14; i++)
    {
        EXPECT_GE(testArray[i], testArray[i + 1]);
    }

    heap.clear();

    EXPECT_TRUE(heap.isEmpty());

    delete[] testArray;
}

TEST(HeapTest, CopyTest)
{
    const int SIZE = 20;    
    int* array = new int[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        array[i] = i;
    }

    Heap<int> heap(array, SIZE);
    EXPECT_EQ(heap.getNumNodes(), SIZE);

    delete[] array;

    array = new int[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        array[i] = heap.peekTop();
        heap.remove();
    }

    for (int i = SIZE - 1; i >= 0; i--)
    {
        EXPECT_EQ(i, array[SIZE - i - 1]);
    }

    delete[] array;
}

int main (int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
