#include "BinaryTree.h"
#include "gtest/gtest.h"
#include <vector>

class BinaryTreeTest : public ::testing::Test
{
protected:
    BinaryTree<int>* tree;

    BinaryTreeTest()
    {
        tree = new BinaryTree<int>();
    }

    ~BinaryTreeTest()
    {
        delete tree;
    }

public:
    std::vector<int> vec;

};

class TestTraversal : public TraversalFunction<int>
{
private:
    BinaryTreeTest* mParent;

public:
    TestTraversal(BinaryTreeTest* parent)
    {
        mParent = parent;
    }

    virtual void visit(int& item)
    {
        mParent->vec.push_back(item);
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
    tree->add(5);
    tree->add(6);
    tree->add(7);
    tree->add(8);
    tree->add(9);
    tree->add(10);

    ASSERT_EQ(tree->getNumNodes(), 10);

    int preorder[] = { 1, 2, 4, 7, 6, 10, 3, 5, 9, 8 };
    int inorder[] = { 7, 4, 2, 10, 6, 1, 9, 5, 3, 8 };
    int postorder[] = { 7, 4, 10, 6, 2, 9, 5, 8, 3, 1 };

    TestTraversal* func = new TestTraversal(this);

    tree->preorderTraverse(func);
    for (int i = 0; i < vec.size(); i++)
    {
        EXPECT_EQ(vec[i], preorder[i]);
    }
    vec.clear();

    tree->inorderTraverse(func);
    for (int i = 0; i < vec.size(); i++)
    {
        EXPECT_EQ(vec[i], inorder[i]);
    }
    vec.clear();

    tree->postorderTraverse(func);
    for (int i = 0; i < vec.size(); i++)
    {
        EXPECT_EQ(vec[i], postorder[i]);
    }
    vec.clear();

    delete func;
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
