/**
 * @function    常用的排序算法的集合。
 * @time    2019-08-20
*/
#include <cstddef>
#include <string.h>
#include <vector>
#include <algorithm>
#include <functional>

#define SWAP(x, y)  \
    do              \
    {               \
        (x) ^= (y); \
        (y) ^= (x); \
        (x) ^= (y); \
    } while (false)

/*********************************************************
 * 
 ******* 插入排序 *******
 * 
*********************************************************/
/**
 * @function    插入排序算法。
 * @paras   pdata   待排序的数据的首地址。
 *          kCount  待排序的数据的数量。
 * @ret 0   操作成功。
 *      -1  pdata = nullptr
 * @time    2019-08-20
 * @notice  数据从小到大排列。
*/
template <typename T>
int InsertSort(T *pdata, const size_t &kCount)
{
    if (pdata == nullptr)
    {
        return -1;
    }
    int k = 0;
    T tmp;
    for (size_t i = 1; i < kCount; i++)
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

/*********************************************************
 * 
 ******* 选择排序 *******
 * 
*********************************************************/
/**
 * @function    选择排序算法。
 * @paras   pdata   待排序的数据的首地址。
 *          kCount  待排序的数据的数量。
 * @ret 0   操作成功。
 *      -1  pdata = nullptr
 * @time    2019-08-20
*/
template <typename T>
int SelectSort(T *pdata, const size_t &kCount)
{
    size_t imin = 0;
    if (pdata == nullptr)
    {
        return -1;
    }
    for (size_t i = 0; i < kCount - 1; i++)
    {
        imin = i;
        /**
         * 从未排序部分中查找最小值。
        */
        for (size_t k = i + 1; k < kCount; k++)
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

/*********************************************************
 * 
 ******* 归并排序 *******
 * 
*********************************************************/
/**
 * @function    归并排序算法的合并函数。
 * @paras   pdata   待排序的数据的首地址。
 *          s   待排序的数据的起始位置。
 *          m   待排序的数据的中间位置。
 *          e   待排序的数据的结束位置。
 * @ret 0   操作成功。
 *      -1  pdata = nullptr 。
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
 * @ret 0   操作成功。
 *      -1  pdata = nullptr 。
 *      -2  不符合递归条件。
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
 *          kCount  待排序的数据的数量。
 * @ret 0   操作成功。
 *      -1  pdata = nullptr 。
 * @time    2019-08-22
*/
template <typename T>
int MergeSort(T *pdata, const size_t &kCount)
{
    if (pdata == nullptr)
    {
        return -1;
    }
    _MergeSort(pdata, 0, kCount - 1);
    return 0;
}

/*********************************************************
 * 
 ******* 快速排序 *******
 * 
*********************************************************/
/**
 * @function    分区函数。将数组 pdata 以 pivot 为中间值分成前后两个部分，  
 *              前面是小于该中间值的，后面是大于该中间值的。最后返回该中间值
 *              所在的位置。
 * @praras  pdata   待分区的数组。
 *          s   数组的开始位置。
 *          e   数组的结束位置。
 * @ret 中间值所在的位置。
 * @time    2019-10-21
*/
template <typename T>
int Partition(T *pdata, int s, int e)
{
    int i, k;
    i = k = s;
    for (; k < e; k++)
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
    if (i != e)
    {
        SWAP(*(pdata + i), *(pdata + e));
    }
    return i;
}

/**
 * @function    快速排序的递归函数。
 * @paras  pdata   待排序的数组。
 *         s    数组的开始位置。
 *         e    数组的结束位置。
 * @ret -1  数组内容不存在。
 *      1   不符合递归。
 *      0   完成递归。
 * @time    2019-10-21
*/
template <typename T>
int _QuickeSort(T *pdata, int s, int e)
{
    if (pdata == nullptr)
    {
        return -1;
    }
    if (s >= e)
    {
        return 1;
    }
    int q = Partition(pdata, s, e);
    _QuickeSort(pdata, s, q - 1);
    _QuickeSort(pdata, q + 1, e);
    return 0;
}

/**
 * @function    快速排序的入口函数。
 * @paras   pdata   待排序的数组。
 *          kCount  数组的大小。
 * @ret -1  数组不存在。
 *      0   完成排序。
 * @time    2019-10-21
*/
template <typename T>
int QuickeSort(T *pdata, const size_t &kCount)
{
    return _QuickeSort(pdata, 0, kCount - 1);
}

/*********************************************************
 * 
 ******* 桶排序 *******
 * 
*********************************************************/
/**
 * @function    桶排序的入口函数。
 * @paras   pdata   待排序的数组。
 *          kCount  数组的大小。
 * @ret -1  数组不存在。
 *      0   完成排序。
 * @time    2019-10-22
*/
template <size_t kBucketSize,
          typename T,
          typename Compare = std::less<T>>
int BucketSort(T *pdata, const size_t &kCount, Compare comp = Compare())
{
    if (pdata == nullptr)
    {
        return -1;
    }
    std::vector<T> vdata(pdata, pdata + kCount);
    auto first = vdata.begin();
    auto last = vdata.end();
    const T min = *std::min_element(first, last);
    const T max = *std::max_element(first, last);
    const T range = max - min + 1;

    /**
     * 获取桶的数量。
    */
    const size_t kBucketCount = range / kBucketSize + 1;

    /**
     * 建立一个桶的集合。
    */
    std::vector<std::vector<T>> vbucketset(kBucketCount);

    /**
     * 为每个桶预留桶大小的 2 倍的空间。
    */
    for (auto bucket : vbucketset)
    {
        bucket.reserve(2 * kBucketSize);
    }
    /**
     * 将数据均匀分配到桶内。
    */
    for (auto it = first; it != last; ++it)
    {
        size_t pos = (*it - min) / kBucketSize;
        vbucketset[pos].emplace_back(*it);
    }

    /**
     * 对每个桶内的数据进行从小到大的排序
     * 并将结果依次覆盖原始数据中。
    */
    auto dest = first;
    for (auto it : vbucketset)
    {
        std::sort(it.begin(), it.end(), comp);
        std::copy(it.begin(), it.end(), dest);
        dest += it.size();
    }

    memcpy(pdata, &vdata[0], sizeof(T) * vdata.size());
    return 0;
}

/*********************************************************
 * 
 ******* 计数排序 *******
 * 
*********************************************************/
/**
 * @function    计数排序的入口函数。
 * @paras   pdata   待排序的数组。
 *          kCount  数组的大小。
 * @ret -1  数组不存在。
 *      0   完成排序。
 * @time    2019-10-22
*/
template <typename T>
int CountingSort(T *pdata, const size_t &kCount)
{
    /**
     * 将数组压入 vector 中。
    */
    std::vector<T> vdata(pdata, pdata + kCount);
    auto first = vdata.begin();
    auto last = vdata.end();
    size_t count = 0;
    count = std::distance(first, last);
    T max = *std::max_element(first, last);

    /**
     * 创建桶的集合，共 max + 1 个。
    */
    std::vector<size_t> vbucket(max + 1);

    /**
     * 将数据放入桶中。
    */
    for (auto it = first; it != last; it++)
    {
        ++vbucket[*it];
    }

    /**
     * 计算每个桶加上之前所有桶的数之和。
    */
    for (auto i = 1; i <= max + 1; i++)
    {
        vbucket[i] += vbucket[i - 1];
    }

    /**
     * 排序！
    */
    std::vector<T> vtmp(count);
    for (auto it = first; it != last; it++)
    {
        T t = *it;
        size_t pos = vbucket[t];
        vtmp[pos - 1] = t;
        --vbucket[t];
    }

    /**
     * 将数据返回。
    */
    memcpy(pdata, &vtmp[0], sizeof(T) * count);
    return 0;
}
