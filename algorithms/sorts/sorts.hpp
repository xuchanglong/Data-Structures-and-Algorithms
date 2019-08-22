/**
 * @function    常用的排序算法的集合。
 * @author      xuchanglong
 * @time        2019-08-20
*/
#include <cstddef>

#define SWAP(x, y)  \
    {               \
        (x) ^= (y); \
        (y) ^= (x); \
        (x) ^= (y); \
    }

/**
 * @function    插入排序算法。
 * @paras       pdata   待排序的数据的首地址。
 *              count   待排序的数据的数量。
 * @return      0   操作成功。
 *              -1  pdata = nullptr
 * @author      xuchanglong
 * @time        2019-08-20
*/
template <typename T>
int InsertSort(T *pdata, size_t count)
{
    if (pdata == nullptr)
    {
        return -1;
    }
    int i = 0;
    int k = 0;
    T tmp;
    for (size_t i = 1; i < count; i++)
    {
        tmp = pdata[i];
        k = i - 1;
        while ((k >= 0) && (pdata[k] > tmp))
        {
            pdata[k + 1] = pdata[k];
            k--;
        }
        pdata[k + 1] = tmp;
    }

    return 0;
}

/**
 * @function    选择排序算法。
 * @paras       pdata   待排序的数据的首地址。
 *              count   待排序的数据的数量。
 * @return      0   操作成功。
 *              -1  pdata = nullptr
 * @author      xuchanglong
 * @time        2019-08-20
*/
template <typename T>
int SelectSort(T *pdata, size_t count)
{
    int imin = 0;
    if (pdata == nullptr)
    {
        return -1;
    }
    for (size_t i = 0; i < count - 1; i++)
    {
        imin = i;
        for (size_t k = i + 1; k < count; k++)
        {
            if (pdata[k] < pdata[imin])
            {
                imin = k;
            }
        }
        if (i != imin)
        {
            SWAP(pdata[i], pdata[imin]);
        }
    }

    return 0;
}

/**
 * @function    归并排序算法的合并函数。
 * @paras       pdata   待排序的数据的首地址。
 *              s       待排序的数据的起始位置。
 *              e       待排序的数据的结束位置。
 * @return      0   操作成功。
 *              -1  pdata = nullptr 。
 * @author      xuchanglong
 * @time        2019-08-22
*/
template <typename T>
int _MergeSort(T *pdata, size_t s, size_t tmp, size_t e)
{
    if (pdata == nullptr)
    {
        return -1;
    }
}

/**
 * @function    归并排序算法的迭代函数。
 * @paras       pdata   待排序的数据的首地址。
 *              s       待排序的数据的起始位置。
 *              e       待排序的数据的结束位置。
 * @return      0   操作成功。
 *              -1  pdata = nullptr 。
 *              -2  不符合递归条件。
 * @author      xuchanglong
 * @time        2019-08-22
*/
template <typename T>
int _MergeSort(T *pdata, size_t s, size_t e)
{
    size_t tmp = (s + e) / 2;
    if (pdata == nullptr)
    {
        return -1;
    }
    if (s <= e)
    {
        return -2;
    }
    _MergeSort(pdata, s, tmp);
    _MergeSort(pdata, tmp, e);
    return 0;
}

/**
 * @function    归并排序算法。
 * @paras       pdata   待排序的数据的首地址。
 *              count   待排序的数据的数量。
 * @return      0   操作成功。
 *              -1  pdata = nullptr 。
 * @author      xuchanglong
 * @time        2019-08-22
*/
template <typename T>
int MergeSort(T *pdata, size_t count)
{
    if (pdata == nullptr)
    {
        return -1;
    }
    _MergeSort(pdata, 0, count);
    return 0;
}