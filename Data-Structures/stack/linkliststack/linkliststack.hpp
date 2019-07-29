/**
 * @function    顺序栈的类。
 * @time        2019-07-27
 * @author      xuchanglong
 */

#ifndef __ARRAYSTACK_HPP
#define __ARRAYSTACK_HPP

#include "../stackbase.h"
#include <string.h>

template <typename T>
class LinkListStack : public StackBase<T>
{
public:
    //  默认构造函数。
    LinkListStack()
    {
        pbuffer = nullptr;
        pos = -1;
    };
    //  拷贝构造函数。
    LinkListStack(const LinkListStack &stack) = delete;
    //  等号运算符重载。
    LinkListStack &operator=(const LinkListStack &stack) = delete;

    virtual ~LinkListStack()
    {
        destroy();
    }

public:
    /**
     * @function    创建顺序栈。
     * @paras       顺序栈的大小。
     * @return      0   创建成功。
     *              -1  参数错误。
     *              -2  栈已经创建。
     *              -3  申请内存失败，可能参数过大。
     */
    int create(const size_t &sum = 10)
    {
        if (sum <= 0)
        {
            return -1;
        }
        if (pbuffer)
        {
            return -2;
        }
        
        StackBase<T>::size = sum;
        pbuffer = new T[sum]();
        if (pbuffer == nullptr)
        {
            return -3;
        }

        pos = -1;
        return 0;
    }

    /**
     * @function    销毁栈。
     * @paras       none
     * @return      none
     */
    void destroy()
    {
        if (pbuffer != nullptr)
        {
            delete[] pbuffer;
            pbuffer = nullptr;
        }
        size = 0;
        pos = -1;
    }

    /** 
     * @function    将元素压入栈中。
     * @paras       data    待压入栈中的元素。
     * @return      0       成功
     *              -1      未申请栈空间。
     */
    int push(T data)
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
     *  @function       将元素压入栈。若栈已满，则重新申请2倍原大小的空间，
     *                               将之前的元素 copy 至新栈中，再在新栈中重新压数。
     *  @paras          data    待压入栈中的元素。
     *  @ return        0       成功。
     *                  -1      内存申请失败。
     */
    int push_c(T data)
    {
        if (!isfull())
        {
            return push(data);
        }

        int size_n = StackBase<T>::size * 2;
        T *pbuf = new T[size_n];
        if (pbuf == nullptr)
        {
            return -2;
        }

        memcpy(pbuf, pbuffer, sizeof(T) * StackBase<T>::size);

        delete[] pbuffer;
        pbuffer = pbuf;
        pbuf = nullptr;

        StackBase<T>::size = size_n;
        return push(data);
    }

    /**
     * @function    将元素弹出栈。
     * @paras       none
     * @return      弹出的数据。
     * @notice      如何通过返回值显示栈为空的情况，后续补充。
     */
    int pop(T &data)
    {
        if (isempty())
        {
            return false;
        }
        data = pbuffer[pos];
        pos--;
        return true;
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
    bool isfull() const { return (StackBase<T>::size - 1) == pos; }

    /**
     * @function    返回栈大小。
     * @paras       none
     * @return      堆栈大小。
     */
    size_t length() const { return StackBase<T>::size; }

    /**
     * @function    返回栈顶位置。
     * @paras       none
     * @return      栈顶位置。
     */
    size_t toppos() const { return pos; }

private:
    /**
     * 栈的存储空间。
     */
    T *pbuffer;

    /**
     * 栈顶元素下标。
     */
    size_t pos;
};

#endif