#ifndef MAPSV_H
#define MAPSV_H

#include <iostream>
#include <vector>
#include "Map.h"

using namespace std;

class MapSV : public Map
{
private:
    vector<pair<string, int>> *arreglo;
    int n;
    int _size;

public:
    MapSV();
    ~MapSV();
    void insert(int n);
    int at(int n);
    void erase(int n);
    int size();
    bool empty();
};
#endif