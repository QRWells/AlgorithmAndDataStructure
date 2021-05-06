// Copyright (c) Wang Qirui. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include <stdio.h>
#include <math.h>

#define bool int
#define true 1
#define false 0

bool is_prime(unsigned long long num)
{
    unsigned long long i, half;

    if (num <= 1)
        return false;
    if (num == 2 || num == 3)
        return true;
    else if (num % 6 != 1 && num % 6 != 5)
        return false;

    half = (unsigned long long)sqrt(num);
    for (i = 5; i <= half; i += 6)
        if (num % i == 0 || num % (i + 2) == 0)
            return false;

    return true;
}

int main(int argc, char **argv)
{
    int n;
    int counter;
    while (scanf("%d", &n) != EOF)
    {
        counter = 0;
        if (n < 1)
            break;

        for (size_t i = n + 1; i <= 2 * n; i++)
            if (is_prime((i)))
                ++counter;

        printf("%d\n", counter);
    }

    return 0;
}