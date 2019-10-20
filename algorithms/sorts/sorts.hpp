/**
 * @function    常用的排序算法的集合。
 * @author  xuchanglong
 * @time    2019-08-20
*/
#include <cstddef>
#include <string.h>

#define SWAP(x, y)  \
    do              \
    {               \
        (x) ^= (y); \
        (y) ^= (x); \
        (x) ^= (y); \
    } while (false)

/**************************************
 * 
 ******* 插入排序 *******
 * 
**************************************/
/**
 * @function    插入排序算法。
 * @paras   pdata   待排序的数据的首地址。
 *          count   待排序的数据的数量。
 * @return  0   操作成功。
 *          -1  pdata = nullptr
 * @author  xuchanglong
 * @time    2019-08-20
 * @notice  数据从小到大排列。
*/
template <typename T>
int InsertSort(T *pdata, const size_t &count)
{
    if (pdata == nullptr)
    {
        return -1;
    }
    int k = 0;
    T tmp;
    for (size_t i = 1; i < count; i++)
    {
        tmp = pdata[i];
        k = i - 1;
        /**
         * 查找插入位置。
         * 比较时没有等号，故该算法是稳定排序算法。
        */
        while ((k >= 0) && (pdata[k] > tmp))
        {
            /**
             * 数据移动。
            */
            pdata[k + 1] = pdata[k];
            k--;
        }
        /**
         * 插入数据。
        */
        pdata[k + 1] = tmp;
    }

    return 0;
}

/**************************************
 * 
 ******* 选择排序 *******
 * 
**************************************/
/**
 * @function    选择排序算法。
 * @paras   pdata   待排序的数据的首地址。
 *          count   待排序的数据的数量。
 * @return  0   操作成功。
 *          -1  pdata = nullptr
 * @author  xuchanglong
 * @time    2019-08-20
*/
template <typename T>
int SelectSort(T *pdata, const size_t &count)
{
    size_t imin = 0;
    if (pdata == nullptr)
    {
        return -1;
    }
    for (size_t i = 0; i < count - 1; i++)
    {
        imin = i;
        /**
         * 从未排序部分中查找最小值。
        */
        for (size_t k = i + 1; k < count; k++)
        {
            if (pdata[k] < pdata[imin])
            {
                imin = k;
            }
        }
        /**
         * 将查到的最小值和当前值进行交换。
        */
        if (i != imin)
        {
            SWAP(pdata[i], pdata[imin]);
        }
    }

    return 0;
}

/**************************************
 * 
 ******* 归并排序 *******
 * 
**************************************/
/**
 * @function    归并排序算法的合并函数。
 * @paras   pdata   待排序的数据的首地址。
 *          s   待排序的数据的起始位置。
 *          m   待排序的数据的中间位置。
 *          e   待排序的数据的结束位置。
 * @return  0   操作成功。
 *          -1  pdata = nullptr 。
 * @author  xuchanglong
 * @time    2019-08-22
*/
template <typename T>
int _Merge(T *pdata, const size_t &s, const size_t &m, const size_t &e)
{
    if (pdata == nullptr)
    {
        return -1;
    }
    T *ptmp = new T[e - s + 1];
    size_t i, t, k;

    /**
     * 两组数据合并。
    */
    for (i = s, t = m + 1, k = 0; (i <= m) && (t <= e);)
    {
        /**
         * 该等号的位置保证了排序算法的稳定性。
         * 因为前后两部分合并时，当发现有相同元素时，首先将属于前一部分的元素复制到临时数组中，
         * 从而保证了排序算法的稳定性。
        */
        if (pdata[i] <= pdata[t])
        {
            ptmp[k++] = pdata[i++];
        }
        else
        {
            ptmp[k++] = pdata[t++];
        }
    }

    /**
     * 将剩余的数据补充到排序好的数组中。
    */
    if (i == m + 1)
    {
        while (t <= e)
        {
            ptmp[k++] = pdata[t++];
        }
    }
    else
    {
        while (i <= m)
        {
            ptmp[k++] = pdata[i++];
        }
    }

    memcpy(pdata + s, ptmp, sizeof(T) * (e - s + 1));
    delete[] ptmp;
    ptmp = nullptr;
    return 0;
}

/**
 * @function    归并排序算法的迭代函数。
 * @paras   pdata   待排序的数据的首地址。
 *          s   待排序的数据的起始位置。
 *          e   待排序的数据的结束位置。
 * @return  0   操作成功。
 *          -1  pdata = nullptr 。
 *          -2  不符合递归条件。
 * @author  xuchanglong
 * @time    2019-08-22
*/
template <typename T>
int _MergeSort(T *pdata, const size_t &s, const size_t &e)
{
    if (pdata == nullptr)
    {
        return -1;
    }
    if (s >= e)
    {
        return -2;
    }
    /**
     * 求解 s 和 e 的中间值。
    */
    const size_t m = (s + e) >> 1;
    _MergeSort(pdata, s, m);
    _MergeSort(pdata, m + 1, e);
    _Merge(pdata, s, m, e);
    return 0;
}

/**
 * @function    归并排序算法。
 * @paras   pdata   待排序的数据的首地址。
 *          count   待排序的数据的数量。
 * @return  0   操作成功。
 *          -1  pdata = nullptr 。
 * @author  xuchanglong
 * @time    2019-08-22
*/
template <typename T>
int MergeSort(T *pdata, const size_t &count)
{
    if (pdata == nullptr)
    {
        return -1;
    }
    _MergeSort(pdata, 0, count - 1);
    return 0;
}

/**************************************
 * 
 ******* 快速排序 *******
 * 
**************************************/
template <typename T>
int Partition(T *pdata, size_t s, size_t e)
{
    int i, k;
    i = k = s;
    for (; k <= e; k++)
    {
        if (pdata[k] < pdata[e])
        {
            if (i != k)
            {
                SWAP(*(pdata + i), *(pdata + k));
            }
            ++i;
        }
    }
    SWAP(*(pdata + i), *(pdata + e));
    return i;
}

template <typename T>
int _QuickeSort(T *pdata, size_t s, size_t e)
{
    if (pdata == nullptr)
    {
        return -1;
    }
    if (e <= s)
    {
        return -2;
    }
    size_t q = Partition(pdata, s, e);
    _QuickeSort(pdata, s, q);
    _QuickeSort(pdata, q + 1, e);
    return 0;
}

template <typename T>
int QuickeSort(T *pdata, size_t count)
{
    return _QuickeSort(pdata, 0, count - 1);
}