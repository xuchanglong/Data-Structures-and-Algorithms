/**
 * @function    顺序队列的类。
 * @time        2019-08-02
 * @author      xuchanglong
 */
#ifndef DATA_STRUCTURES_QUEUE_ARRAYQUEUE_ARRAYQUEUE_HPP_
#define DATA_STRUCTURES_QUEUE_ARRAYQUEUE_ARRAYQUEUE_HPP_

#include <cstddef>

template <typename T>
class ArrayQueue
{
public:
    ArrayQueue()
    {
        pbuffer = nullptr;
        queuesize = 0;
        elesum = 0;
        tail = 0;
    }

    ArrayQueue(const ArrayQueue &kQueue) = delete;

    ArrayQueue &operator=(const ArrayQueue &kQueue) = delete;

    ~ArrayQueue()
    {
        Destroy();
    }

public:
    /**
     * @function    创建队列。
     * @paras       sum 队列大小。
     * @return      报错代码。
     *              0   操作成功。
     *              -1  输入的队列大小 <= 0
     *              -2  申请内存失败
     * @author      xuchanglong
     * @time        2019-08-02
     */
    int Create(const size_t &kSum = 10)
    {
        if (kSum <= 0)
        {
            return -1;
        }
        pbuffer = new T *[kSum];
        if (pbuffer == nullptr)
        {
            return -2;
        }
        queuesize = kSum;
        head = 0;
        tail = 0;
        elesum = 0;

        return 0;
    }
    /**
     * @function    销毁队列。
     * @paras       none。
     * @return      报错代码。
     *              0   操作成功。
     *              -1  队列为空
     * @author      xuchanglong
     * @time        2019-08-02
     */
    int Destroy()
    {
        if (pbuffer)
        {
            delete pbuffer;
            pbuffer = nullptr;
        }
        else
        {
            return -1;
        }
        elesum = 0;
        queuesize = 0;
        head = 0;
        tail = 0;
        return 0;
    }
    /**
     * @function    向队列中压数。函数是标准称呼，全称是 Enter Queue 。
     * @paras       pdata   待压入的指针。
     * @return      报错代码。
     *              0   操作成功。
     *              -1  队列已满
     *              -2  待压入的指针为空。
     * @author      xuchanglong
     * @time        2019-08-02
     */
    int Enqueue(T *pdata)
    {
        if (isFull())
        {
            return -1;
        }
        if (pdata == nullptr)
        {
            return -2;
        }
        pbuffer[tail] = pdata;
        tail = (tail + 1) % queuesize;
        elesum++;

        return 0;
    }
    /**
     * @function    从队列中取数。函数是标准称呼，全称是 Delete Queue 。
     * @paras       data   待取走的数据。
     * @return      报错代码。
     *              0   操作成功。
     *              -1  队列为空
     * @author      xuchanglong
     * @time        2019-08-02
     */
    int Dequeue(T &data)
    {
        if (isEmpty())
        {
            return -1;
        }
        data = *pbuffer[head];
        head = (head + 1) % queuesize;
        elesum--;

        return 0;
    }

    /**
     * @function    返回当前队列的大小。
     * @paras           none
     * @return          当前队列的大小。
     * @author          xuchanglong
     * @time            2019-08-03
     */
    size_t Size()
    {
        return queuesize;
    }

    /**
     * @function    当前元素数量
     * @paras           none
     * @return          当前队列的大小。
     * @author          xuchanglong
     * @time            2019-08-03
     */
    size_t ElementSum()
    {
        return elesum;
    }

private:
    /**
     * @function    判断队列是否为空。
     * @paras       none 。
     * @return      true    为空 。
     *              false   不为空 。
     * @author      xuchanglong
     * @time        2019-08-02
     */
    bool isEmpty()
    {
        return !elesum;
    }
    /**
     * @function    判断队列是否已经压满。
     * @paras       none 。
     * @return      true    已满 。
     *              false   不满 。
     * @author      xuchanglong
     * @time        2019-08-02
     */
    bool isFull()
    {
        return elesum == queuesize;
    }

private:
    /**
     * 队列元素存放空间。
     */
    T **pbuffer;
    /**
     * 队列空间大小。
     */
    size_t queuesize;
    /**
     * 当前元素数量。
     */
    size_t elesum;
    /**
     * 指向队列头部元素的位置。
     */
    size_t head;
    /**
     * 指向队列尾部的下一个待压入的位置。
     */
    size_t tail;
};

#endif