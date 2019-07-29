/**
 * @function    顺序栈的类。
 * @time        2019-07-27
 * @author      xuchanglong
 */

#ifndef __ARRAYSTACK_HPP
#define __ARRAYSTACK_HPP

#include <string.h>

template <typename T>
class ArrayStack
{
public:
    //  默认构造函数。
    ArrayStack()
    {
        pbuffer = nullptr;
        pos = -1;
        size = 0;
    };
    //  拷贝构造函数。
    ArrayStack(const ArrayStack &stack) = delete;
    //  等号运算符重载。
    ArrayStack &operator=(const ArrayStack &stack) = delete;

    virtual ~ArrayStack()
    {
        destory();
    }

public:
    /**
     * @function    创建顺序栈。
     * @paras       顺序栈的大小。
     * @return      0   创建成功。
     *              -1  参数错误。
     *              -2  申请内存失败，可能参数过大。
     */
    int create(const size_t &sum = 10)
    {
        if (sum <= 0)
        {
            return -1;
        }
        size = sum;
        pbuffer = new T *[sum]();
        if (pbuffer == nullptr)
        {
            return -2;
        }

        pos = -1;
        return 0;
    }

    /**
     * @function    销毁栈。
     * @paras       顺none
     * @return      0   操作成功。
     *              -1  栈不存在。
     */
    int destory()
    {
        if (pbuffer==nullptr)
        {
            return -1;
        }
        delete pbuffer;
        pbuffer = nullptr;
        pos = -1;
        size = 0;

        return 0;
    }

    /** 
     * @function    将元素的地址压入栈中。
     * @paras       data    待压入栈中的元素的地址。
     * @return      0       成功
     *              -1      栈空间已满。
     */
    int push(T *data)
    {
        if (isfull())
        {
            return -1;
        }

        pos++;
        pbuffer[pos] = data;

        return 0;
    }

    /**
     *  @function       将元素的地址压入栈。若栈已满，则重新申请2倍原大小的空间，
     *                  将之前的栈中内容 copy 至新栈中，再在新栈中重新压数。
     *  @paras          data    待压入栈中的元素的地址。
     *  @ return        0       成功。
     *                  -1      内存申请失败。
     */
    int push_c(T *data)
    {
        if (!isfull())
        {
            return push(data);
        }

        int size_n = size * 2;
        T **pbuf = new T *[size_n];
        if (pbuf == nullptr)
        {
            return -2;
        }

        memcpy(pbuf, pbuffer, sizeof(T *) * size);

        delete[] pbuffer;
        pbuffer = pbuf;
        pbuf = nullptr;

        size = size_n;
        return push(data);
    }

    /**
     * @function    将元素弹出栈。
     * @paras       弹出来的元素。
     * @return      0   操作成功。
     *              -1  栈中元素数量为空。
     * @notice      如何通过返回值显示栈为空的情况，后续补充。
     */
    int pop(T &data)
    {
        if (isempty())
        {
            return -1;
        }
        data = *pbuffer[pos];
        pos--;
        return 0;
    }

public:
    /**
     * @function    判断栈是否是空的。
     * @paras       none
     * @return      true    栈是空的。
     *              false   栈是非空。
     */
    bool isempty() const { return pos == -1; }

    /**
     * @function    判断栈是否是满的。
     * @paras       none
     * @return      true    栈是满的。
     *              false   栈是非满。
     */
    bool isfull() const { return (size - 1) == static_cast<size_t>(pos); }

    /**
     * @function    返回栈大小。
     * @paras       none
     * @return      堆栈大小。
     */
    size_t length() const { return size; }

    /**
     * @function    返回栈顶位置。
     * @paras       none
     * @return      栈顶位置。
     */
    size_t toppos() const { return pos; }

private:
    /**
     * 栈空间大小。
     */
    size_t size;
    /**
     * 栈的存储空间。
     */
    T **pbuffer;

    /**
     * 栈顶元素下标。
     */
    int pos;
};

#endif