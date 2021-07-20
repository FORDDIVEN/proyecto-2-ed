#include "MapSV.h"

MapSV::MapSV()
{
    _size = 0;
    arreglo = new vector<pair<string, int>>;
    colisionAT = 0;
    colisionINSERT = 0;
}
MapSV::~MapSV()
{
    delete[] arreglo;
}

void MapSV::insert(string palabrota)
{
    //meter al ultimo y luego hacer ordenamiento
    //arreglo->push_back(entrada);//como es un vector de pares solo basta con poner el par al ultimo
    int numerin = rand() % 100;

    arreglo->push_back(make_pair(palabrota, numerin));
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
    }
}

int MapSV::at(string palabrita)
{
    //busqueda binaria para encontrar n
    int posActual = size() / 2;
    int buscacion = 0;

    while (arreglo->at(posActual).first != palabrita)
    {
        buscacion = metodoPalAt(posActual, palabrita);

        if (buscacion < 0)
        {                               ///REVISAR PARA LA DERECHA PORQUE PALABRITA ES MAYOR
            posActual += posActual / 2; //lo hice yo, mala la cosita
            //posActual = posActual / 2;
        }

        if (buscacion > 0)
        {
            posActual -= posActual / 2;
        }
    }

    buscacion = metodoPalAt(posActual, palabrita);
    if (buscacion == 0)
    {
        return arreglo->at(posActual).second;
    }
    else
    {
        return -1;
    }
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

    int comparar;

    for (int i = 0; i < arreglo->at(primero).first.length(); ++i)
    {
        original[i] = arreglo->at(primero).first[i];
    }

    for (int i = 0; i < arreglo->at(segundo).first.length(); ++i)
    {
        revisar[i] = arreglo->at(segundo).first[i];
    }

    comparar = strcmp(original, revisar);

    if (comparar < 0)
    {
        printf("str1 is less than str2");
        return comparar;
    }
    else if (comparar > 0)
    {
        printf("str2 is less than str1");
        return comparar;
    }
    else
    {
        printf("str1 is equal to str2");
        return comparar;
    }
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

    if (comparar < 0)
    {
        printf("str1 is less than str2");
        return comparar;
    }
    else if (comparar > 0)
    {
        printf("str2 is less than str1");
        return comparar;
    }
    else
    {
        printf("str1 is equal to str2");
        return comparar;
    }
}

int MapSV::pos(string palabrita)
{
    //busqueda binaria para encontrar n
    int posActual = size() / 2;
    int buscacion = 0;

    while (arreglo->at(posActual).first != palabrita)
    {
        buscacion = metodoPalAt(posActual, palabrita);

        if (buscacion < 0)
        {                               ///REVISAR PARA LA DERECHA PORQUE PALABRITA ES MAYOR
            posActual += posActual / 2; //lo hice yo, mala la cosita
            //posActual = posActual / 2;
        }

        if (buscacion > 0)
        {
            posActual -= posActual / 2;
        }
    }

    buscacion = metodoPalAt(posActual, palabrita);
    if (buscacion == 0)
    {
        return posActual;
    }
    else
    {
        return -1;
    }
}