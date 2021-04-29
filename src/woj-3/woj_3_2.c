// Copyright (c) Wang Qirui. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ull unsigned long long

int main(int argc, char **argv)
{
    char name[30] = {0}, minName1[30] = {0}, minName2[30] = {0};
    ull rank, min1 = 1 << 31 - 1, min2 = 1 << 31;
    while (scanf("%s %lld", name, &rank) != EOF)
    {
        if (rank < min2)
        {
            if (rank < min1)
            {
                min2 = min1;
                min1 = rank;
                strcpy(minName1, name);
            }
            else
            {
                min2 = rank;
                strcpy(minName2, name);
            }
        }
    }

    printf("%s\n%s\n", minName1, minName2);

    return 0;
}