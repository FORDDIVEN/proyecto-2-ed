#include "MapSV.h"

MapSV::MapSV()
{

    _size = 0;
    arreglo = new vector<pair<string, int>>;
}
MapSV::~MapSV()
{
    delete[] arreglo;
}

void MapSV::insert(int n)
{
}

void MapSV::erase(int n)
{
}
int MapSV::at(int n)
{
}
int MapSV::size()
{
    return _size;
}
bool MapSV::empty()
{
    if (_size > 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}