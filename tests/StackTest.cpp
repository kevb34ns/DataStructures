#include "Stack.h"
#include "gtest/gtest.h"

class StackTest : public ::testing::Test 
{
protected:
   Stack<int> stack;

   StackTest()
   {

   }

   ~StackTest()
   {

   }
};

TEST_F(StackTest, Test1)
{
   ASSERT_TRUE(stack.empty());
   stack.push(0);
   ASSERT_FALSE(stack.empty());

   stack.push(1);
   stack.push(2);
   ASSERT_EQ(stack.top(), 2);

   Stack<int> stackCopy(stack);
   ASSERT_EQ(stackCopy.top(), 2);

   stack.pop();
   ASSERT_EQ(stackCopy.top(), 2);

   stack.pop();
   ASSERT_EQ(stack.top(), 0);

   stack.pop();
   ASSERT_TRUE(stack.empty());

   stack.push(0);
   stack.clear();
   ASSERT_TRUE(stack.empty());
}

int main(int argc, char** argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
