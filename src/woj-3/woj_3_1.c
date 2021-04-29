// Copyright (c) Wang Qirui. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    char line[2047];

    char out[20] = {0};
    int counter = 0;
    int result;
    int i, j;

    while (1)
    {
        result = scanf("%[^\n]", line);
        if (result == EOF)
            break;
        if (result == 0)
        {
            fprintf(stderr, "\n");
            getchar();
            continue;
        }
        getchar();
        for (i = 0; i < strlen(line); i++)
        {
            j = 0;
            if (line[i] > '9' || line[i] < '0')
                continue;
            else
            {
                while (1)
                {
                    if (line[i + j] <= '9' && line[i + j] >= '0')
                    {
                        if (counter > 1)
                            break;
                        out[j] = line[i + j];
                        ++j;
                    }
                    else
                    {
                        ++counter;
                        break;
                    }
                }
                out[j] = '\0';
                i += j;
            }
        }

        if (counter == 1)
        {
            printf("%s\n", out);
        }
        else
        {
            fprintf(stderr, "%s\n", line);
        }
        counter = 0;
    }

    return 0;
}