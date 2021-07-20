#ifndef MAPSV_H
#define MAPSV_H

#include <iostream>
#include <vector>
#include "Map.h"
#include <cstring>
#include <string.h>
#include <stdio.h>

using namespace std;

class MapSV : public Map
{
private:
    vector<pair<string, int>> *arreglo;
    int n;
    int _size;
    int colisionAT;
    int colisionINSERT;

public:
    MapSV();
    ~MapSV();
    void insert(string palabrota);
    int at(string palabrita);
    void erase(string palabrinn);
    int size();
    bool empty();
    int colisionesAt();
    int colisionesInsert();
    int mayorMenor(int primero, int segundo);
    int metodoPalAt(int primero, string palabrin);
    int pos(string palabrin);
};
#endif