/**
 * @function    栈的基类。
 * @time        2019-07-29
 * @author      xuchanglong
 */

#ifndef __STACKBASE_HPP
#define __STACKBASE_HPP

#include <string.h>

template <typename T>
class StackBase
{
public:
    //  默认构造函数。
    StackBase() { size = 0; }
    //  拷贝构造函数。
    StackBase(const StackBase &stack) = delete;
    //  等号运算符重载。
    StackBase &operator=(const StackBase &stack) = delete;

    virtual ~StackBase() {}

public:
    /**
     * @function    创建栈。
     * @paras       sum 顺序栈的大小。
     * @return      0   创建成功。
     *              -1  参数错误。
     *              -2  栈已经创建。
     *              -3  申请内存失败，可能参数过大。
     */
    virtual int create(const size_t &sum = 10) = 0;

    /**
     * @function    销毁栈。
     * @paras       none
     * @return      none
     */
    virtual void destroy() = 0;

    /** 
     * @function    将元素压入栈中。
     * @paras       data    待压入栈中的元素。
     * @return      0       成功
     *              -1      未申请栈空间。
     */
    virtual int push(T data) = 0;

    /**
     *  @function       将元素压入栈。若栈已满，则重新申请2倍原大小的空间，
     *                               将之前的元素 copy 至新栈中，再在新栈中重新压数。
     *  @paras          data    待压入栈中的元素。
     *  @ return        0       成功。
     *                  -1      内存申请失败。
     */
    virtual int push_c(T data) = 0;

    /**
     * @function    将元素弹出栈。
     * @paras       none
     * @return      弹出的数据。
     * @notice      如何通过返回值显示栈为空的情况，后续补充。
     */
    virtual int pop(T &data) = 0;

public:
    /**
     * @function    判断栈是否是空的。
     * @paras       none
     * @return      true    栈是空的。
     *              false   栈是非空。
     */
    virtual bool isempty() const = 0;

    /**
     * @function    判断栈是否是满的。
     * @paras       none
     * @return      true    栈是满的。
     *              false   栈是非满。
     */
    virtual bool isfull() const = 0;

    /**
     * @function    返回栈大小。
     * @paras       none
     * @return      堆栈大小。
     */
    virtual size_t length() const = 0;

protected:
    /**
     * 栈空间大小。
     */
    size_t size;
};

#endif