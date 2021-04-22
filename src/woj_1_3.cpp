// Copyright (c) Wang Qirui. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include <iostream>
#include <map>
#include <string>

using namespace std;

double bmi(double weight, double height)
{
    return weight / (height * height);
}

int main(int argc, char **argv)
{
    double *_weight = new double, *_height = new double;
    double *_bmi = new double;
    string *_name = new string();
    map<double, string> *_map = new map<double, string>();
    while (cin >> *_name >> *_height >> *_weight)
    {
        *_bmi = bmi(*_weight, *_height);
        _map->insert(pair<double, string>(*_bmi, *_name));
    }

    map<double, string>::iterator it = _map->begin();

    cout << it->second << endl;

    delete _bmi;
    delete _weight;
    delete _height;
    delete _name;
    delete _map;

    return 0;
}