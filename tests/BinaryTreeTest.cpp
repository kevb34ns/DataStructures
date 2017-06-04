#include "BinaryTree.h"
#include "gtest/gtest.h"
#include <vector>

class BinaryTreeTest : public ::testing::Test
{
protected:
    BinaryTree<int>* tree;
    std::vector<int> vec;

    BinaryTreeTest()
    {
        tree = new BinaryTree<int>();
    }

    ~BinaryTreeTest()
    {
        delete tree;
    }

public:
    void visit(int& item)
    {
        vec.push_back(item);
    }
};

TEST_F(BinaryTreeTest, SimpleTest)
{
    ASSERT_TRUE(tree->empty());

    tree->add(1);
    tree->add(2);
    tree->add(3);

    ASSERT_EQ(tree->getRootData(), 1);
    ASSERT_EQ(tree->getNumNodes(), 3);
    ASSERT_EQ(tree->getTreeHeight(), 2);

    ASSERT_TRUE(tree->remove(2));
    ASSERT_FALSE(tree->contains(2));
    ASSERT_FALSE(tree->remove(4));

    EXPECT_FALSE(tree->empty());
    tree->setRootData(6);
    ASSERT_EQ(tree->getRootData(), 6);

    tree->clear();
    EXPECT_TRUE(tree->empty());
}

TEST_F(BinaryTreeTest, TraversalTest)
{
    tree->add(1);
    tree->add(2);
    tree->add(3);
    tree->add(4);

    // TODO need to pass a function pointer/change traversal methods because you can't have a function pointer that can reference vec to add the items
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << "item: " << vec[i] << std::endl;
    }
}

TEST_F(BinaryTreeTest, CopyTest)
{
    tree->add(1);
    tree->add(2);
    tree->add(3);
    tree->add(4);

    BinaryTree<int> constructedTree(*tree);
    ASSERT_EQ(constructedTree.getNumNodes(), 4);

    BinaryTree<int> assignedTree = *tree;
    ASSERT_EQ(assignedTree.getNumNodes(), 4);

    tree->add(5);
    ASSERT_EQ(constructedTree.getNumNodes(), 4);
    ASSERT_EQ(assignedTree.getNumNodes(), 4);
}

int main (int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
