/**
 * @function    linklist/doublelinklist/doublelinklist.hpp 的单元测试代码。
 * @author       xuchanglong
 * @time            2019-08-08
 */
#include "linklist/doublelinklist/doublelinklist.hpp"
#include <iostream>
#include <string.h>

/**
 * @function    依次从链表中取出元素，显示到控制台上。
 * @paras         kDLinkList   双向链表。
 * @return       none。
 * @author      xuchanglong
 * @time           2019-08-08
 */
template <typename T>
void ShowDoubleLinkList(DoubleLinkList<T> &kDLinkList);

/**
 * @function    针对不同存储类型的链表，进行测试。
 * @paras       pdata       待测试的数组。
 *              kDataSize    数组大小。
 * @return      测试结果。
 * @author      xuchanglong
 * @time           2019-08-08
 */
template <typename T>
int TestDoubleLinkList(T *pdata, const size_t &kDataSize);

int main()
{
    std::cout << "int" << std::endl;
    int isum[10] = {1, 43, 4, 3, 2, 9, 35, 654, 65, 732};
    TestDoubleLinkList(isum, 10);

    std::cout << std::endl
              << "double" << std::endl;

    double dsum[7] = {1.62, 89.854, 42.0254, 57.9513, 726.8913, 71345, 5251.54};
    TestDoubleLinkList(dsum, 7);

    std::cout << std::endl
              << "string" << std::endl;

    std::string strsum[12] = {"a1", "1.62", "c1", "42.0254", "e1", "f1", "aa2", "bb2", "cc2", "dd2", "ee2", "ff2"};
    TestDoubleLinkList(strsum, 12);

    return 0;
}

template <typename T>
void ShowDoubleLinkList(DoubleLinkList<T> &kDLinkList)
{
    DoubleLinkListNode<T> *pnode = nullptr;
    while (!kDLinkList.isEmpty())
    {
        pnode = kDLinkList.Tail();
        std::cout << *pnode->data << "、";
        kDLinkList.RemoveNode(pnode);
    }
    std::cout << std::endl;
}

template <typename T>
int TestDoubleLinkList(T *pdata, const size_t &kDataSize)
{
    DoubleLinkList<T> dlinklist;
    dlinklist.Create();
    //  向链表中中进行压入数据。
    std::cout << "-------------------  Enter  -------------------" << std::endl;
    for (size_t i = 0; i < kDataSize; i++)
    {
        if (dlinklist.InsertHead(pdata + i) != 0)
        {
            std::cout << pdata[i] << " can't enter linklist." << std::endl;
        }
    }
    ShowDoubleLinkList(dlinklist);
    return 0;
}