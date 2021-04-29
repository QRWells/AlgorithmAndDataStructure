// Copyright (c) Wang Qirui. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv)
{
    int i;
    int count = 0;
    char str[1023][50];

    while (scanf("%s ", str[count]) != EOF)
    {
        for (i = 0; i < strlen(str[count]); i++)
        {
            str[count][i] = tolower(str[count][i]);
        }

        ++count;
    }

    int min = 0;

    for (i = 1; i < count; ++i)
    {
        if (strcmp(str[min], str[i]) > 0)
        {
            min = i;
        }
    }

    printf("%s\n", str[min]);

    return 0;
}