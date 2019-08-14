#include "singlelinklist_algo/singlelinklist_algo.hpp"
#include <iostream>

template <typename T>
void ShowSingleLinkList(SingleLinkList<T> &kSLinkList);

int main()
{

    SingleLinkList<int> slinklist;
    slinklist.Create(5);
    int testnum[10] = {1,2,3,4,5,2,6,4,8,4}; 

    for (size_t i = 0; i < 10; i++)
    {
        std::cout << "next" << std::endl;

        LRU_SingleLinkList(slinklist, testnum + i);
        ShowSingleLinkList(slinklist);
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