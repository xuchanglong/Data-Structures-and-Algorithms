#include "sorts/sorts.hpp"
#include <iostream>

template <typename T>
void Show(T *pdata, size_t count);

/**
 * 1    插入排序。
 * 2    选择排序。
*/
#define SORTALGORITHMSTYPE 2

int main()
{
    int testnum[10] = {1, 2, 3, 4, 5, 2, 6, 4, 8, 4};

    std::cout << "原始数据。" << std::endl;
    Show(testnum, 10);

    switch (SORTALGORITHMSTYPE)
    {
    case 1:
        std::cout << "插入排序，";
        InsertSort(testnum, 10);
        break;
    case 2:
        std::cout << "选择排序，";
        SelectSort(testnum, 10);
        break;
    default:
        break;
    }

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