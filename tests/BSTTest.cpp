#include "BinarySearchTree.h"
#include "gtest/gtest.h"
#include <vector>

class BSTTest : public ::testing::Test
{
protected:
    BinarySearchTree<int>* tree;

    BSTTest()
    {
        tree = new BinarySearchTree<int>();
    }

    ~BSTTest()
    {
        delete tree;
    }
};

class TraverseBST : public TraversalFunction<int>
{
public:
    std::vector<int> vec;

    TraverseBST()
    {

    }

    virtual ~TraverseBST()
    {

    }

    virtual void visit(int& item)
    {
        vec.push_back(item);
    }
};

TEST_F(BSTTest, SimpleTest)
{
    tree->add(2);
    tree->add(4);
    tree->add(3);
    tree->add(1);
    tree->add(0);

    ASSERT_TRUE(tree->contains(0));

    TraverseBST* func = new TraverseBST();
    tree->inorderTraverse(func);

    for (int i = 0; i < func->vec.size(); i++)
    {
        EXPECT_EQ(func->vec[i], i);
    }

    delete func;

    tree->remove(2);
    ASSERT_FALSE(tree->contains(2));
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
