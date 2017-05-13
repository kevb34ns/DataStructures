#include "Queue.h"
#include "gtest/gtest.h"

TEST(QueueTest, Test1)
{
   Queue<int> queue;

   ASSERT_TRUE(queue.empty());
   queue.push(0);
   ASSERT_FALSE(queue.empty());

   queue.push(1);
   queue.push(2);
   ASSERT_EQ(queue.front(), 0);

   Queue<int> queueCopy(queue);
   ASSERT_EQ(queueCopy.front(), 0);

   queue.pop();
   ASSERT_EQ(queueCopy.front(), 0);

   queue.pop();
   ASSERT_EQ(queue.front(), 2);

   queue.pop();
   ASSERT_TRUE(queue.empty());

   queue.push(0);
   queue.clear();
   ASSERT_TRUE(queue.empty());
}

int main(int argc, char** argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
