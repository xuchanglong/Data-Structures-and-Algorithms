/**
 * @function    单向链表的算法操作集合。
 * @time    2019-08-14
 * -------------------------------------------------
 * @modify  增加检测链表是否含有环的功能。
 * @time    2019-08-14
 * -------------------------------------------------
 * @modify  增加翻转链表、合并两个有序链表的功能。
 * @time    2019-08-15
 */
#ifndef ALGORITHMS_SINGLELINKLIST_ALGO_SINGLELINKLIST_ALGO_H_
#define ALGORITHMS_SINGLELINKLIST_ALGO_SINGLELINKLIST_ALGO_H_

#include "linklist/singlelinklist/singlelinklist.hpp"

/**
 * @function    基于单链表的 LRU 算法的实现。
 * @paras   slinklist   单链表的引用。
 *          pdata   待插入的数据。
 * @ret  0   操作成功。
 * @principle   1、搜索链表，当该数据在链表中存在时，则删除该数据对应的节点，并新建节点放到链表的首部。
 *              2、当该数据在链表中不存在时，判断链表是否已满，若满，则删除尾节点，并新建节点插入到链表的首部。
 *              3、当链表未满，则直接新建节点并插入至链表的首部。
 * @time    2019-08-10           
 */
template <typename T>
int LRU(SingleLinkList<T> &slinklist, T *pdata)
{
    if (pdata == nullptr)
    {
        return -1;
    }

    SingleLinkListNode<T> *pnode = slinklist.SearchNode(pdata);
    if (pnode)
    {
        slinklist.RemoveNode(pnode);
        slinklist.InsertHead(nullptr, pdata);
    }
    else
    {
        if (slinklist.isFull())
        {
            slinklist.RemoveNode(slinklist.Tail());
            slinklist.InsertHead(nullptr, pdata);
        }
        else
        {
            slinklist.InsertHead(nullptr, pdata);
        }
    }

    return 0;
}

/**
 * @function    检测链表中是否含有环。
 * @paras   slinklist   待检测的链表。
 * @ret true    有环。
 *      false   无环。   
 * @time    2019-08-14    
 */
template <typename T>
bool CheckCycle(const SingleLinkList<T> &slinklist)
{
    SingleLinkListNode<T> *ptail = slinklist.Tail();
    if ((ptail == nullptr) || (ptail->next == nullptr))
    {
        return false;
    }
    SingleLinkListNode<T> *pslow = ptail;
    SingleLinkListNode<T> *pfast = ptail;
    while ((pfast != nullptr) && (pfast->next != nullptr))
    {
        pslow = pslow->next;
        pfast = pfast->next->next;
        if (pslow == pfast)
        {
            return true;
        }
    }
    return false;
}

/**
 * @function    翻转单向链表。
 * @paras   slinklist   待检测的链表。
 * @ret  0   链表中至少有2个节点并且翻转成功。
 *       -1  链表为空或者只有一个节点。   
 * @time    2019-08-15   
 */
template <typename T>
int Reverse(const SingleLinkList<T> &slinklist)
{
    SingleLinkListNode<T> *ptail = slinklist.Tail();
    if ((ptail == nullptr) || (ptail->next == nullptr))
    {
        return -1;
    }
    SingleLinkListNode<T> *prev, *curr, *next;
    prev = nullptr;
    curr = ptail;
    next = ptail->next;
    while (curr->next != nullptr)
    {
        curr->next = prev;
        prev = curr;
        curr = next;
        next = curr->next;
    }
    curr->next = prev;
    return 0;
}

/**
 * @function    合并两个有序的链表。
 * @paras   slinklist_1   待合并的链表1
 *          slinklist_2   待合并的链表2
 * @ret  非nullptr  合并成功
 *       nullptr    两个链表为空。  
 * @time    2019-08-15   
 */
template <typename T>
SingleLinkListNode<T> *MergeTwoSortedlinklist(const SingleLinkList<T> &slinklist_1,
                                             const SingleLinkList<T> &slinklist_2)
{
    /**
     * 形参约束。
    */
    if (slinklist_1.isEmpty() || slinklist_2.isEmpty())
    {
        return nullptr;
    }
    SingleLinkListNode<T> *pnode_1, *pnode_2, *phead, *ptmp;
    pnode_1 = slinklist_1.Tail();
    pnode_2 = slinklist_2.Tail();
    phead = nullptr;
    ptmp = nullptr;

    /**
    * 确定合并之后的链表的首节点。
    */
    if (*pnode_1->data <= *pnode_2->data)
    {
        phead = pnode_1;
        pnode_1 = pnode_1->next;
    }
    else
    {
        phead = pnode_2;
        pnode_2 = pnode_2->next;
    }
    ptmp = phead;

    /**
     * 合并链表。
    */
    while (pnode_1 != nullptr && pnode_2 != nullptr)
    {
        if (*pnode_1->data <= *pnode_2->data)
        {
            ptmp->next = pnode_1;
            pnode_1 = pnode_1->next;
        }
        else
        {
            ptmp->next = pnode_2;
            pnode_2 = pnode_2->next;
        }
        ptmp = ptmp->next;
    }

    /**
    * 合并链表中剩余的节点。 
    */
    if (pnode_1 != nullptr)
    {
        ptmp->next = pnode_1;
    }
    else if (pnode_2 != nullptr)
    {
        ptmp->next = pnode_2;
    }

    return phead;
}

#endif