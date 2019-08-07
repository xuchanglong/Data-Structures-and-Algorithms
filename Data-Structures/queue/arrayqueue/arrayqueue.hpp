/**
 * @function    顺序循环队列的类。
 * @author      xuchanglong
 * @time        2019-08-02
 * ****************************************************
 * @modify  删除 elesum 成员变量。更改判断队列是满还是空的方式。
 * @author  xuchanglong
 * @time        2019-08-04
 */
#ifndef DATA_STRUCTURES_QUEUE_ARRAYQUEUE_ARRAYQUEUE_HPP_
#define DATA_STRUCTURES_QUEUE_ARRAYQUEUE_ARRAYQUEUE_HPP_

#include <cstddef>
#include <new>

template <typename T>
class ArrayQueue
{
public:
    ArrayQueue()
    {
        pbuffer_ = nullptr;
        queuesize_ = 0;
        tail_ = 0;
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
     * @paras       kSum 队列大小。
     * @return      报错代码。
     *              0   操作成功。
     *              -1  输入的队列大小 == 0。
     *              -2  申请内存失败。
     * @author      xuchanglong
     * @time        2019-08-02
     */
    int Create(const size_t &kSum = 10)
    {
        if (kSum == 0)
        {
            return -1;
        }
        try
        {
            pbuffer_ = new T *[kSum];
        }
        catch(const std::exception& e)
        {
            //std::cerr << e.what() << '\n';
            return -2;
        }
        
        queuesize_ = kSum;
        head_ = 0;
        tail_ = 0;

        return 0;
    }
    /**
     * @function    销毁队列。
     * @paras       none。
     * @return      报错代码。
     *              0   操作成功。
     *              -1  队列为空。
     * @author      xuchanglong
     * @time        2019-08-02
     */
    int Destroy()
    {
        if (pbuffer_)
        {
            delete pbuffer_;
            pbuffer_ = nullptr;
        }
        else
        {
            return -1;
        }
        queuesize_ = 0;
        head_ = 0;
        tail_ = 0;
        return 0;
    }
    /**
     * @function    向队列中压数。函数是标准称呼，全称是 Enter Queue 。
     * @paras       pdata   待压入的指针。
     * @return      报错代码。
     *              0   操作成功。
     *              -1  队列已满。
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
        pbuffer_[tail_] = pdata;
        tail_ = (tail_ + 1) % queuesize_;

        return 0;
    }
    /**
     * @function    从队列中取数。函数是标准称呼，全称是 Delete Queue 。
     * @paras       data   待取走的数据。
     * @return      报错代码。
     *              0   操作成功。
     *              -1  队列为空。
     * @author      xuchanglong
     * @time        2019-08-02
     */
    int Dequeue(T &data)
    {
        if (isEmpty())
        {
            return -1;
        }
        data = *pbuffer_[head_];
        head_ = (head_ + 1) % queuesize_;

        return 0;
    }

private:
    /**
     * @function    判断队列是否为空。
     * @paras       none 。
     * @return      true    为空 。
     *              false   不为空 。
     * @author      xuchanglong
     * @time        2019-08-02
     * ***********************************************
     * @modify  更改判断队列是否为空的方式。
     *                      之前是由计数元素数量的变量来判断，当该变量为空时，即该队列为空。
     *                      这种方式没有任何问题，但是当程序员申请一个超级大的队列时，该变量有可能越界。
     *                      如果，定义该变量以很大的数据类型时，当申请队列元素较少时又是一种浪费。
     *                      所以更改 head_ == tail_ 的方式，可以解决所有问题。
     * @author  xuchanglong
     * @time        2019-08-04
     */
    bool isEmpty() { return head_ == tail_; }
    /**
     * @function    判断队列是否已经压满。
     * @paras       none 。
     * @return      true    已满 。
     *              false   不满 。
     * @author      xuchanglong
     * @time        2019-08-02
     * ***********************************************
     * @modify  更改判断队列是否为满的方式。
     *                      之前由 elesum 变量来判断，现在删除了该成员变量。
     *                       (tail_ + 1) % queuesize_ == head_ 的方式，相当于浪费了一个队列元素空间。
     *                      为什么要浪费一个元素空间呢，主要是 tail_ == head_ 这种方式无法分辨该队列
     *                      为空还是为满。当然了，也可以浪费2个、3个、……,1个当然最好啦。
     */
    bool isFull() { return (tail_ + 1) % queuesize_ == head_; }

    /**
     * @function    返回当前队列的大小。
     * @paras           none
     * @return          当前队列的大小。
     * @author          xuchanglong
     * @time            2019-08-03
     */
    size_t Size() { return queuesize_; }

private:
    /**
     * 队列元素存放空间。
     */
    T **pbuffer_;
    /**
     * 队列空间大小。
     */
    size_t queuesize_;
    /**
     * 指向队列头部元素的位置。
     */
    size_t head_;
    /**
     * 指向队列尾部的下一个待压入的位置。
     */
    size_t tail_;
};

#endif