/**
 * @function    queue/linklistqueue/linklistqueue.hpp 的单元测试代码。
 * @time    2019-08-04
 */
#include "queue/linklistqueue/linklistqueue.hpp"
#include <iostream>

/**
 * @function    依次从队列中取出元素，显示到控制台上。
 * @paras   queue   队列
 * @ret none。
 * @time    2019-08-04
 */
template <typename T>
void ShowQueue(LinkListQueue<T> &queue);

/**
 * @function    针对不同存储类型的队列，进行测试。
 * @paras   pdata待测试的数组。
 *          kDataSize    数组大小。
 * @ret 测试结果。
 * @time    2019-08-04
 */
template <typename T>
int TestQueue(T *pdata, const size_t &kDataSize);

int main()
{
    std::cout << "int" << std::endl;
    int isum[10] = {1, 43, 4, 3, 2, 9, 35, 654, 65, 732};
    TestQueue(isum, 10);

    std::cout << std::endl
              << "double" << std::endl;

    double dsum[7] = {1.62, 89.854, 42.0254, 57.9513, 726.8913, 71345, 5251.54};
    TestQueue(dsum, 7);

    std::cout << std::endl
              << "string" << std::endl;

    std::string strsum[12] = {"a1", "1.62", "c1", "42.0254", "e1", "f1", "aa2", "bb2", "cc2", "dd2", "ee2", "ff2"};
    TestQueue(strsum, 12);

    return 0;
}

template <typename T>
void ShowQueue(LinkListQueue<T> &queue)
{
    T data;
    while (queue.DeQueue(data) == 0)
    {
        std::cout << data << "、";
    }
    std::cout << std::endl;
}

template <typename T>
int TestQueue(T *pdata, const size_t &kDataSize)
{
    LinkListQueue<T> queue;
    if (queue.Create() != 0)
    {
        std::cout << "Create LinkListQueue failed." << std::endl;
        return -1;
    }
    //  向队列中进行压入数据。
    std::cout << "-------------------  Enter  -------------------" << std::endl;
    //  若数据溢出，则返回报错。
    for (size_t i = 0; i < kDataSize; i++)
    {
        if (queue.EnQueue(&pdata[i]) != 0)
        {
            std::cout << pdata[i] << " can't enter queue." << std::endl;
        }
    }
    ShowQueue(queue);
    return 0;
}