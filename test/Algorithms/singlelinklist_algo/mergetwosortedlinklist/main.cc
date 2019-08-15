#include "singlelinklist_algo/singlelinklist_algo.hpp"
#include <iostream>

template <typename T>
void ShowSingleLinkList(SingleLinkList<T> &kSLinkList);

int main()
{

    SingleLinkList<int> slinklist_1;
    SingleLinkList<int> slinklist_2;
    slinklist_1.Create(7);
    slinklist_2.Create(7);
    int testnum_1[7] = {1, 3, 5, 7, 9, 11, 16};
    int testnum_2[7] = {2, 4, 6, 10, 13, 14, 17};

    for (size_t i = 0; i < 7; i++)
    {
        slinklist_1.InsertHead(nullptr, &testnum_1[i]);
    }

    for (size_t i = 0; i < 7; i++)
    {
        slinklist_2.InsertHead(nullptr, &testnum_2[i]);
    }
    std::cout << "链表1：" << std::endl;
    ShowSingleLinkList(slinklist_1);

    std::cout << "链表2：" << std::endl;
    ShowSingleLinkList(slinklist_2);

    SingleLinkListNode<int> *pnode = MergeTwoSotedlinklist(slinklist_1, slinklist_2);

    std::cout << "合并之后的数据："<< std::endl;
    while (pnode)
    {
        std::cout << *pnode->data << "、";
        pnode = pnode -> next;
    }
    std::cout << std::endl;
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