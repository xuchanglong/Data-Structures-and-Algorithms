#include "arraystack.hpp"
#include <iostream>
 
template <typename T>
void showstack(arraystack<T> &stack);

template <typename T>
int showinttype(const int & stacksize , const T * const pdata , const int & datasize);
 
int main()
{
    int pdata[10] = {1, 43, 4, 3, 2, 9, 35, 654, 65, 732};
    showinttype(5 , pdata , 10);

    //std::string str[7] = {"1" , "89" , "42" , "57" , "726" , "71345" , "addw"};
    double dsum[7] = {1.62 , 89.854 , 42.0254 , 57.9513 , 726.8913 , 71345 , 5251.54};
    showinttype(5 , dsum , 7);
    return 0;
}
 
template <typename T>
void showstack(arraystack<T> &stack)
{
    T data;
    while (stack.pop(data))
    {
        std::cout << data << "、";
    }
    std::cout << std::endl;
}

template<typename T>
int showinttype(const int & stacksize , const T * const pdata , const int & datasize)
{
    arraystack<T> stack;
    if (stack.create(stacksize) != 0)
    {
        std::cout << "Create arraystack failed." << std::endl;
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