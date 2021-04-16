#include <stdio.h>
#include <math.h>

double areaTriangle(double x, double y, double z);

int main(int argc, char **argv)
{
    unsigned long long x, y, z, lineNumber = 0, min = __INT_MAX__, minNum = 1;
    while (scanf("%lld %lld %lld", &x, &y, &z) != EOF)
    {
        ++lineNumber;
        if ((x + y <= z) || (x + z <= y) || (y + z <= x))
            continue;

        if (areaTriangle(x, y, z) < min)
        {
            minNum = lineNumber;
            min = areaTriangle(x, y, z);
        }
    }
    printf("%lld\n", minNum);
    return 0;
}

double areaTriangle(double x, double y, double z)
{
    double s = (x + y + z) / 2;
    return sqrt(s * (s - x) * (s - y) * (s - z));
}