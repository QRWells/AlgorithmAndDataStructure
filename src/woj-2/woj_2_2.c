// Copyright (c) Wang Qirui. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include <stdio.h>
#include <string.h>

#define state short
#define none 0
#define start_slash 1
#define start 2
#define end 3
#define is ==
#define and &&

int main(int argc, char **argv)
{
    char s[10239];
    int count = 0;
    state flag = none;
    int i;
    while (scanf("%s", s) != EOF)
    {
        for (i = 0; i < strlen(s); i++)
        {
            if (flag is end and s[i] is '/' and s[i - 1] is '*')
            {
                ++count;
                flag = none;
                continue;
            }

            if (flag is start and s[i] is '*')
                flag = end;

            if (flag is start_slash and s[i] is '*' and s[i - 1] is '/')
                flag = start;

            if (flag is none and s[i] is '/')
                flag = start_slash;
        }
    }

    printf("%d\n", count);

    return 0;
}