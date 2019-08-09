/**
 * @function    单链表实现类。
 * @author      xuchanglong
 * @time        2018-08-09；
 */
#ifndef DATA_STRUCTURES_LINKLIST_SINGLELINKLIST_SINGLELINKLIST_HPP_
#define DATA_STRUCTURES_LINKLIST_SINGLELINKLIST_SINGLELINKLIST_HPP_

#include "singlelinklistnode.hpp"
#include <string.h>

template <typename T>
class SingleLinkList
{
public:
    SingleLinkList()
    {
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
     * @paras       none 。
     * @return      none 。
     * @author      xuchanglong
     * @time        2019-08-09
     */
    void Create()
    {
        head_ = nullptr;
        tail_ = nullptr;
        size_ = 0;
    }

    /**
     * @function    销毁单向链表。
     * @paras       none 。
     * @return      none 。
     * @author      xuchanglong
     * @time        2019-08-09
     */
    void Destroy()
    {
        SingleLinkListNode<T> *pnode = nullptr;
        while (size_)
        {
            pnode = tail_;
            tail_ = tail_->next;

            delete pnode;
            pnode = nullptr;

            size_--;
        }
        head_ = nullptr;
    }

    /**
     * @function    在头部位置插入节点。
     * @paras       pdata   待插入的数据。
     * @return      0   操作成功。
     *              -1  pdata == nullptr 。
     * @author      xuchanglong
     * @time        2019-08-09
     */
    int InsertHead(T *pdata)
    {
        if (pdata == nullptr)
        {
            return -1;
        }
        SingleLinkListNode<T> *pnode = new SingleLinkListNode<T>;
        memset(pnode, 0, sizeof(SingleLinkListNode<T>) * 1);
        pnode->data = pdata;

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
     * @paras       pdata   待插入的数据。
     * @return      0   操作成功。
     *              -1  pdata == nullptr 。
     * @author      xuchanglong
     * @time        2019-08-09
     */
    int InsertTail(T *pdata)
    {
        if (pdata == nullptr)
        {
            return -1;
        }
        SingleLinkListNode<T> *pnode = new SingleLinkListNode<T>;
        memset(pnode, 0, sizeof(SingleLinkListNode<T>) * 1);
        pnode->data = pdata;

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
     * @paras       pdata   待插入的数据。
     * @return      0   操作成功。
     *              -1  pdata == nullptr 。
     *              -2  链表为空 。
     *              -3  该节点在链表中不存在。
     * @author      xuchanglong
     * @time        2019-08-09
     */
    int RemoveNode(SingleLinkListNode<T> *&pnode)
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
     * @paras       pdata   待插入的数据。
     * @return      0   操作成功。
     *              -1  pdata == nullptr 。
     *              -2  未找到指定的元素。
     * @author      xuchanglong
     * @time        2019-08-09
     */
    SingleLinkListNode<T> *SearchNode(T *pdata)
    {
        if (pdata == nullptr)
        {
            return -1;
        }
        SingleLinkListNode<T> *pnode = nullptr;
        pnode = tail_;
        while (pnode->data != pdata)
        {
            pnode = tail_->next;
            if (pnode == nullptr)
            {
                return -2;
            }
        }
        return pnode;
    }

    /**
     * @function    返回头部节点。
     * @paras       node 。
     * @return      头部节点。
     * @author      xuchanglong
     * @time        2019-08-09
     */
    SingleLinkListNode<T> *Head()
    {
        return head_;
    }
    /**
     * @function    返回尾部节点。
     * @paras       node 。
     * @return      尾部节点。
     * @author      xuchanglong
     * @time        2019-08-09
     */
    SingleLinkListNode<T> *Tail()
    {
        return tail_;
    }

    /**
     * @function    判断链表是否为空。
     * @paras       node 。
     * @return      true    空
     *              false   非空
     * @author      xuchanglong
     * @time        2019-08-09
     */
    bool isEmpty()
    {
        return !size_;
    }

    /**
     * @function    返回链表中节点的数量。
     * @paras       node 。
     * @return      链表中节点的数量。
     * @author      xuchanglong
     * @time        2019-08-09
     */
    size_t Size()
    {
        return size_;
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
};

#endif