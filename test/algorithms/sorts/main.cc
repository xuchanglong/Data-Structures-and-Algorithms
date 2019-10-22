#include "sorts/sorts.hpp"
#include <iostream>
#include <cstdio>

#define ELEMENTSUM(x) \
    sizeof(x) / sizeof((x)[0])

template <typename T>
void Show(T *pdata, size_t count);

/**
 * 1    插入排序。
 * 2    选择排序。
 * 3    归并排序。
 * 4    快速排序。
 * 5    桶排序。
 * 6    计数排序。
 */
int main(int argc, const char *argv[])
{
    if (argc == 1)
    {
        std::cout << "请选择排序算法！" << std::endl;
        return 1;
    }

    int algtype = atoi(argv[1]);
    int testnum[] = {13, 3, 4, 5, 2, 6, 4, 8, 4, 0, 7, 7, 9, 9, 9, 10, 11, 12, 10, 12};

    std::cout << "原始数据。" << std::endl;
    Show(testnum, ELEMENTSUM(testnum));

    switch (algtype)
    {
    case 1:
        std::cout << "插入排序，";
        InsertSort(testnum, ELEMENTSUM(testnum));
        break;
    case 2:
        std::cout << "选择排序，";
        SelectSort(testnum, ELEMENTSUM(testnum));
        break;
    case 3:
        std::cout << "归并排序，";
        MergeSort(testnum, ELEMENTSUM(testnum));
        break;
    case 4:
        std::cout << "快速排序，";
        QuickeSort(testnum, ELEMENTSUM(testnum));
        break;
    case 5:
        std::cout << "桶排序，";
        BucketSort<3, int>(testnum, ELEMENTSUM(testnum));
        break;
    case 6:
        std::cout << "计数排序，";
        CountingSort(testnum, ELEMENTSUM(testnum));
        break;
    default:
        break;
    }

    std::cout << "排序之后的数据。" << std::endl;
    Show(testnum, ELEMENTSUM(testnum));

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