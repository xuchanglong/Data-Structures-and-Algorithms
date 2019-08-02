/**
 * @function    顺序栈的类。
 * @time        2019-07-27
 * @author      xuchanglong
 */

#ifndef DATA_STRUCTURES_STACK_LINKLISTSTACK_LINKLISTSTACK_HPP_
#define DATA_STRUCTURES_STACK_LINKLISTSTACK_LINKLISTSTACK_HPP_

#include <string.h>

template <typename T>
class LinkListStack
{
private:
    struct _linkliststack_node
    {
        T *data;
        _linkliststack_node *pnext;
    };
public:

    LinkListStack()
    {
        phead = nullptr;
        size = 0;
    };

    LinkListStack(const LinkListStack &stack) = delete;

    LinkListStack &operator=(const LinkListStack &stack) = delete;

    virtual ~LinkListStack()
    {
        destroy();
    }

public:
    /**
     * @function    创建链式栈。
     * @paras       none
     * @return      0   创建成功。
     *              -1  栈已经创建。
     *              -2  申请内存失败，可能参数过大。
     */
    int create()
    {
        if (phead!=nullptr)
        {
            return -1;
        }
        phead = new _linkliststack_node;
        if (phead==nullptr)
        {
            return -2;
        }
        phead->data = nullptr;
        phead->pnext = nullptr;
        size = 0;
        return 0;
    }

    /**
     * @function    销毁栈。
     * @paras       none
     * @return      none
     */
    int destroy()
    {
        if (phead == nullptr)
        {
            return -1;
        }

        _linkliststack_node *ptmp;
        while (phead->pnext)
        {
            ptmp = phead->pnext;
            phead->pnext = ptmp->pnext;
            delete ptmp;
            ptmp = nullptr;
        }
        delete phead;
        phead = nullptr;
        size = 0;
        return 0;
    }

    /** 
     * @function    将元素地址压入栈中。
     * @paras       data    待压入栈中的元素的地址。
     * @return      0       操作成功
     *              -1      地址为空
     *              -2      申请节点失败。
     */
    int push(T *data)
    {
        if (data==nullptr)
        {
            return -1;
        }
        
        _linkliststack_node *ptmp = new _linkliststack_node;
        if (ptmp==nullptr)
        {
            return -2;
        }
        
        ptmp->data = data;
        ptmp->pnext = phead->pnext;
        phead->pnext = ptmp;

        size++;

        return 0;
    }

    /**
     * @function    将元素弹出栈。
     * @paras       弹出来的元素。
     * @return      0   操作成功。
     *              -1  栈中元素数量为空。
     */
    int pop(T &data)
    {
        if (isempty())
        {
            return -1;
        }
        data = *phead->pnext->data;

        _linkliststack_node *ptmp = phead->pnext;
        phead->pnext = ptmp->pnext;
        delete ptmp;
        ptmp = nullptr;
        size--;
        return 0;
    }

public:
    /**
     * @function    判断栈是否是空的。
     * @paras       none
     * @return      true    栈是空的。
     *              false   栈是非空。
     */
    bool isempty() const { return !size; }

    /**
     * @function    返回栈大小。
     * @paras       none
     * @return      堆栈大小。
     */
    size_t length() const { return size; }
private:
    /**
     * 栈顶元素指针。
     */
    _linkliststack_node *phead;

    /**
     * 栈中元素数量。
     */
    size_t size;
};

#endif