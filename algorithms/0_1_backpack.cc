#include <iostream>

unsigned int g_max = 0;
void func(const int &index, const int &cw, const int *const pitems, const int &count, const int &maxW);

int main()
{
    int items[10] = {80, 20, 90, 9, 50, 6, 70, 8, 9, 10};
    func(0, 0, items, 10, 111);
    std::cout << "所能容纳的最大的物件重量为 " << g_max << std::endl;
    return 0;
}

void func(const int &index, const int &cw, const int *const pitems, const int &count, const int &maxW)
{
    if (cw == maxW || index >= count)
    {
        if (cw > g_max)
            g_max = cw;
        return;
    }
    func(index + 1, cw, pitems, count, maxW);
    if (cw + pitems[index] <= maxW)
        func(index + 1, cw + pitems[index], pitems, count, maxW);
    return;
}