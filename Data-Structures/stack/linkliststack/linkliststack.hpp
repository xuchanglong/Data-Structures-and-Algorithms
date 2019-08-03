/**
 * @function    链式栈的类。
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
    struct LinkListStackNode
    {
        T *data;
        LinkListStackNode *next;
    };

public:
    LinkListStack()
    {
        phead = nullptr;
        elesum = 0;
    };

    LinkListStack(const LinkListStack &kStack) = delete;

    LinkListStack &operator=(const LinkListStack &kStack) = delete;

    virtual ~LinkListStack()
    {
        Destroy();
    }

public:
    /**
     * @function    创建链式栈。
     * @paras       none
     * @return      0   创建成功。
     *              -1  栈已经创建。
     *              -2  申请内存失败，可能参数过大。
     */
    int Create()
    {
        if (phead != nullptr)
        {
            return -1;
        }
        phead = new LinkListStackNode;
        if (phead == nullptr)
        {
            return -2;
        }
        phead->data = nullptr;
        phead->next = nullptr;
        elesum = 0;
        return 0;
    }

    /**
     * @function    销毁栈。
     * @paras       none
     * @return      none
     */
    int Destroy()
    {
        if (phead == nullptr)
        {
            return -1;
        }

        LinkListStackNode *ptmp;
        while (phead->next)
        {
            ptmp = phead->next;
            phead->next = ptmp->next;
            delete ptmp;
            ptmp = nullptr;
        }
        delete phead;
        phead = nullptr;
        elesum = 0;
        return 0;
    }

    /** 
     * @function    将元素地址压入栈中。
     * @paras       data    待压入栈中的元素的地址。
     * @return      0       操作成功
     *              -1      地址为空
     *              -2      申请节点失败。
     */
    int Push(T *data)
    {
        if (data == nullptr)
        {
            return -1;
        }

        LinkListStackNode *ptmp = new LinkListStackNode;
        if (ptmp == nullptr)
        {
            return -2;
        }

        ptmp->data = data;
        ptmp->next = phead->next;
        phead->next = ptmp;

        elesum++;

        return 0;
    }

    /**
     * @function    将元素弹出栈。
     * @paras       弹出来的元素。
     * @return      0   操作成功。
     *              -1  栈中元素数量为空。
     */
    int Pop(T &data)
    {
        if (isEmpty())
        {
            return -1;
        }
        data = *phead->next->data;

        LinkListStackNode *ptmp = phead->next;
        phead->next = ptmp->next;
        delete ptmp;
        ptmp = nullptr;
        elesum--;
        return 0;
    }

public:
    /**
     * @function    判断栈是否是空的。
     * @paras       none
     * @return      true    栈是空的。
     *              false   栈是非空。
     */
    bool isEmpty() const { return !elesum; }

    /**
     * @function    返回栈大小。
     * @paras       none
     * @return      堆栈大小。
     */
    size_t Length() const { return elesum; }

private:
    /**
     * 栈顶元素指针。
     */
    LinkListStackNode *phead;

    /**
     * 栈中元素数量。
     */
    size_t elesum;
};

#endif