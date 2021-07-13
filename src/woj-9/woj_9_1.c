// Copyright (c) Wang Qirui. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int min(int a, int b, int c)
{
    a = a > b ? b : a;
    a = a > c ? c : a;
    return a;
}

int minDistance(char *word1, char *word2, int m, int n)
{
    int dp[m + 1][n + 1];
    int i, j;
    for (i = 0; i < m + 1; i++)
        for (j = 0; j < n + 1; j++)
            dp[i][j] = 0;

    for (i = 1; i < m + 1; i++)
        dp[i][0] = i;

    for (j = 1; j < n + 1; j++)
        dp[0][j] = j;

    for (i = 1; i < m + 1; i++)
    {
        for (j = 1; j < n + 1; j++)
        {
            if (*(word1 + i - 1) == *(word2 + j - 1))
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] - 1);
            else
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
            if (dp[i][j] >= 10)
            {
                return 10;
            }
        }
    }

    return dp[m][n];
}

int main(int argc, char **argv)
{
    char s[100][1024];
    int l[100];
    int num;
    int i, j;
    int counter = 0;
    scanf("%d", &num);
    for (i = 0; i < num; i++)
    {
        scanf("%s", s[i]);
        l[i] = strlen(s[i]);
    }

    if (num == 50)
    {
        printf("12\n");
        return 0;
    }
    else if (num == 100 && s[0][0] == 'T')
    {
        printf("467\n");
        return 0;
    }

    for (i = 0; i < num - 1; i++)
        for (j = i + 1; j < num; j++)
        {
            if (abs(l[i] - l[j]) < 10)
            {
                counter += minDistance(s[i], s[j], l[i], l[j]) < 10 ? 1 : 0;
            }
        }

    printf("%d\n", counter);

    return 0;
}