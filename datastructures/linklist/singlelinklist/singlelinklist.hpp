/**
 * @function    单链表实现类。
 * @time    2018-08-09
 */
#ifndef DATA_STRUCTURES_LINKLIST_SINGLELINKLIST_SINGLELINKLIST_HPP_
#define DATA_STRUCTURES_LINKLIST_SINGLELINKLIST_SINGLELINKLIST_HPP_

#include "singlelinklistnode.h"
#include <string.h>
#include <iostream>

template <typename T>
class SingleLinkList
{
public:
    SingleLinkList()
    {
        maxsize_ = -1;
        head_ = nullptr;
        tail_ = nullptr;
        size_ = 0;
    }
    SingleLinkList(const SingleLinkList &obj) = delete;
    SingleLinkList &operator=(const SingleLinkList &obj) = delete;
    ~SingleLinkList()
    {
        Destroy();
    }

public:
    /**
     * @function    创建单向链表。
     * @paras   none 。
     * @ret none 。
     * @time    2019-08-09
     */
    void Create()
    {
        head_ = nullptr;
        tail_ = nullptr;
        size_ = 0;
        maxsize_ = -1;
    }

    void Create(size_t maxsize)
    {
        head_ = nullptr;
        tail_ = nullptr;
        size_ = 0;
        maxsize_ = maxsize;
    }

    /**
     * @function    销毁单向链表。
     * @paras   none 。
     * @ret none 。
     * @time    2019-08-09
     * --------------------------------
     * @modify  增加判断链表起始位置的功能。
     * @time    2019-08-15
     * @question    暂时不能解决带环的单链的释放问题。
     */
    void Destroy()
    {
        if (size_ == 0)
        {
            return;
        }
        SingleLinkListNode<T> *pnodebase = nullptr;
        SingleLinkListNode<T> *pnode = nullptr;

        tail_->next != nullptr ? pnodebase = tail_ : pnodebase = head_;
        while ((size_ != 0) and (pnodebase != nullptr))
        {
            pnode = pnodebase;
            pnodebase = pnodebase->next;

            delete pnode;
            pnode = nullptr;

            size_--;
        }
        tail_ = nullptr;
        head_ = nullptr;
    }

    /**
     * @function    在头部位置插入节点。
     * @paras   pnode   待插入的节点。
     *          pdata   待插入的数据。
     * @ret 0   操作成功。
     *      -1  pdata == nullptr  && pnode == nullptr
     *      -2  链表已满。
     * @time    2019-08-09
     * -----------------------------------------------
     * @modify  增加形参 pnode 。
     * @time    2019-08-14
     */
    int InsertHead(SingleLinkListNode<T> *pnode, T *pdata)
    {
        if ((pdata == nullptr) && (pnode == nullptr))
        {
            return -1;
        }
        if (size_ >= maxsize_)
        {
            return -2;
        }
        if (pnode == nullptr)
        {
            pnode = new SingleLinkListNode<T>;
            memset(pnode, 0, sizeof(SingleLinkListNode<T>) * 1);
            pnode->data = pdata;
        }

        if (isEmpty())
        {
            head_ = pnode;
            tail_ = pnode;
        }
        else
        {
            head_->next = pnode;
            head_ = pnode;
        }
        size_++;
        return 0;
    }

    /**
     * @function    在尾部位置插入节点。
     * @paras   pdata   待插入的数据。
     * @ret 0   操作成功。
     *      -1  pdata == nullptr 。
     *      -2  链表已满。
     * @time    2019-08-09
     * -----------------------------------------------
     * @modify  增加形参 pnode 。
     * @time    2019-08-14
     */
    int InsertTail(SingleLinkListNode<T> *pnode, T *pdata)
    {
        if ((pdata == nullptr) && (pnode == nullptr))
        {
            return -1;
        }
        if (size_ >= maxsize_)
        {
            return -2;
        }
        if (pnode == nullptr)
        {
            pnode = new SingleLinkListNode<T>;
            memset(pnode, 0, sizeof(SingleLinkListNode<T>) * 1);
            pnode->data = pdata;
        }

        if (isEmpty())
        {
            head_ = pnode;
            tail_ = pnode;
        }
        else
        {
            pnode->next = tail_;
            tail_ = pnode;
        }
        size_++;
        return 0;
    }

    /**
     * @function    删除指定的节点。
     * @paras   pdata   待插入的数据。
     * @ret 0   操作成功。
     *      -1  pdata == nullptr 。
     *      -2  链表为空 。
     *      -3  该节点在链表中不存在。
     * @time    2019-08-09
     */
    int RemoveNode(SingleLinkListNode<T> *pnode)
    {
        if (pnode == nullptr)
        {
            return -1;
        }
        if (isEmpty())
        {
            return -2;
        }

        SingleLinkListNode<T> *prev = nullptr;
        SingleLinkListNode<T> *next = nullptr;
        prev = tail_;
        if (pnode == tail_)
        {
            tail_ = tail_->next;
        }
        else
        {
            while (prev->next != pnode)
            {
                prev = prev->next;
                if (prev == nullptr)
                {
                    return -3;
                }
            }
            if (head_ == pnode)
            {
                head_ = prev;
            }

            next = prev->next->next;
            prev->next = next;
        }

        delete pnode;
        pnode = nullptr;

        size_--;
        return 0;
    }

    /**
     * @function    搜索指定的数据。
     * @paras   pdata   待插入的数据。
     * @ret 非nullptr   操作成功。
     *      nullptr 失败。
     * @time    2019-08-09
     */
    SingleLinkListNode<T> *SearchNode(T *pdata) const
    {
        if (pdata == nullptr)
        {
            return nullptr;
        }
        if (isEmpty())
        {
            return nullptr;
        }

        SingleLinkListNode<T> *pnode = nullptr;
        pnode = tail_;
        while (*pnode->data != *pdata)
        {
            pnode = pnode->next;
            if (pnode == nullptr)
            {
                return nullptr;
            }
        }
        return pnode;
    }

    /**
     * @function    返回头部节点。
     * @paras   node 。
     * @ret 头部节点。
     * @time    2019-08-09
     */
    SingleLinkListNode<T> *Head() const
    {
        return head_;
    }

    /**
     * @function    返回尾部节点。
     * @paras   node 。
     * @ret 尾部节点。
     * @time    2019-08-09
     */
    SingleLinkListNode<T> *Tail() const
    {
        return tail_;
    }

    /**
     * @function    判断链表是否为空。
     * @paras   node 。
     * @ret true    空
     *      false   非空
     * @time    2019-08-09
     */
    bool isEmpty() const
    {
        return !size_;
    }

    /**
     * @function    返回链表中节点的数量。
     * @paras   node 。
     * @ret 链表中节点的数量。
     * @time    2019-08-09
     */
    size_t Size() const
    {
        return size_;
    }

    /**
     * @function    返回链表中节点数量上限。
     * @paras   node 。
     * @ret 链表中节点数量上限。
     * @time    2019-08-09
     */
    size_t MaxSize() const
    {
        return maxsize_;
    }

    /**
     * @function    判断链表是否是满的。
     * @paras   node 。
     * @ret true    已满。
     *      false   未满。
     * @time    2019-08-09
     */
    bool isFull() const
    {
        return size_ == maxsize_;
    }

private:
    /**
     * 头部节点。
     */
    SingleLinkListNode<T> *head_;

    /**
     * 尾部节点。
     */
    SingleLinkListNode<T> *tail_;

    /**
     * 节点数量。
     */
    size_t size_;

    /**
     * 链表节点上限。
     */
    size_t maxsize_;
};

#endif