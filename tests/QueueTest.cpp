#include "Queue.h"
#include "gtest/gtest.h"

class QueueTest : public ::testing::Test 
{
protected:
   Queue<int> queue;

   QueueTest()
   {

   }

   ~QueueTest()
   {

   }
};

TEST_F(QueueTest, Test1)
{
   //TODO test copy constructor/assignment operator
   ASSERT_TRUE(queue.empty());
   queue.push(0);
   ASSERT_FALSE(queue.empty());

   queue.push(1);
   queue.push(2);
   ASSERT_EQ(queue.front(), 0);

   queue.pop();
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
