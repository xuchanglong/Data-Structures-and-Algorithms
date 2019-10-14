#include <iostream>
#include <cstdlib>

struct BinaryTreeNode
{
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
};

using BinaryTree = BinaryTreeNode;

/**
 * 创建二叉树。
*/
int BinaryTree_Create(BinaryTree **root)
{
    std::string s;
    std::cout << "请输入节点值：";
    std::cin >> s;
    if (s == "#")
    {
        return 0;
    }
    *root = new BinaryTree();
    (*root)->data = atoi(s.c_str());
    (*root)->left = nullptr;
    (*root)->right = nullptr;

    BinaryTree_Create(&(*root)->left);
    BinaryTree_Create(&(*root)->right);
    return 0;
}

/**
 * 销毁指定的二叉树。
*/
int Binary_Destroy(BinaryTree **root)
{
    if ((*root) == nullptr)
    {
        return -1;
    }
    Binary_Destroy(&(*root)->left);
    Binary_Destroy(&(*root)->right);
    delete (*root);
    (*root) = nullptr;
    return 0;
}

/**
 * 前序遍历。
 * 对于树的任意节点，先打印本节点，再打印其左子树，最后打印其右子树。
*/
int BinaryTree_PreOrder(BinaryTree *root)
{
    if (root == nullptr)
    {
        return -1;
    }
    std::cout << root->data << "、";
    BinaryTree_PreOrder(root->left);
    BinaryTree_PreOrder(root->right);
    return 0;
}

/**
 * 中序遍历。
 * 对于树的任意节点，先打印其左子树，再打印本节点，最后打印其右子树。
*/
int BinaryTree_InOrder(BinaryTree *root)
{
    if (root == nullptr)
    {
        return -1;
    }
    BinaryTree_InOrder(root->left);
    std::cout << root->data << "、";
    BinaryTree_InOrder(root->right);
    return 0;
}

/**
 * 后序遍历。
 * 对于树的任意节点，先打印其左子树，再打印其右子树，最后打印本节点。
*/
int BinaryTree_PostOrder(BinaryTree *root)
{
    if (root == nullptr)
    {
        return -1;
    }
    BinaryTree_PostOrder(root->left);
    std::cout << root->data << "、";
    BinaryTree_PostOrder(root->right);
    return 0;
}

int main()
{
    BinaryTree *root = nullptr;
    BinaryTree_Create(&root);

    std::cout << "前序遍历：" << std::endl;
    BinaryTree_PreOrder(root);
    std::cout << std::endl;

    std::cout << "中序遍历：" << std::endl;
    BinaryTree_InOrder(root);
    std::cout << std::endl;

    std::cout << "后序遍历：" << std::endl;
    BinaryTree_PostOrder(root);
    std::cout << std::endl;

    Binary_Destroy(&root);
    return 0;
}