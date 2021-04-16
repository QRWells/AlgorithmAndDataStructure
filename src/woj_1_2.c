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