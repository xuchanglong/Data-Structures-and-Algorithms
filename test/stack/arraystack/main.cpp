#include "../../../Data-Structures/stack/arraystack/arraystack.hpp"
#include <iostream>
 
template <typename T>
void showstack(arraystack<T> &stack);
 
int main()
{
    arraystack<int> stack(5);
    int datasum[10] = {1, 43, 4, 3, 2, 9, 35, 654, 65, 732};
    //  向堆栈进行压入数据。
    std::cout << "-------------------  push  -------------------" << std::endl;
    //  若数据溢出，则返回报错。
    for (size_t i = 0; i < 10; i++)
    {
        if (stack.push(datasum[i]) != 0)
        {
            std::cout << datasum[i] << " can't push stack." << std::endl;
        }
    }
    showstack(stack);
 
    std::cout << "-------------------  push_c  -------------------" << std::endl;
    //  若数据溢出，则重新申请内存，继续压数。
    for (size_t i = 0; i < 10; i++)
    {
        if (stack.push_c(datasum[i]) != 0)
        {
            std::cout << datasum[i] << " can't push stack." << std::endl;
        }
    }
    showstack(stack);
 
    return 0;
}
 
template <typename T>
void showstack(arraystack<T> &stack)
{
    T data;
    for (size_t i = 0; i < stack.length(); i++)
    {
        if (stack.pop(data))
        {
            std::cout << data << "、";
        }
    }
    std::cout << std::endl;
}