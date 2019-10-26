#include <iostream>
#include <memory.h>

/*
 *	定义键值类型，即：存储在散列表中的数据的类型。
 */
typedef int KeyType;

/*
 *	声明记录类型。
 */
struct RcdType
{
    //  关键字，也是散列表中存储的内容。
    KeyType Key;
};

/*
 *	哈希表对象
 */
struct sHashTable
{
    //  记录存储基址。
    RcdType *pRcd;

    /**
     * 关键字状态标记。
     * 0	空。
     * 1	有效。
     * 2	已删除。
    */
    int *pTag;

    //  当前哈希表中含有的记录数量。
    int count;

    //  散列表的大小。
    int size;
};

/**
 * 散列表大小的序号。
*/
int Index = 0;

/**
 * 记录散列表的大小的数组。和 Index 配合使用。
*/
int HashTableSize[2] = {11, 31};

/**
 * @function    初始化散列表。
 * @paras   H   待初始化的散列表对象。
 *          kSize   散列表的大小。
 * @ret 0   操作成功。
 *      -1  申请内存失败。
*/
auto InitHashTable(sHashTable &H, const int &kSize) -> int
{
    H.pRcd = (RcdType *)malloc(sizeof(KeyType) * kSize);
    H.pTag = (int *)malloc(sizeof(int) * kSize);

    if (
        (H.pRcd == nullptr) ||
        (H.pTag == nullptr))
    {
        return -1;
    }

    memset(H.pRcd, 0, sizeof(RcdType) * kSize);
    memset(H.pTag, 0, sizeof(int) * kSize);

    H.count = 0;
    H.size = kSize;

    return 0;
}

/**
 * @function    哈希函数。用于计算 key 在散列表中的位置。
 * @paras   Key 被查找和保存的值。
 *          size    散列表的大小。
 * @ret 散列值。
*/
auto Hash(const KeyType &Key, const int &size) -> int
{
    /*
	 *	保证 hash 值不会超过 m 。
	 */
    return Key * 3 % size;
}

/**
 * @function    线性探测法处理冲突。
 * @paras   pos 
 * @ret none 。
*/
auto Collision(int &pos, const int &size) -> void
{
    /*
	 *	保证 hash 值不会超过散列表的大小 。
	 */
    pos = (pos + 1) % size;
    return;
}

/**
 * @function    打印哈希表内容。
 * @paras   H   散列表对象。
 * @ret None 。
*/
auto PrintHashTable(const sHashTable &H) -> void
{
    std::cout << "Rcd :";
    for (size_t i = 0; i < H.size; ++i)
    {
        std::cout << H.pRcd[i].Key << " ";
    }
    std::cout << std::endl;

    for (size_t i = 0; i < H.size; ++i)
    {
        std::cout << H.pTag[i] << " ";
    }
    std::cout << std::endl;
}

auto ReCreateHashTable(sHashTable &H) -> int;

/**
 * @function  从散列表中查找指定的记录。
 * @paras   H   散列表对象。
 *          Key	待查找的记录。
 *			pos	返回该 key 在表中的位置。
 *			count   返回在查找该 key 时冲突的次数。
 * @ret 0   找到了指定的记录 。
 *      -1  未找到指定的记录，该位置为空。
*/
auto SearchRcd(const sHashTable &H, const KeyType &Key, int &pos, int &count) -> int
{
    pos = Hash(Key, H.size);
    count = 0;
    //  处理冲突。
    while (
        //  若该位置的关键字已经删除，则继续查找。
        (H.pTag[pos] == 2) ||
        //  该位置有效且该记录和待查找的记录不同，则继续查找。
        (
            (H.pTag[pos] == 1) &&
            (H.pRcd[pos].Key != Key)))
    {
        Collision(pos, H.size);
        ++count;
    }

    if ((H.pTag[pos] == 1) && (H.pRcd[pos].Key == Key))
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

/**
 * @function    将记录插入到散列表中。
 * @paras   H   散列表
 *          Key 被插入的记录。
 * @ret 0   插入成功。
*/
auto InsertRcd(sHashTable &H, const KeyType &Key) -> int
{
    int pos, count;
    if (-1 == SearchRcd(H, Key, pos, count))
    {
        /**
         * 寻找没有数据的位置。
         */
        //  冲突次数未达到上线。
        if ((count * 1.0f / H.size) < 0.5)
        {
            // 插入记录。
            H.pRcd[pos].Key = Key;
            H.pTag[pos] = 1;
            ++H.count;
        }
        //  熵太高，直接重构。
        else
        {
            ReCreateHashTable(H);
        }
    }
    else
    {
        return -1;
    }
    return 0;
}

/**
 * 
*/

/**
 * @function    删除散列表中的指定记录。
 * @paras   H   散列表的对象。
 *          Key 指定的记录。
 * @ret 0   删除成功。
 *      -1  删除失败。
*/
auto DeleteRcd(sHashTable &H, const KeyType &Key) -> int
{
    int pos, count;
    if (0 == SearchRcd(H, Key, pos, count))
    {
        //  删除代码。
        H.pTag[pos] = 2;
        --H.count;
    }
    else
    {
        return -1;
    }
    return 0;
}

/**
 * @function    重构散列表，即：扩大散列表的大小。
 * @paras   被重构的散列表。
 * @ret 0   重构成功。
 *      -1  申请新的散列表失败。
*/
auto ReCreateHashTable(sHashTable &H) -> int
{
    RcdType *pRcd = H.pRcd;
    int *pTag = H.pTag;
    int size = H.size;

    if (InitHashTable(H, HashTableSize[Index++]) == 0)
    {
        /*
		 *	将现有的有效的记录重新放入新的 Hash Table 中。
		 *	各个记录与之前的位置不在一样。
		 */
        for (int i = 0; i < size; ++i)
        {
            if (pTag[i] == 1)
            {
                InsertRcd(H, pRcd[i].Key);
            }
        }
        delete pRcd;
        pRcd = nullptr;
        delete pTag;
        pTag = nullptr;
    }
    else
    {
        return -1;
    }
    return 0;
}

int main()
{
    sHashTable H;
    KeyType array[] = {22, 41, 53, 46, 30, 13, 12, 67};
    KeyType Key;

    std::cout << "-----------  创建 Hash Table  -----------" << std::endl;
    std::cout << "初始化 Hash Table";
    if (-1 == InitHashTable(H, HashTableSize[Index++]))
    {
        std::cout << "Initialization failed" << std::endl;
        return 1;
    }

    std::cout << std::endl;
    std::cout << "插入 Hash Table " << std::endl;
    for (const KeyType &Key : array)
    {
        InsertRcd(H, Key);
        PrintHashTable(H);
    }

    std::cout << std::endl;
    std::cout << "删除 Hash Table 中记录 " << "12" << std::endl;
    if (-1 == DeleteRcd(H, 12))
    {
        std::cout << "Failed to delete." << std::endl;
    }
    PrintHashTable(H);

    std::cout << std::endl;
    std::cout << "搜索 Hash Table 中记录" << std::endl;
    int pos;
    int count;
    if (-1 == SearchRcd(H, 67, pos, count))
    {
        std::cout << "Failed to search." << std::endl;
    }

    std::cout << std::endl;
    std::cout << "再次向 Hash Table 中插入记录，测试重构" << std::endl;
    KeyType array1[8] = {27, 47, 57, 47, 37, 17, 93, 67};
    for (const KeyType &Key : array1)
    {
        InsertRcd(H, Key);
        PrintHashTable(H);
    }

    std::cin.get();
    return 0;
}
