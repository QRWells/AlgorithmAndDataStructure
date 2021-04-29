// Copyright (c) Wang Qirui. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include <stdio.h>

int main(int argc, char **argv)
{
    unsigned long long max, out = 1;
    scanf("%lld", &max);
    while (out <= max)
    {
        printf("%lld\n", out);
        out *= 3;
    }
    return 0;
}