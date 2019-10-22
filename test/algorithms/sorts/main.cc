#include "sorts/sorts.hpp"
#include <iostream>
#include <cstdio>

template <typename T>
void Show(T *pdata, size_t count);

/**
 * 1    插入排序。
 * 2    选择排序。
 * 3    归并排序。
 * 4    快速排序。
 * 5    桶排序。
 */
int main(int argc, const char *argv[])
{
    if (argc == 1)
    {
        std::cout << "请选择排序算法！" << std::endl;
        return 1;
    }

    int algtype = atoi(argv[1]);
    int testnum[10] = {13, 17, 3, 4, 5, 2, 6, 4, 8, 4};

    std::cout << "原始数据。" << std::endl;
    Show(testnum, 10);

    switch (algtype)
    {
    case 1:
        std::cout << "插入排序，";
        InsertSort(testnum, 10);
        break;
    case 2:
        std::cout << "选择排序，";
        SelectSort(testnum, 10);
        break;
    case 3:
        std::cout << "归并排序，";
        MergeSort(testnum, 10);
        break;
    case 4:
        std::cout << "快速排序，";
        QuickeSort(testnum, 10);
        break;
    case 5:
        std::cout << "桶排序，";
        BucketSort<3, int>(testnum, 10);
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