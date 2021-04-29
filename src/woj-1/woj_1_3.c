// Copyright (c) Wang Qirui. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include <stdio.h>
#include <float.h>
#include <string.h>

double bmi(double weight, double height);

int main(int argc, char **argv)
{
    char name[30] = {0}, minName[30] = {0};
    double height, weight;
    double _bmi, bmiMin = DBL_MAX;
    while (scanf("%s %lf %lf", name, &height, &weight) != EOF)
    {
        _bmi = bmi(weight, height);
        if (_bmi < bmiMin)
        {
            bmiMin = _bmi;
            strcpy(minName, name);
        }
    }

    printf("%s\n", minName);

    return 0;
}

double bmi(double weight, double height)
{
    return weight / (height * height);
}