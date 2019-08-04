/**
 * @function    链式循环队列的类。
 * @author      xuchanglong
 * @time        2019-08-04
 */
#ifndef DATA_STRUCTURES_QUEUE_LINKLISTQUEUE_LINKLISTQUEUE_HPP_
#define DATA_STRUCTURES_QUEUE_LINKLISTQUEUE_LINKLISTQUEUE_HPP_

#include <cstddef>

template <typename T>
class LinkListQueue
{
private:
    struct LinkListQueueNode
    {
        T *pdata;
        LinkListQueueNode *next;
    };

public:
    LinkListQueue()
    {
        phead = nullptr;
        ptail = nullptr;
        elementsum = 0;
    }

    LinkListQueue(const LinkListQueue &kQueue) = delete;

    LinkListQueue &operator=(const LinkListQueue &kQueue) = delete;

    ~LinkListQueue()
    {
        ;
    }

public:
    /**
     * @function    创建队列。
     * @paras       none 。
     * @return      报错代码。
     *              0   操作成功。
     * @author      xuchanglong
     * @time        2019-08-04
     */
    int Create()
    {
        phead = nullptr;
        ptail = nullptr;
        elementsum = 0;

        return 0;
    }

    /**
     * @function    销毁队列。
     * @paras       none 。
     * @return      报错代码。
     *              0   操作成功。
     *              -1  队列中无元素。
     * @author      xuchanglong
     * @time        2019-08-04
     */
    int Destroy()
    {
        if (!phead || !ptail)
        {
            return -1;
        }

        LinkListQueueNode *ptmp;
        while (phead)
        {
            ptmp = phead;
            phead = phead->next;

            delete ptmp;
            ptmp = nullptr;
        }
        phead = nullptr;
        ptail = nullptr;

        return 0;
    }

    /**
     * @function    元素指针入队。
     * @paras       pdata 元素指针。
     * @return      报错代码。
     *              0   操作成功。
     *              -1  形参为空。
     *              -2  申请存放该指针的内存时失败。
     * @author      xuchanglong
     * @time        2019-08-02
     */
    int EnQueue(T *pdata)
    {
        if (!pdata)
        {
            return -1;
        }
        LinkListQueueNode *ptmp = new LinkListQueueNode;
        if (!ptmp)
        {
            return -2;
        }
        ptmp->pdata = pdata;
        if (phead==nullptr)
        {
            phead = ptmp;
        }
        else
        {
            ptail->next = ptmp;
        }
        ptail = ptmp;

        elementsum++;
        return 0;
    }

    /**
     * @function    元素出队。
     * @paras       data 元素。
     * @return      报错代码。
     *              0   操作成功。
     *              -1  队列为空。
     * @author      xuchanglong
     * @time        2019-08-02
     */
    int DeQueue(T &data)
    {
        if (isEmpty())
        {
            return -1;
        }
        data = *phead->pdata;
        LinkListQueueNode *ptmp = phead;
        phead = phead->next;
        delete ptmp;
        ptmp = nullptr;

        if (phead==nullptr)
        {
            ptail = nullptr;
        }

        elementsum--;
        return 0;
    }

private:
    /**
     * @function    返回队列中元素个数。
     * @paras       none 。
     * @return      队列中元素个数。
     * @author      xuchanglong
     * @time        2019-08-04
     */
    size_t Size() { return elementsum; }

    /**
     * @function    返回队列是否为空。
     * @paras       none 。
     * @return      true    队列为空
     *                          false   队列非空。
     * @author      xuchanglong
     * @time        2019-08-04
     */
    bool isEmpty() { return !elementsum; }

private:
    /**
     * phead，用于指向队头。
     */
    LinkListQueueNode *phead;

    /**
     * ptail，用于指向队尾。
     */
    LinkListQueueNode *ptail;

    /**
     * 计数链式队列中的元素个数。
     */
    size_t elementsum;
};

#endif