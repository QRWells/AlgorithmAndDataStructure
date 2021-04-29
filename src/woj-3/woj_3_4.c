// Copyright (c) Wang Qirui. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include <stdio.h>
#include <math.h>

const double EPS = 1e-6;

int main(int argc, char **argv)
{
    double x, y, z, maximum, tmp;

    double i, j;

    while (1)
    {
        scanf("%lf %lf %lf", &x, &y, &z);
        if (x == 0 && y == 0 && z == 0)
            break;

        maximum = 0;

        for (i = 1; i <= z - 1; i += 1.0)
        {
            for (j = i; j <= z - 1; j += 1.0)
            {
                if (i + j > z)
                    break;

                if (fabs(floor(i * (100 + x) / 100) + floor(j * (100 + x) / 100) - z) < EPS)
                {
                    tmp = floor(i * (100 + y) / 100) + floor(j * (100 + y) / 100);
                    maximum = fmax(maximum, tmp);
                }
            }
        }

        printf("%.0f\n", maximum);
    }

    return 0;
}