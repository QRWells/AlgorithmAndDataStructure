// Copyright (c) Wang Qirui. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include <stdio.h>
#include <math.h>

typedef struct point
{
    double x;
    double y;
} Point;

double areaN(int nq, Point v[])
{
    double s = 0;
    int i, j;
    double xi, yi;
    double xj, yj;

    for (i = 0; i < nq; i++)
    {
        xi = v[i].x;
        yi = v[i].y;

        j = (i == nq - 1) ? 0 : i + 1;

        xj = v[j].x;
        yj = v[j].y;

        s += 0.5 * (yi + yj) * (xi - xj);
    }
    return s;
}

int main(int argc, char **argv)
{
    int i;
    Point vert[4];
    for (i = 0; i < 4; i++)
        scanf("%lf %lf ", &vert[i].x, &vert[i].y);

    printf("%.3lf\n", fabs(areaN(4, vert)));

    return 0;
}