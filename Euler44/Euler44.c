#include <stdio.h>
#include <math.h>

int isPentagonal(unsigned long long x)
{
    unsigned long long n = (1 + sqrt(24 * x + 1)) / 6;
    unsigned long long p_n = n * (3 * n - 1) / 2;
    return p_n == x;
}

int main()
{
#define ORIGINAL

#ifdef ORIGINAL
    const unsigned int HugeNumber = 999999999;
    unsigned int best = HugeNumber;
    unsigned int n = 2; // start with P(2)
    unsigned int last = 1; // P(1)

    while (best == HugeNumber)
    {
        // next pentagonal number
        unsigned long long p_n = n * (3 * n - 1) / 2;
        // difference to closest pentagonal number larger than our best result ?
        if (p_n - last > best)
            break;

        // check all pairs P(n) and P(n - distance) where 1 <= distance < n
        for (unsigned int distance = 1; distance < n; distance++)
        {
            // compute P(n - distance) pentagonal number
            unsigned long long x = n - distance;
            unsigned long long p_x = x * (3 * x - 1) / 2;

            // their sum and difference
            unsigned long long sum = p_n + p_x;
            unsigned long long difference = p_n - p_x;

            // too far away ?
            if (difference > best)
                break;

            // yes, found something
            if (isPentagonal(sum) && isPentagonal(difference))
                best = difference;
        }

        // check next pentagonal number
        last = p_n;
        n++;
    }
    printf("%u\n", best);

#else

    unsigned int maxIndex;
    unsigned int distance;
    scanf("%u %u", &maxIndex, &distance);

    // iterate over all pairs at a given distance
    for (unsigned long long n = distance + 1; n <= maxIndex; n++)
    {
        unsigned long long p_n = n * (3 * n - 1) / 2;

        unsigned long long x = n - distance;
        unsigned long long p_x = x * (3 * x - 1) / 2;

        // check sum and difference
        unsigned long long sum = p_n + p_x;
        unsigned long long difference = p_n - p_x;

        // yes, found something
        if (isPentagonal(sum) || isPentagonal(difference))
            printf("%llu\n", p_n);
    }
#endif

    return 0;
}

