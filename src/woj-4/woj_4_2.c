// Copyright (c) Wang Qirui. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    char word[30] = {0};
    int counter[26] = {0};

    while (scanf("%s ", word) != EOF)
    {
        for (size_t i = 0; i < strlen(word); i++)
        {
            if (word[i] <= 'Z' && word[i] >= 'A')
                ++counter[word[i] - 'A'];
            else if (word[i] <= 'z' && word[i] >= 'a')
                ++counter[word[i] - 'a'];
        }
    }

    int max = -1;

    for (size_t i = 0; i < 26; i++)
        if (counter[i] > max)
            max = counter[i];

    printf("%d ", max);

    for (int i = 0; i < 26; i++)
        if (counter[i] == max)
            printf("%c", i + 'a');
    printf("\n");

    return 0;
}