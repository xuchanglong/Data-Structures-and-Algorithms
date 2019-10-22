/**
 * @function    待哨兵节点的双向循环链表的实现类。
 * @time    2019-08-12
 */
#ifndef DATA_STRUCTURES_LINKLIST_CYCLEDOUBLELINKLIST_CYCLEDOUBLELINKLIST_HPP_
#define DATA_STRUCTURES_LINKLIST_CYCLEDOUBLELINKLIST_CYCLEDOUBLELINKLIST_HPP_

#include "cycledoublelinklistnode.hpp"
#include <cstddef>

template <typename T>
class CycleDoubleLinkList
{
public:
    CycleDoubleLinkList()
    {
        pSentinel = nullptr;
        size_ = 0;
        maxsize_ = -1;
    }
    CycleDoubleLinkList(const CycleDoubleLinkList &obj) = delete;
    CycleDoubleLinkList &operator=(const CycleDoubleLinkList &obj) = delete;
    ~CycleDoubleLinkList()
    {
        Destroy();
        delete pSentinel;
        pSentinel = nullptr;
    }

public:
    /**
     * @function    创建双向循环链表。
     * @paras   none 。
     * @ret none 。
     * @time    2019-08-12
     */
    void Create()
    {
        pSentinel = new CycleDoubleLinkListNode<T>;
        ClearSentinel();
        size_ = 0;
        maxsize_ = -1;
    }

    /**
     * @function    创建双向循环链表。
     * @paras   none 。
     * @ret none 。
     * @time    2019-08-12
     */
    void Create(size_t maxsize)
    {
        pSentinel = new CycleDoubleLinkListNode<T>;
        ClearSentinel();
        size_ = 0;
        maxsize_ = maxsize;
    }

    /**
     * @function    销毁双向循环链表。
     * @paras   none 。
     * @ret none 。
     * @time    2019-08-12
     */
    void Destroy()
    {
        CycleDoubleLinkListNode<T> *ptmp = nullptr;
        while (size_)
        {
            ptmp = pSentinel->next;
            pSentinel->next = pSentinel->next->next;

            delete ptmp;
            ptmp = nullptr;
            size_--;
        }
        pSentinel->prev = nullptr;
    }

    /**
     * @function    向链表的头部插入新的数据。
     * @paras   pdata   待插入的数据。
     * @ret 0   操作成功。
     *      -1  pdata == nullptr
     *      -2  链表已满。
     * @time    2019-08-12
     */
    int InsertHead(T *pdata)
    {
        if (pdata == nullptr)
        {
            return -1;
        }
        if (size_ >= maxsize_)
        {
            return -2;
        }

        CycleDoubleLinkListNode<T> *pnode = new CycleDoubleLinkListNode<T>;
        pnode->data = pdata;

        pnode->next = pSentinel->next;
        pnode->prev = pSentinel;
        pSentinel->next = pnode;
        pnode->next->prev = pnode;

        size_++;
        return 0;
    }

    /**
     * @function    向链表的尾部插入新的数据。
     * @paras   pdata   待插入的数据。
     * @ret 0   操作成功。
     *      -1  pdata == nullptr
     *      -2  链表已满。
     * @time    2019-08-12
     */
    int InsertTail(T *pdata)
    {
        if (pdata == nullptr)
        {
            return -1;
        }
        if (size_ >= maxsize_)
        {
            return -2;
        }

        CycleDoubleLinkListNode<T> *pnode = new CycleDoubleLinkListNode<T>;
        pnode->data = pdata;

        pnode->next = pSentinel;
        pnode->prev = pSentinel->prev;
        pSentinel->prev = pnode;
        pnode->prev->next = pnode;

        size_++;
    }

    /**
     * @function    删除链表中指定的节点。
     * @paras   pnode   待删除的节点。
     * @ret 0   操作成功。
     *      -1  pnode == nullptr
     * @time    2019-08-12
     */
    int RemoveNode(CycleDoubleLinkListNode<T> *&pnode)
    {
        if (pnode == nullptr)
        {
            return -1;
        }

        pnode->next->prev = pnode->prev;
        pnode->prev->next = pnode->next;

        delete pnode;
        pnode = nullptr;

        size_--;
        return 0;
    }

    /**
     * @function    搜索链表中指定数据的节点，并返回第一个。（从头部开始搜索）
     * @paras   data   待搜索的数据。
     * @ret 非nullptr   操作成功。
     *      nullptr 未找到指定数据的节点。
     * @time    2019-08-12
     */
    CycleDoubleLinkListNode<T> *SearchNode(T *data)
    {
        CycleDoubleLinkListNode<T> *ptmp = pSentinel->next;
        while (ptmp->data != nullptr)
        {
            if (*ptmp->data == *data)
            {
                return ptmp;
            }
            ptmp = ptmp->next;
        }
        return nullptr;
    }

    /**
     * @function    返回头部节点。
     * @paras   none 。
     * @ret 头部节点。
     * @time    2019-08-12
     */
    CycleDoubleLinkListNode<T> *Head()
    {
        return pSentinel->next;
    }

    /**
     * @function    返回尾部节点。
     * @paras   none 。
     * @ret 尾部节点。
     * @time    2019-08-12
     */
    CycleDoubleLinkListNode<T> *Tail()
    {
        return pSentinel->prev;
    }

    /**
     * @function    返回链表中节点数量。
     * @paras   none 。
     * @ret 链表中的节点数量。
     * @time    2019-08-12
     */
    size_t Size()
    {
        return size_;
    }

    /**
     * @function    返回链表中节点数量上限。
     * @paras   none 。
     * @ret 链表中的节点数量。
     * @time    2019-08-12
     */
    size_t MaxSize()
    {
        return maxsize_;
    }

    /**
     * @function    返回该链表是否为空的标志。
     * @paras   none 。
     * @ret true，为空，反之为false。
     * @time    2019-08-12
     */
    bool isEmpty()
    {
        return !size_;
    }
private:
    void ClearSentinel()
    {
        if (pSentinel)
        {
            pSentinel->data = nullptr;
            pSentinel->next = pSentinel;
            pSentinel->prev = pSentinel;
        }
    }
private:
    /**
     * 哨兵节点。
     * pSentinel->next 代表双向链表的头节点。
     * pSentinel->prev 代表双向链表的尾节点。
     */
    CycleDoubleLinkListNode<T> *pSentinel;

    /**
     * 链表中节点的数量。
     */
    size_t size_;

    /**
     * 链表节点上限。
     */
    size_t maxsize_;
};

#endif