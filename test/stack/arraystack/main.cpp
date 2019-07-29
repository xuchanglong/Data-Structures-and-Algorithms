#include "arraystack.hpp"
#include <iostream>

/**
 * @function    依次将元素弹出栈，显示到控制台上。
 * @paras       stack   栈
 * @return      none。
 */
template <typename T>
void showstack(ArrayStack<T> &stack);

/**
 * @function    针对不同存储类型的栈，进行测试。
 * @paras       stacksize   栈大小。
 *              pdata       待测试的数组。
 *              datasize    数组大小。
 * @return      测试结果。
 */
template <typename T>
int teststack(const int &stacksize, const T *const pdata, const int &datasize);

int main()
{
    int pdata[10] = {1, 43, 4, 3, 2, 9, 35, 654, 65, 732};
    teststack(5, pdata, 10);

    std::cout << std::endl;

    double dsum[7] = {1.62, 89.854, 42.0254, 57.9513, 726.8913, 71345, 5251.54};
    teststack(5, dsum, 7);

    return 0;
}

template <typename T>
void showstack(ArrayStack<T> &stack)
{
    T data;
    while (stack.pop(data))
    {
        std::cout << data << "、";
    }
    std::cout << std::endl;
}

template <typename T>
int teststack(const int &stacksize, const T *const pdata, const int &datasize)
{
    ArrayStack<T> stack;
    if (stack.create(stacksize) != 0)
    {
        std::cout << "Create ArrayStack failed." << std::endl;
        return -1;
    }
    //  向堆栈进行压入数据。
    std::cout << "-------------------  push  -------------------" << std::endl;
    //  若数据溢出，则返回报错。
    for (size_t i = 0; i < datasize; i++)
    {
        if (stack.push(pdata[i]) != 0)
        {
            std::cout << pdata[i] << " can't push stack." << std::endl;
        }
    }
    showstack(stack);

    std::cout << "-------------------  push_c  -------------------" << std::endl;
    //  若数据溢出，则重新申请内存，继续压数。
    for (size_t i = 0; i < datasize; i++)
    {
        if (stack.push_c(pdata[i]) != 0)
        {
            std::cout << pdata[i] << " can't push stack." << std::endl;
        }
    }
    showstack(stack);
    return 0;
}