// Copyright (c) Wang Qirui. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ull unsigned long long

int main(int argc, char **argv)
{
    ull n;
    scanf("%lld", &n);
    ull counter = 0;

    double y = 0;
    ull inscribed_square = (ull)sqrt(n * n / 2);
    ull x = inscribed_square;
    while (x <= n)
    {
        counter += (long)y;
        x++;
        y = sqrt(n * n - x * x);
    }
    counter *= 8;
    counter += (4 * inscribed_square * inscribed_square);
    counter += (4 * n + 1);

    printf("%lld:%.15lf\n", n, (double)counter / (n * n));

    return 0;
}