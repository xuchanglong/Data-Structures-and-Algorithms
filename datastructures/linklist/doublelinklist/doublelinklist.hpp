/**
 * @function    双向链表实现类。
 * @time    2019-08-08
 */
#ifndef DATA_STRUCTURES_LINKLIST_DOUBLELINKLIST_DOUBLELINKLIST_HPP_
#define DATA_STRUCTURES_LINKLIST_DOUBLELINKLIST_DOUBLELINKLIST_HPP_

#include "doublelinklistnode.hpp"
#include <cstddef>

template <typename T>
class DoubleLinkList
{
public:
    DoubleLinkList()
    {
        head_ = nullptr;
        tail_ = nullptr;
        size_ = 0;
        maxsize_ = -1;
    }
    DoubleLinkList(const DoubleLinkList &obj) = delete;
    DoubleLinkList &operator=(const DoubleLinkList &obj) = delete;
    ~DoubleLinkList()
    {
        Destroy();
    }

public:
    /**
     * @function    创建双向链表。
     * @paras   none 。
     * @ret none 。
     * @time    2019-08-08
     */
    void Create()
    {
        head_ = nullptr;
        tail_ = nullptr;
        size_ = 0;
        maxsize_ = -1;
    }

    /**
     * @function    创建双向链表。
     * @paras   none 。
     * @ret none 。
     * @time    2019-08-09
     */
    void Create(size_t maxsize)
    {
        head_ = nullptr;
        tail_ = nullptr;
        size_ = 0;
        maxsize_ = maxsize;
    }

    /**
     * @function    销毁双向链表。
     * @paras   none 。
     * @ret none 。
     * @time    2019-08-08
     */
    void Destroy()
    {
        DoubleLinkListNode<T> *ptmp = nullptr;
        while (size_)
        {
            ptmp = head_;
            head_ = head_->prev;
            head_->next = nullptr;

            delete ptmp;
            ptmp = nullptr;
            size_--;
        }
        tail_ = nullptr;
    }

    /**
     * @function    向链表的头部插入新的数据。
     * @paras   pdata   待插入的数据。
     * @ret 0   操作成功。
     *      -1  pdata == nullptr
     *      -2  链表已满。
     * @time    2019-08-08
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
        
        DoubleLinkListNode<T> *pnode = new DoubleLinkListNode<T>;
        memset(pnode, 0, sizeof(DoubleLinkListNode<T>) * 1);

        pnode->data = pdata;
        if (isEmpty())
        {
            head_ = pnode;
            tail_ = pnode;
        }
        else
        {
            pnode->prev = head_;
            head_->next = pnode;
            head_ = pnode;
        }
        size_++;
        return 0;
    }

    /**
     * @function    向链表的尾部插入新的数据。
     * @paras   pdata   待插入的数据。
     * @ret 0   操作成功。
     *      -1  pdata == nullptr
     *      -2  链表已满。
     * @time    2019-08-09
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

        DoubleLinkListNode<T> *pnode = new DoubleLinkListNode<T>;
        memset(pnode, 0, sizeof(DoubleLinkListNode<T>) * 1);

        pnode->data = pdata;
        if (isEmpty())
        {
            head_ = pnode;
            tail_ = pnode;
        }
        else
        {
            pnode->next = tail_;
            tail_->prev = pnode;
            tail_ = pnode;
        }
        size_++;
    }

    /**
     * @function    删除链表中指定的节点。
     * @paras   pnode   待删除的节点。
     * @ret 0   操作成功。
     *      -1  pnode == nullptr
     * @time    2019-08-08
     */
    int RemoveNode(DoubleLinkListNode<T> *&pnode)
    {
        if (pnode == nullptr)
        {
            return -1;
        }

        if (pnode == head_)
        {
            head_ = head_->prev;
            if (head_ != nullptr)
            {
                head_->next = nullptr;
            }

            delete pnode;
            pnode = nullptr;
        }
        else if (pnode == tail_)
        {
            tail_ = tail_->next;
            if (tail_ != nullptr)
            {
                tail_->prev = nullptr;
            }

            delete pnode;
            pnode = nullptr;
        }
        else
        {
            pnode->prev->next = pnode->next;
            pnode->next->prev = pnode->prev;

            delete pnode;
            pnode = nullptr;
        }

        size_--;
        return 0;
    }

    /**
     * @function    搜索链表中指定数据的节点，并返回第一个。（从头部开始搜索）
     * @paras   data   待搜索的数据。
     * @ret 非nullptr   操作成功。
     *      nullptr 未找到指定数据的节点。
     * @time    2019-08-08
     */
    DoubleLinkListNode<T> *SearchNode(T *data)
    {
        DoubleLinkListNode<T> *ptmp = head_;
        while (ptmp)
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
     * @time    2019-08-09
     */
    DoubleLinkListNode<T> *Head()
    {
        return head_;
    }

    /**
     * @function    返回尾部节点。
     * @paras   none 。
     * @time    2019-08-09
     */
    DoubleLinkListNode<T> *Tail()
    {
        return tail_;
    }

    /**
     * @function    返回链表中节点数量。
     * @paras   none 。
     * @ret 链表中的节点数量。
     * @time    2019-08-08
     */
    size_t Size()
    {
        return size_;
    }

    /**
     * @function    返回链表中节点数量上限。
     * @paras   none 。
     * @ret 链表中的节点数量。
     * @time    2019-08-09
     */
    size_t MaxSize()
    {
        return maxsize_;
    }

    /**
     * @function    返回该链表是否为空的标志。
     * @paras   none 。
     * @ret true，为空，反之为false。
     * @time    2019-08-08
     */
    bool isEmpty()
    {
        return !size_;
    }

private:
    /**
     * 指向头节点。
     */
    DoubleLinkListNode<T> *head_;

    /**
     * 指向尾节点。
     */
    DoubleLinkListNode<T> *tail_;

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