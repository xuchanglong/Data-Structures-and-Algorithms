/**
 * @function    顺序栈的类。
 * @time        2019-07-27
 * @author      xuchanglong
 */

#ifndef DATA_STRUCTURES_STACK_ARRAYSTACK_ARRAYSTACK_HPP_
#define DATA_STRUCTURES_STACK_ARRAYSTACK_ARRAYSTACK_HPP_

#include <string.h>

template <typename T>
class ArrayStack
{
public:
    ArrayStack()
    {
        pbuffer_ = nullptr;
        pos_ = -1;
        size_ = 0;
    };

    ArrayStack(const ArrayStack &kStack) = delete;

    ArrayStack &operator=(const ArrayStack &kSack) = delete;

    virtual ~ArrayStack()
    {
        Destory();
    }

public:
    /**
     * @function    创建顺序栈。
     * @paras       顺序栈的大小。
     * @return      0   创建成功。
     *              -1  参数错误。
     *              -2  申请内存失败，可能参数过大。
     */
    int Create(const size_t &kSum = 10)
    {
        if (kSum <= 0)
        {
            return -1;
        }
        size_ = kSum;
        pbuffer_ = new T *[kSum];
        if (pbuffer_ == nullptr)
        {
            return -2;
        }

        pos_ = -1;
        return 0;
    }

    /**
     * @function    销毁栈。
     * @paras       顺none
     * @return      0   操作成功。
     *              -1  栈不存在。
     */
    int Destory()
    {
        if (pbuffer_==nullptr)
        {
            return -1;
        }
        delete pbuffer_;
        pbuffer_ = nullptr;
        pos_ = -1;
        size_ = 0;

        return 0;
    }

    /** 
     * @function    将元素的地址压入栈中。
     * @paras       data    待压入栈中的元素的地址。
     * @return      0       成功
     *              -1      栈空间已满。
     */
    int Push(T *data)
    {
        if (isFull())
        {
            return -1;
        }

        pos_++;
        pbuffer_[pos_] = data;

        return 0;
    }

    /**
     *  @function       将元素的地址压入栈。若栈已满，则重新申请2倍原大小的空间，
     *                  将之前的栈中内容 copy 至新栈中，再在新栈中重新压数。
     *  @paras          data    待压入栈中的元素的地址。
     *  @ return        0       成功。
     *                  -1      内存申请失败。
     */
    int Push_c(T *data)
    {
        if (!isFull())
        {
            return Push(data);
        }

        int size_n = size_ * 2;
        T **pbuf = new T *[size_n];
        if (pbuf == nullptr)
        {
            return -2;
        }

        memcpy(pbuf, pbuffer_, sizeof(T *) * size_);

        delete[] pbuffer_;
        pbuffer_ = pbuf;
        pbuf = nullptr;

        size_ = size_n;
        return Push(data);
    }

    /**
     * @function    将元素弹出栈。
     * @paras       弹出来的元素。
     * @return      0   操作成功。
     *              -1  栈中元素数量为空。
     * @notice      如何通过返回值显示栈为空的情况，后续补充。
     */
    int Pop(T &data)
    {
        if (isEmpty())
        {
            return -1;
        }
        data = *pbuffer_[pos_];
        pos_--;
        return 0;
    }

public:
    /**
     * @function    判断栈是否是空的。
     * @paras       none
     * @return      true    栈是空的。
     *              false   栈是非空。
     */
    bool isEmpty() const { return pos_ == -1; }

    /**
     * @function    判断栈是否是满的。
     * @paras       none
     * @return      true    栈是满的。
     *              false   栈是非满。
     */
    bool isFull() const { return (size_ - 1) == static_cast<size_t>(pos_); }

    /**
     * @function    返回栈大小。
     * @paras       none
     * @return      堆栈大小。
     */
    size_t Size() const { return size_; }

    /**
     * @function    返回栈顶位置。
     * @paras       none
     * @return      栈顶位置。
     */
    size_t TopPos() const { return pos_; }

private:
    /**
     * 栈空间大小。
     */
    size_t size_;
    /**
     * 栈的存储空间。
     */
    T **pbuffer_;

    /**
     * 栈顶元素下标。
     */
    int pos_;
};

#endif