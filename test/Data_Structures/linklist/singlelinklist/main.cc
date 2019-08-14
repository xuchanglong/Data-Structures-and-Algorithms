/**
 * @function    linklist/singlelinklist/singlelinklist.hpp 的单元测试代码。
 * @author       xuchanglong
 * @time            2019-08-09
 */
#include "linklist/singlelinklist/singlelinklist.hpp"
#include <iostream>
#include <string.h>

/**
 * @function    依次从链表中取出元素，显示到控制台上。
 * @paras         kSLinkList   单向链表。
 * @return       none。
 * @author      xuchanglong
 * @time           2019-08-09
 */
template <typename T>
void ShowSingleLinkList(SingleLinkList<T> &kSLinkList);

/**
 * @function    针对不同存储类型的链表，进行测试。
 * @paras       pdata       待测试的数组。
 *              kDataSize    数组大小。
 * @return      测试结果。
 * @author      xuchanglong
 * @time           2019-08-09
 */
template <typename T>
int TestSingleLinkList(T *pdata, const size_t &kDataSize);

int main()
{
    std::cout << "int" << std::endl;
    int isum[10] = {1, 43, 4, 3, 2, 9, 35, 654, 65, 732};
    TestSingleLinkList(isum, 10);

    std::cout << std::endl
              << "double" << std::endl;

    double dsum[7] = {1.62, 89.854, 42.0254, 57.9513, 726.8913, 71345, 5251.54};
    TestSingleLinkList(dsum, 7);

    std::cout << std::endl
              << "string" << std::endl;

    std::string strsum[12] = {"a1", "1.62", "c1", "42.0254", "e1", "f1", "aa2", "bb2", "cc2", "dd2", "ee2", "ff2"};
    TestSingleLinkList(strsum, 12);

    return 0;
}

template <typename T>
void ShowSingleLinkList(SingleLinkList<T> &kSLinkList)
{
    SingleLinkListNode<T> *pnode = kSLinkList.Tail();
    while (pnode)
    {
        std::cout << *pnode->data << "、";
        pnode = pnode->next;
    }
    std::cout << std::endl;
}

template <typename T>
int TestSingleLinkList(T *pdata, const size_t &kDataSize)
{
    SingleLinkList<T> slinklist;
    slinklist.Create();
    //  向链表中中进行压入数据。
    std::cout << "-------------------  Enter  -------------------" << std::endl;
    for (size_t i = 0; i < kDataSize; i++)
    {
        if (slinklist.InsertHead(nullptr, pdata + i) != 0)
        {
            std::cout << pdata[i] << " can't enter linklist." << std::endl;
        }
    }
    ShowSingleLinkList(slinklist);
    return 0;
}