/**
 * @function    常用的排序算法的集合。
 * @author      xuchanglong
 * @time        2019-08-20
*/
#include <cstddef>

/**
 * @function    插入排序算法。
 * @paras       pdata   待排序的数据的首地址。
 *              sum     待排序的数据的数量。
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