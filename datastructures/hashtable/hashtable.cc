#include <iostream>
#include <memory.h>

/*
 *	定义键值类型。
 */
typedef int KeyType;

/*
 *	声明函数返回值。
 */
enum eHashStatus
{
    HASH_SUCCESS = 0,
    HASH_UNSUCCESS,
    HASH_OVERFLOW,
};

/*
 *	声明记录类型。
 */
struct RcdType
{
    /*
	 *	关键字
	 */
    KeyType Key;
};

/*
 *	声明哈希表。
 */
struct sHashTable
{
    /*
	 *	记录存储基址。
	 */
    RcdType *pRcd;
    /*
	 *	关键字状态标记。
	 *	0	空。
	 *	1	有效。
	 *	2	已删除。
	 */
    int *pTag;
    /*
	 *	当前哈希表中含有的记录数量。
	 */
    int count;
    /*
	 *	哈希表容量。
	 */
    int size;
};

int Index = 0;
int HashTableSize[2] = {11, 31};

/*
 * 	function	哈希表的初始化。
 *	paras		H		哈希表
 *				size	哈希表中元素个数。
 *	return		函数执行状态。
 */
auto InitHashTable(sHashTable &H, const int &iSum) -> eHashStatus
{
    H.pRcd = (RcdType *)malloc(sizeof(KeyType) * iSum);
    H.pTag = (int *)malloc(sizeof(int) * iSum);

    if (
        (H.pRcd == nullptr) ||
        (H.pTag == nullptr))
    {
        return HASH_OVERFLOW;
    }

    memset(H.pRcd, 0, sizeof(RcdType) * iSum);
    memset(H.pTag, 0, sizeof(int) * iSum);

    H.count = 0;
    H.size = iSum;

    return HASH_SUCCESS;
}

/*
 *	哈希函数。
 */
auto Hash(const KeyType &Key, const int &size) -> int
{
    /*
	 *	保证 hash 值不会超过 m 。
	 */
    return Key * 3 % size;
}

/*
 *	线性探测法处理冲突。
 */
auto Collision(int &pos, const int &size) -> void
{
    /*
	 *	保证 hash 值不会超过 m 。
	 */
    pos = (pos + 1) % size;
}

/*
 *	打印哈希表。
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

auto ReCreateHashTable(sHashTable &H) -> eHashStatus;

/*
 *	function    哈希表的查找。
 *	paras   H   哈希表
 *			Key	待查找的 Key
 *			pos	该 key 在表中的位置。
 *			count   该 key 在表中冲突的次数。
 */
auto SearchRcd(const sHashTable &H, const KeyType &Key, int &pos, int &count) -> eHashStatus
{
    pos = Hash(Key, H.size);
    count = 0;
    /*
	 *	冲突处理。
	 */
    while (
        /*
		*   该位置有效且报错的 Key 和待查找的 Key 不一样，则继续跳过。
		*/
        (
            (H.pTag[pos] == 1) &&
            (H.pRcd[pos].Key != Key)) ||
        /*
		*	若该位置的关键字已经删除，则继续跳过。
		*/
        (H.pTag[pos] == -1))
    {
        Collision(pos, H.size);
        ++count;
    }

    if ((H.pTag[pos] == 1) && (H.pRcd[pos].Key == Key))
    {
        return HASH_SUCCESS;
    }
    else
    {
        return HASH_UNSUCCESS;
    }
}

/*
 *	插入。
 */
auto InsertRcd(sHashTable &H, const KeyType &Key) -> eHashStatus
{
    int pos, count;
    /*
	 *	没有相同key。
	 */
    if (HASH_UNSUCCESS == SearchRcd(H, Key, pos, count))
    {
        /*
		 *	冲突次数未达到上线。
		 */
        if ((count * 1.0f / H.size) < 0.5)
        {
            /*
			 *	插入 Key 。
			 */
            H.pRcd[pos].Key = Key;
            H.pTag[pos] = 1;
            ++H.count;
        }
        /*
		 *	熵太高，直接重构。
		 */
        else
        {
            ReCreateHashTable(H);
        }
    }
    else
    {
        return HASH_UNSUCCESS;
    }
    return HASH_SUCCESS;
}

/*
 *	销毁哈希表中指定的记录。
 */
auto DeleteRcd(sHashTable &H, const KeyType &Key) -> eHashStatus
{
    int pos, count;
    if (HASH_SUCCESS == SearchRcd(H, Key, pos, count))
    {
        /*
		 *	删除代码。
		 */
        H.pTag[pos] = -1;
        --H.count;
    }
    else
    {
        return HASH_UNSUCCESS;
    }
    return HASH_SUCCESS;
}
/*
 *	重构。
 */
auto ReCreateHashTable(sHashTable &H) -> eHashStatus
{
    RcdType *pRcd = H.pRcd;
    int *pTag = H.pTag;
    int size = H.size;

    if (InitHashTable(H, HashTableSize[Index++]) == HASH_SUCCESS)
    {
        /*
		 *	将现有的有效的 Key 重新放入新的 Hash Table 中。
		 *	各个 Key 与之前的位置不在一样。
		 */
        for (int i = 0; i < size; ++i)
        {
            if (pTag[i] == 1)
            {
                InsertRcd(H, pRcd[i].Key);
            }
        }
    }
    else
    {
        return HASH_UNSUCCESS;
    }
    return HASH_SUCCESS;
}

int main()
{
    sHashTable H;
    KeyType array[] = {22, 41, 53, 46, 30, 13, 12, 67};
    KeyType Key;

    std::cout << "-----------  创建 Hash Table  -----------" << std::endl;
    std::cout << "初始化 Hash Table";
    if (HASH_UNSUCCESS == InitHashTable(H, HashTableSize[Index++]))
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

    std::cout << "删除 Hash Table 中记录" << std::endl;
    if (HASH_UNSUCCESS == DeleteRcd(H, 12))
    {
        std::cout << "Failed to delete." << std::endl;
    }
    PrintHashTable(H);

    std::cout << std::endl;

    std::cout << "搜索 Hash Table 中记录" << std::endl;
    int pos;
    int count;
    if (HASH_UNSUCCESS == SearchRcd(H, 67, pos, count))
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
