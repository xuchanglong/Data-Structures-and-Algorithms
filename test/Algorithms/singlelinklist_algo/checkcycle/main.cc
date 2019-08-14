#include "singlelinklist_algo/singlelinklist_algo.hpp"
#include <iostream>

template <typename T>
void ShowSingleLinkList(SingleLinkList<T> &kSLinkList);

int main()
{

    SingleLinkList<int> slinklist;
    slinklist.Create(11);
    int testnum[10] = {1,2,3,4,5,2,6,4,8,4}; 

    for (size_t i = 0; i < 10; i++)
    {
        slinklist.InsertHead(&testnum[i]);
    }

    std::cout << "无环的链表：" << std::endl;
    ShowSingleLinkList(slinklist);

    slinklist.InsertHead(&testnum[0]);

    std::cout << "有环的链表：" << std::endl;
    ShowSingleLinkList(slinklist);

    if (CheckCycle(slinklist))
    {
        std::cout << "This single linklist has cycle." << std::endl;
    }
    else
    {
        std::cout << "This single linklist has not cycle." << std::endl;
    }
    

    slinklist.Destroy();
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