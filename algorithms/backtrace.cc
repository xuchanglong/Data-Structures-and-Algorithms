#include <iostream>

unsigned int g_count = 0;

bool isOK(unsigned char *p_result, const unsigned char &row, const unsigned char &column);
void PrintResult(unsigned char *p_result);
void Calc8Queens(unsigned char *p_result, const unsigned char &row);

int main()
{
    unsigned char result[8] = {5, 5, 5, 5, 5, 5, 5, 5};
    Calc8Queens(result, 0);
    std::cout << "共有 " << g_count << " 个结果" << std::endl;
    return 0;
}

bool isOK(unsigned char *p_result, const unsigned char &row, const unsigned char &column)
{
    if (p_result == nullptr)
        return false;
    unsigned char leftup = column - 1;
    unsigned char rightup = column + 1;
    for (int i = row - 1; i >= 0; --i)
    {
        if (p_result[i] == column)
            return false;
        if (leftup >= 0)
        {
            if (p_result[i] == leftup)
                return false;
        }
        if (rightup < 8)
        {
            if (p_result[i] == rightup)
                return false;
        }
        leftup--;
        rightup++;
    }
    return true;
}

void PrintResult(unsigned char *p_result)
{
    if (p_result == nullptr)
        return;
    for (unsigned char i = 0; i < 8; ++i)
    {
        for (unsigned char k = 0; k < p_result[i]; ++k)
            std::cout << "-"
                      << " ";
        std::cout << "a"
                  << " ";
        for (unsigned char k = p_result[i] + 1; k < 8; ++k)
            std::cout << "-"
                      << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
    return;
}

void Calc8Queens(unsigned char *p_result, const unsigned char &row)
{
    if (p_result == nullptr)
        return;
    if (row >= 8)
    {
        g_count++;
        PrintResult(p_result);
        return;
    }
    for (int column = 0; column < 8; ++column)
    {
        if (isOK(p_result, row, column))
        {
            p_result[row] = column;
            Calc8Queens(p_result, row + 1);
        }
    }
    return;
}