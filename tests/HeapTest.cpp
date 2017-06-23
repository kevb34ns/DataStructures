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
        ASSERT_GE(testArray[i], testArray[i - 1]);
    }

    delete[] testArray;
}

TEST(HeapTest, CopyTest)
{

}

int main (int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
