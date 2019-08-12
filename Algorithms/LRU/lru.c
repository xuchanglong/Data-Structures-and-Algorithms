/**
 * @function    基于单链表的 LRU 实现方法。
 * @author        xuchanglong
 * @time            2019-08-10
 */

#include "lru.h"
#include <string.h>

/**
 * @function    基于单链表的 LRU 算法的实现。
 * @paras          slinklist   单链表的引用。
 *                           pdata      待插入的数据。
 * @return         0    操作成功。
 * @priciple      1、搜索链表，当该数据在链表中存在时，则删除该数据对应的节点，并新建节点放到链表的首部。
 *                           2、当该数据在链表中不存在时，判断链表是否已满，若满，则删除尾节点，并新建节点插入到链表的首部。
 *                           3、当链表未满，则直接新建节点并插入至链表的首部。
 * @author       xuchanglong
 * @time            2019-08-10           
 */
template <typename T>
int LRU_SingleLinkList(SingleLinkList<T> &slinklist, T *pdata)
{
    if (pdata == nullptr)
    {
        return -1;
    }

    SingleLinkListNode<T> *pnode = slinklist.SearchNode(pdata);
    if (pnode)
    {
        slinklist.RemoveNode(pnode);
        slinklist.InsertHead(pdata);
    }
    else
    {
        if (slinklist.isFull())
        {
            slinklist.RemoveNode(slinklist.Tail());
            slinklist.InsertHead(pdata);
        }
        else
        {
            slinklist.InsertHead(pdata);
        }
    }

    return 0;
}
