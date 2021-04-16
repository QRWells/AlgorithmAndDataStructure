#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int list_size = (1 << 7) - 1;
    int current_size = 0;
    int *list_back = (int *)malloc(list_size * sizeof(int));
    int *list = list_back;

    int max, last;
    int counter_cur = 1;
    int counter_max = 1;

    while (1)
    {
        if (scanf("%d", list + current_size) == EOF)
            break;
        current_size++;
        if (current_size == list_size)
        {
            list_size = list_size * 2 + 1;
            list_back = (int *)malloc(list_size * sizeof(int));
            int j;
            for (j = 0; j < current_size; j++)
            {
                list_back[j] = list[j];
            }

            free(list);
            list = list_back;
        }
    }

    last = list[current_size - 1];
    max = list[current_size - 1];

    int i;

    for (i = current_size - 2; i > -1; i--)
    {
        if (i[list] == last)
        {
            ++counter_cur;
            if (counter_cur > counter_max)
            {
                max = i[list];
                counter_max = counter_cur;
            }
        }
        else
        {
            last = i[list];
            counter_cur = 1;
        }
    }

    printf("%d %d\n", counter_max, max);

    return 0;
}