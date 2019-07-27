#ifndef __ARRAYSTACK_HPP
#define __ARRAYSTACK_HPP
 
#include <string.h> 
 
template <typename T>
class arraystack
{
public:
    //  默认构造函数。
    arraystack() = delete;
    //  拷贝构造函数。
    arraystack(const arraystack &stack) = delete;
    //  等号运算符重载。
    arraystack &operator=(const arraystack &stack) = delete;
 
    explicit arraystack(const size_t &sum)
    {
        size = sum;
        pbuffer = new T[sum]();
        pos = -1;
    }
    virtual ~arraystack()
    {
        if (pbuffer != nullptr)
        {
            delete[] pbuffer;
            pbuffer = nullptr;
        }
    }
 
public:
    /** 
     * @function    将元素压入栈中。
     * @paras           data    待压入栈中的元素。
     * @return          0    成功
     *                            -1  未申请栈空间。
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
     *  @paras              data        待压入栈中的元素。
     *  @ return            0       成功。
     *                                -1      内存申请失败。
     */
    int push_c(T data)
    {
        if (!isfull())
        {
            return push(data);
        }
 
        T *pbuf = new T[size * 2]();
        memcpy(pbuf, pbuffer, sizeof(T) * size);
 
        delete[] pbuffer;
        pbuffer = pbuf;
        pbuf = nullptr;
 
        size = size * 2;
        push(data);
 
        return 0;
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
    bool isempty() const { return size == -1; }
    /**
     * @function    判断栈是否是满的。
     * @paras       none
     * @return      true    栈是满的。
     *              false   栈是非满。
     */
    bool isfull() const { return (size - 1) == pos; }
 
    /**
     * @function    返回堆栈大小。
     * @paras          none
     * @return         堆栈大小。
     */
    int length() const { return size; }
 
private:
    /**
     * 栈空间大小。
     */
    size_t size;
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