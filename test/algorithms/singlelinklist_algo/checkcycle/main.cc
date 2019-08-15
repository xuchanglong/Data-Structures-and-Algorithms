#include "singlelinklist_algo/singlelinklist_algo.hpp"
#include <iostream>

int main()
{

    SingleLinkList<int> slinklist;
    slinklist.Create(11);
    int testnum[10] = {1, 2, 3, 4, 5, 2, 6, 4, 8, 4};
    SingleLinkListNode<int> **pnode = new SingleLinkListNode<int> *[10];
    for (size_t i = 0; i < 10; i++)
    {
        pnode[i] = new SingleLinkListNode<int>;
        memset(pnode[i], 0, sizeof(SingleLinkListNode<int>) * 1);
        pnode[i]->data = testnum + i;
    }

    for (size_t i = 0; i < 10; i++)
    {
        slinklist.InsertHead(pnode[i], nullptr);
    }
    /**
     *  形成环。 
     */
    slinklist.InsertHead(pnode[3], nullptr);

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