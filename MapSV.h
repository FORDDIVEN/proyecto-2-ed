#include <iostream>
#include <vector>

using namespace std;

class MapSV
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