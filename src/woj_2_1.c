// Copyright (c) Wang Qirui. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    char s[10239];
    char alphabet[26] = {0};
    int i;
    while (scanf("%s", s) != EOF)
    {
        for (i = 0; i < strlen(s); i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
                alphabet[s[i] - 'a'] += 1;
            else if (s[i] >= 'A' && s[i] <= 'Z')
                alphabet[s[i] - 'A'] += 1;
            else
                continue;
        }
    }
    for (i = 0; i < 26; i++)
    {
        if (!alphabet[i])
        {
            printf("%c", i + 'a');
        }
    }
    printf("\n");
    return 0;
}