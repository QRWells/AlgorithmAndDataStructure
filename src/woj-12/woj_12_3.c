#include <stdio.h>

#define maxN 10000
int aux[maxN];
int target[maxN];

void sort(int[], int, int);
void merge(int[], int, int, int);
int min(int, int);

int main(int argc, char const *argv[])
{
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", target + i);
    sort(target, 0, n - 1);
    for (i = 0; i < n; i++)
        printf("%d\n", target[i]);

    return 0;
}

void sort(int a[], int l, int r)
{
    if (r <= l)
        return;
    int n = r - l + 1;
    int sz, lo;
    for (sz = 1; sz < n; sz += sz)
        for (lo = 0; lo < n - sz; lo += (sz << 1))
            merge(a, lo, lo + sz - 1, min(lo + sz + sz - 1, n - 1));
}

void merge(int a[], int l, int m, int r)
{
    int i, j, k;
    for (i = m + 1; i > l; i--)
        aux[i - 1] = a[i - 1];
    for (j = m; j < r; j++)
        aux[r + m - j] = a[j + 1];
    for (k = l; k <= r; k++)
        if (aux[i] <= aux[j])
            a[k] = aux[i++];
        else
            a[k] = aux[j--];
}

int min(int a, int b)
{
    return a > b ? b : a;
}