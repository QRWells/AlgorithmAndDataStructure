// Copyright (c) Wang Qirui. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include <stdio.h>
#include <math.h>

int main(int argc, char **argv)
{
    int h, w;
    int j, i;
    while (scanf("%d %d", &h, &w) != EOF)
    {

        if (h == 0)
            break;

        int diag = h * h + w * w;
        for (i = diag; i != 0; ++i)
        {
            for (j = 1; 2 * j * j < i; ++j)
            {
                int rem = i - j * j;
                int sqrem = sqrt(rem);
                if (sqrem * sqrem == rem)
                {
                    if (i == diag && j <= h)
                        continue;
                    printf("%d %d\n", j, sqrem);
                    i = -1;
                    break;
                }
            }
        }
    }
    return 0;
}