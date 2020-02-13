/**
 * 一、二叉搜索树增、删、改的效率：
 * 1、最坏情况：二叉树退化为链表，时间复杂度为O(n)。
 * 2、最好情况：二叉树为完全二叉树，时间复杂度为O(logn)。
 * 总结，时间复杂度的范围(O(logn),O(n))
 * 
 * 针对第2种情况，推导如下：
 * 假设，二叉树的层数为L，则层和该层的节点数目对应关系如下：
 *      1    1
 *      2    2
 *      3    4
 *      4    8
 *      ……   ……
 *      L    2^(L-1)
 * 因为是完全二叉树，故最后一层节点数目有可能不全，故最终的L层
 * 的二叉搜索树的节点数量的范围： 
 *      (1 + 2 + 4 + 8 + …… + 2^(L-2) + 1) <= n <= (1 + 2 + 4 + 8 + …… + 2^(L-1))
 * 根据等比公式，结果： 
 *      2^(L-1) <= n <= 2^L-1 
 * L的范围：
 *      L-1 <= logn
 *      log(n+1) <= L
 * ==>  log(n+1) <= L <= logn+1
 * 
 * 故完全二叉树的查找操作的时间复杂度为 O(logn)。
 * 
 * 二、散列表和二叉查找树的对比。
 * 问题：散列表的增、删、查的时间复杂度均是O(1)，而二叉查找树在较平衡的情况下时间复杂度才是O(logn),
 * 为什么要选择平衡二叉树呢。
 * 答案：
 * 1、排序，散列表是无序存储的，排序时时间复杂度就上来了。
 * 二叉查找树则只需要中序遍历即可，在O(n)的时间复杂度内就可完成。
 * 2、散列表扩容时耗时很多，而且在散列冲突时性能不稳定。
 * 平衡二叉树性能很稳定在O(logn)中。
 * 3、尽管散列表查找操作是常量级的，但是在哈希冲突的存在下，时间复杂度就不确定了，有可能比O(logn)
 * 还有大，再加上哈希函数本身的算法耗时，总的下来时间也不低。
 * 4、散列表表设计复杂，需要考虑哈希函数的设计、哈希冲突、扩容和缩容问题。
 * 而平衡二叉树只需要考虑平衡性的问题。class
*/

#include <iostream>
class TreeNode
{
public:
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){};

public:
    int val;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *SearchBST(TreeNode *root, int key)
{
    while (root != nullptr)
    {
        if (key == root->val)
        {
            return root;
        }
        root = root->val > key ? root->left : root->right;
    }
    return nullptr;
}

void InsertBST(TreeNode *&root, int data)
{
    TreeNode *node = new TreeNode(data);
    if (root == nullptr)
    {
        root = node;
        return;
    }

    if (SearchBST(root, data) != nullptr)
        return;
    TreeNode *preNode = nullptr;
    TreeNode *curNode = root;
    while (curNode)
    {
        preNode = curNode;
        curNode = curNode->val > data ? curNode->left : curNode->right;
    }
    if (preNode->val > data)
    {
        preNode->left = node;
    }
    else
    {
        preNode->right = node;
    }
    return;
}

void MinOrderVisit(TreeNode *root)
{
    if (root == nullptr)
        return;
    MinOrderVisit(root->left);
    std::cout << root->val << " ";
    MinOrderVisit(root->right);
    return;
}

void DeleteBST(TreeNode *&root, int data)
{

    if (root == nullptr)
        return;

    if (root->val == data)
    {
        TreeNode *p = root;
        if (root->left == nullptr && root->right == nullptr)
        {
            root = nullptr;
        }
        else if (root->left == nullptr)
        {
            root = root->right;
        }
        else if (root->right == nullptr)
        {
            root = root->left;
        }
        else
        {
            TreeNode *temp = root->right;
            TreeNode *find = nullptr;
            while (temp)
            {
                find = temp;
                temp = temp->left;
            }
            find->left = root->left;
            root = root->right;
        }
        delete p;
    }
    else if (root->val > data)
    {
        DeleteBST(root->left, data);
    }
    else
    {
        DeleteBST(root->right, data);
    }
    return;
}

int main()
{

    int a[] = {2, 1, 4, 3, 5, 6, 8, 7, 9, 10};
    int len = sizeof(a) / sizeof(a[0]);
    TreeNode *p = nullptr;
    for (int i = 0; i < len; i++)
    {
        InsertBST(p, a[i]);
    }
    DeleteBST(p, 7);
    MinOrderVisit(p);
    return 0;
}