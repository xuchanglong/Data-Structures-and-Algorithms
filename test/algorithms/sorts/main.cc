#include "sorts/sorts.hpp"
#include <iostream>

template <typename T>
void Show(T *pdata, size_t count);

int main()
{
    int testnum[10] = {1, 2, 3, 4, 5, 2, 6, 4, 8, 4};

    std::cout << "原始数据。" << std::endl;
    Show(testnum, 10);

    InsertSort(testnum, 10);

    std::cout << "排序之后的数据。" << std::endl;
    Show(testnum, 10);

    return 0;
}

template <typename T>
void Show(T *pdata, size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        std::cout << pdata[i] << "、";
    }
    std::cout << std::endl;
}