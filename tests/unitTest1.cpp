#include "ArrayList.h"
#include "gtest/gtest.h"
#include <vector>
#include <cstdlib>

class ArrayListTest : public ::testing::Test 
{
protected:
	ArrayList<int> list;

	ArrayListTest() : list(10)
	{

	}

	~ArrayListTest()
	{

	}

};

TEST_F(ArrayListTest, SimpleAddTest) 
{
	list.add(0);
	list.add(1);
	list.add(2);
	list.add(3);

	std::vector<int> vec = list.toVector();
	for (int i = 0; i < 4; i++) {
		ASSERT_EQ(vec.at(i), i);
	}

	ASSERT_FALSE(list.empty());
	ASSERT_EQ(list.size(), 4);
}

TEST_F(ArrayListTest, SimpleRemoveTest)
{
	int num = 15;
	for (int i = 0; i < num; ++i)
	{
		list.add(i);
	}

	for (int i = 0; i < num; ++i)
	{
		list.remove(i);
		ASSERT_EQ(list.size(), num - i - 1);
	}

	ASSERT_TRUE(list.empty());
}

TEST_F(ArrayListTest, SimpleContainsTest)
{
	int n = rand();
	list.add(n);
	ASSERT_TRUE(list.contains(n));
}

TEST_F(ArrayListTest, ResizeTest)
{
	int num = 101;
	for (int i = 0; i < num; i++) {
		list.add(i);
	}

	ASSERT_EQ(list.size(), num);
}

int main(int argc, char** argv) 
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();	
}