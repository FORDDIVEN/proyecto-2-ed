#ifndef MAPDH_H
#define MAPDH_H

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class MapDH
{
private:
    int _size;
    int n;
    vector<pair<string, int>> *hashTable;
    int pos(string palabrota);
    int polinomialHash(string palabra);
    int superPolinomialHash(int n);
    void agrandar();
    int colisionInsert;
    int colisionAt;
    int comprimir(int hash);

public:
    MapDH(int n);
    ~MapDH();
    void insert(pair<string, int> entrada);
    void erase(string palabra);
    int at(string palabra);
    int size();
    bool empty();
    int colisionesInsert();
    int colisionesAt();
};
#endif