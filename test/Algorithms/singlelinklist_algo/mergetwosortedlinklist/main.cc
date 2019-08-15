#include "singlelinklist_algo/singlelinklist_algo.hpp"
#include <iostream>

template <typename T>
void ShowSingleLinkList(SingleLinkList<T> &kSLinkList, SingleLinkListNode<T> *pnodebase);

int main()
{

    SingleLinkList<int> slinklist_1;
    SingleLinkList<int> slinklist_2;
    slinklist_1.Create(5);
    slinklist_2.Create(5);
    int testnum_1[7] = {1, 3, 5, 7, 9, 11, 16};
    int testnum_2[9] = {2, 4, 6, 10, 13, 14, 17};

    for (size_t i = 0; i < 10; i++)
    {
        slinklist.InsertHead(nullptr, &testnum_1[i]);
    }
    std::cout << "翻转之前的链表中的数据：" << std::endl;
    ShowSingleLinkList(slinklist, slinklist.Tail());

    Reverse(slinklist);

    std::cout << "翻转之后的链表中的数据：" << std::endl;
    ShowSingleLinkList(slinklist, slinklist.Head());

    slinklist.Destroy();
    return 0;
}

template <typename T>
void ShowSingleLinkList(SingleLinkList<T> &kSLinkList, SingleLinkListNode<T> *pnodebase)
{
    SingleLinkListNode<T> *pnode = pnodebase;
    while (pnode)
    {
        std::cout << *pnode->data << "、";
        pnode = pnode->next;
    }
    std::cout << std::endl;
}