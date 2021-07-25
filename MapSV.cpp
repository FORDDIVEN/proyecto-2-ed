#include "MapSV.h"

MapSV::MapSV()
{
    _size = 0;
    arreglo = new vector<pair<string, int> >;
    colisionAT = 0;
    colisionINSERT = 0;
}
MapSV::~MapSV()
{
    delete[] arreglo;
}

void MapSV::insert(pair<string, int> palabrota)
{
    //meter al ultimo y luego hacer ordenamiento
    //arreglo->push_back(entrada);//como es un vector de pares solo basta con poner el par al ultimo
    int numerin = rand() % 100;

    arreglo->push_back(palabrota);
    _size++;

    int i = 0;
    int j = arreglo->size() - 1;

    int comparacion = 0;

    while (i < arreglo->size())
    {
        comparacion = mayorMenor(i, j);

        if (comparacion > 0)
        {
            swap(arreglo->at(i), arreglo->at(j));
        }
        else
        {
            i++;
        }
    }
}

void MapSV::erase(string palabrin)
{
    //BUSCAAR POSICION Y SOLO PONER CARACTER RARO :D usando AT
    int posicion = pos(palabrin);
    if (posicion != -1)
    {
        arreglo->at(posicion).first = '#';
        arreglo->at(posicion).second = -2;
        _size--;
    }
}

int MapSV::at(string palabrita)
{
    //busqueda binaria para encontrar n
    int up = arreglo->size() - 1;
    int down = 0;
    int posActual;
    int buscacion = 0;

    while (down <= up)
    {

        posActual = (up + down) / 2;
        buscacion = metodoPalAt(posActual, palabrita);

        if (buscacion == 0)
        {
            return arreglo->at(posActual).second;
        }

        if (buscacion < 0)
        { ///REVISAR PARA LA DERECHA PORQUE PALABRITA ES MAYOR
            down = posActual + 1;
        }

        if (buscacion > 0)
        {
            up = posActual - 1;
        }
    }
    return -1;
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
int MapSV::colisionesAt()
{
    return colisionAT;
}
int MapSV::colisionesInsert()
{
    return colisionINSERT;
}

int MapSV::mayorMenor(int primero, int segundo)
{

    char original[arreglo->at(primero).first.length()];
    char revisar[arreglo->at(segundo).first.length()];

    int comparar = 0;

    for (int i = 0; i < arreglo->at(primero).first.length(); ++i)
    {
        original[i] = arreglo->at(primero).first[i];
    }

    for (int i = 0; i < arreglo->at(segundo).first.length(); ++i)
    {
        revisar[i] = arreglo->at(segundo).first[i];
    }

    comparar = strcmp(original, revisar);
    return comparar;
}

int MapSV::metodoPalAt(int primero, string palabrin)
{

    char original[arreglo->at(primero).first.length()];
    char revisar[palabrin.length()];

    int comparar;

    for (int i = 0; i < arreglo->at(primero).first.length(); ++i)
    {
        original[i] = arreglo->at(primero).first[i];
    }

    for (int i = 0; i < palabrin.length(); ++i)
    {
        revisar[i] = palabrin[i];
    }

    comparar = strcmp(original, revisar);
    return comparar;
}

int MapSV::pos(string palabrita)
{
    //busqueda binaria para encontrar n
    int up = arreglo->size() - 1;
    int down = 0;
    int posActual;
    int buscacion = 0;

    while (down <= up)
    {

        posActual = (up + down) / 2;
        buscacion = metodoPalAt(posActual, palabrita);

        if (buscacion == 0)
        {
            return posActual;
        }

        if (buscacion < 0)
        { ///REVISAR PARA LA DERECHA PORQUE PALABRITA ES MAYOR
            down = posActual + 1;
        }

        if (buscacion > 0)
        {
            up = posActual - 1;
        }
    }
    return -1;
}
void MapSV::imprimir()
{
    int si = arreglo->size();
    for (int i = 0; i < si; i++)
    {
        cout << "" << arreglo->at(i).first;
        //cout << " " << arreglo->at(i).second;
        cout << "----";
    }
}