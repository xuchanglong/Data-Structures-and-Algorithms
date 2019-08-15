#include "singlelinklist_algo/singlelinklist_algo.hpp"
#include <iostream>

template <typename T>
void ShowSingleLinkList(SingleLinkList<T> &kSLinkList,SingleLinkListNode<T> *pnodebase);

int main()
{

    SingleLinkList<int> slinklist;
    slinklist.Create(5);
    int testnum[10] = {1, 2, 3, 4, 5, 2, 6, 4, 8, 4};

    for (size_t i = 0; i < 10; i++)
    {
        slinklist.InsertHead(nullptr, &testnum[i]);
    }
    std::cout << "翻转之前的链表中的数据：" << std::endl;
    ShowSingleLinkList(slinklist,slinklist.Tail());

    Reverse(slinklist);

    std::cout << "翻转之后的链表中的数据：" << std::endl;
    ShowSingleLinkList(slinklist,slinklist.Head());

    slinklist.Destroy();
    return 0;
}

template <typename T>
void ShowSingleLinkList(SingleLinkList<T> &kSLinkList,SingleLinkListNode<T> *pnodebase)
{
    SingleLinkListNode<T> *pnode = pnodebase;
    while (pnode)
    {
        std::cout << *pnode->data << "、";
        pnode = pnode->next;
    }
    std::cout << std::endl;
}