/**
 * @function    链式循环队列的类。
 * @time    2019-08-04
 */
#ifndef DATA_STRUCTURES_QUEUE_LINKLISTQUEUE_LINKLISTQUEUE_HPP_
#define DATA_STRUCTURES_QUEUE_LINKLISTQUEUE_LINKLISTQUEUE_HPP_

#include <cstddef>
#include <new>

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
        phead_ = nullptr;
        ptail_ = nullptr;
        elementsum_ = 0;
    }

    LinkListQueue(const LinkListQueue &kQueue) = delete;

    LinkListQueue &operator=(const LinkListQueue &kQueue) = delete;

    ~LinkListQueue()
    {
        Destroy();
    }

public:
    /**
     * @function    创建队列。
     * @paras   none 。
     * @ret 报错代码。
     *      0   操作成功。
     * @time    2019-08-04
     */
    int Create()
    {
        phead_ = nullptr;
        ptail_ = nullptr;
        elementsum_ = 0;

        return 0;
    }

    /**
     * @function    销毁队列。
     * @paras   none 。
     * @ret 报错代码。
     *      0   操作成功。
     * @time    2019-08-04
     */
    int Destroy()
    {
        LinkListQueueNode *ptmp;
        while (phead_)
        {
            ptmp = phead_;
            phead_ = phead_->next;

            delete ptmp;
            ptmp = nullptr;
        }
        phead_ = nullptr;
        ptail_ = nullptr;

        return 0;
    }

    /**
     * @function    元素指针入队。
     * @paras   pdata 元素指针。
     * @ret 报错代码。
     *      0   操作成功。
     *      -1  形参为空。
     *      -2  申请存放该指针的内存时失败。
     * @time    2019-08-02
     */
    int EnQueue(T *pdata)
    {
        if (!pdata)
        {
            return -1;
        }
        LinkListQueueNode *ptmp = nullptr;
        try
        {
            ptmp = new LinkListQueueNode;
        }
        catch(const std::exception& e)
        {
            //std::cerr << e.what() << '\n';
            return -2;
        }
        
        ptmp->pdata = pdata;
        ptmp->next = nullptr;
        if (phead_==nullptr)
        {
            phead_ = ptmp;
        }
        else
        {
            ptail_->next = ptmp;
        }
        ptail_ = ptmp;

        elementsum_++;
        return 0;
    }

    /**
     * @function    元素出队。
     * @paras   data 元素。
     * @ret 报错代码。
     *      0   操作成功。
     *      -1  队列为空。
     * @time    2019-08-02
     */
    int DeQueue(T &data)
    {
        if (isEmpty())
        {
            return -1;
        }
        data = *phead_->pdata;
        LinkListQueueNode *ptmp = phead_;
        phead_ = phead_->next;
        delete ptmp;
        ptmp = nullptr;

        if (phead_==nullptr)
        {
            ptail_ = nullptr;
        }

        elementsum_--;
        return 0;
    }

private:
    /**
     * @function    返回队列中元素个数。
     * @paras   none 。
     * @ret 队列中元素个数。
     * @time    2019-08-04
     */
    size_t Size() { return elementsum_; }

    /**
     * @function    返回队列是否为空。
     * @paras   none 。
     * @ret true    队列为空
     *      false   队列非空。
     * @time    2019-08-04
     */
    bool isEmpty() { return !elementsum_; }

private:
    /**
     * phead，用于指向队头。
     */
    LinkListQueueNode *phead_;

    /**
     * ptail，用于指向队尾。
     */
    LinkListQueueNode *ptail_;

    /**
     * 计数链式队列中的元素个数。
     */
    size_t elementsum_;
};

#endif