#include <cmath>
#include "hashing.hpp"

unsigned int hashing::hashingFunction(const unsigned int& num, const std::size_t& size)
{
    unsigned int hashedNum = 0;
    unsigned int n = num;
    unsigned int count = 0;
    unsigned int currentNum;

    while (n != 0)
    {
        ++count;
        n /= 10;
    }
    currentNum = num;
    for (unsigned int i = 0; i != count; ++i)
    {
        // hashedNum += num / (count - i) * (i + 1);
        unsigned int diff = currentNum % static_cast<int>(std::pow(10, count - i - 1));
        hashedNum += (currentNum - diff) * (i + 1);
        currentNum = diff;
    }

    hashedNum %= size;

    return hashedNum;
}