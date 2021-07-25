#include <iostream>
#include <vector>
#include "MapH.h"
#include <fstream>
#include <ctime>
#include "MapSV.h"
#include "AVLMap.h"
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));
    double timeInsert;
    double timeAt;

    MapH *hashing = new MapH(120000);
    MapSV *arreglo = new MapSV();
    AVLMap *avltree = new AVLMap();

    int nWords;
    //cout << "" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Ingresar numero de palabras: ";
    cin >> nWords;
    cout << "----------------------------------------" << endl;

    int contador = 0;
    ifstream f("randomWords.txt");
    string palabra;
    int aux;
    int repeticiones = 1;

    //MIDIENDO TIEMPO INSERT PRIMERA IMPLEMENTACION - ARREGLO
    f.clear();
    f.seekg(0, f.beg);

    clock_t start = clock();
    for (int i = 0; i < repeticiones; i++)
    {
        contador = 0;
        while (f >> palabra)
        {
            aux = rand() % 100;
            pair<string, int> tupla;
            tupla.first = palabra;
            tupla.second = aux;
            if (palabra.length() > 5)
            {
                tupla.first = palabra.substr(0, 5); //tomar desde a hasta b en mi palabra que es de 0 hasta 5 em este caso
            }
            arreglo->insert(tupla);

            if (contador == nWords)
            {
                break;
            }
            contador++;
        }
    }
    timeInsert = ((double)clock() - start) / CLOCKS_PER_SEC;
    printf("Tiempo Insert Arreglo: %.10f\n\n", timeInsert / (double)repeticiones);

    f.clear();
    f.seekg(0, f.beg);

    //MIDIENDO TIEMPO INSERT SEGUNDA IMPLEMENTACION - HASHING

    start = clock();
    for (int i = 0; i < repeticiones; i++)
    {
        contador = 0;
        while (f >> palabra)
        {
            aux = rand() % 100;
            pair<string, int> tupla;
            tupla.first = palabra;
            tupla.second = aux;
            if (palabra.length() > 5)
            {
                tupla.first = palabra.substr(0, 5); //tomar desde a hasta b en mi palabra que es de 0 hasta 5 em este caso
            }
            hashing->insert(tupla);

            if (contador == nWords)
            {
                break;
            }
            contador++;
        }
    }
    timeInsert = ((double)clock() - start) / CLOCKS_PER_SEC;
    printf("Tiempo Insert Hashing: %.10f\n\n", timeInsert / (double)repeticiones);

    f.clear();
    f.seekg(0, f.beg);

    //MIDIENDO TIEMPO INSERT TERCERA IMPLEMENTACION - AVL-TREE

    start = clock();
    for (int i = 0; i < repeticiones; i++)
    {
        contador = 0;
        while (f >> palabra)
        {
            aux = rand() % 100;
            pair<string, int> tupla;
            tupla.first = palabra;
            tupla.second = aux;
            if (palabra.length() > 5)
            {
                tupla.first = palabra.substr(0, 5); //tomar desde a hasta b en mi palabra que es de 0 hasta 5 em este caso
            }
            avltree->insert(tupla);

            if (contador == nWords)
            {
                break;
            }
            contador++;
        }
    }
    timeInsert = ((double)clock() - start) / CLOCKS_PER_SEC;
    printf("Tiempo Insert AVL-Tree: %.10f\n", timeInsert / (double)repeticiones);

    f.clear();
    f.seekg(0, f.beg);

    cout << "----------------------------------------" << endl;

    //MIDIENDO TIEMPO METODO AT PRIMERA IMPLEMENTACION ARREGLO

    start = clock();
    for (int i = 0; i < repeticiones; i++)
    {
        contador = 0;
        while (f >> palabra)
        {

            if (palabra.length() > 5)
            {
                palabra = palabra.substr(0, 5); //tomar desde a hasta b en mi palabra que es de 0 hasta 7 em este caso
            }
            int arreglin = arreglo->at(palabra);

            if (contador == nWords)
            {
                break;
            }
            contador++;
        }
    }
    timeAt = ((double)clock() - start) / CLOCKS_PER_SEC;
    printf("Tiempo At Arreglo: %.10f\n\n", timeAt / (double)repeticiones);

    start = clock();
    for (int i = 0; i < repeticiones; i++)
    {
        contador = 0;
        while (f >> palabra)
        {

            if (palabra.length() > 5)
            {
                palabra = palabra.substr(0, 5); //tomar desde a hasta b en mi palabra que es de 0 hasta 7 em este caso
            }
            int arreglin = arreglo->at(palabra);

            if (contador == nWords)
            {
                break;
            }
            contador++;
        }
    }
    timeAt = ((double)clock() - start) / CLOCKS_PER_SEC;
    printf("Tiempo At Arreglo cuando no encuentra elemento: %.10f\n\n", timeAt / (double)repeticiones);

    f.clear();
    f.seekg(0, f.beg);

    //MIDIENDO TIEMPO SEGUNDA IMPLEMENTACION HASHING METODO AT

    start = clock();
    for (int i = 0; i < repeticiones; i++)
    {
        contador = 0;
        while (f >> palabra)
        {

            if (palabra.length() > 5)
            {
                palabra = palabra.substr(0, 5); //tomar desde a hasta b en mi palabra que es de 0 hasta 7 em este caso
            }
            int dobleH = hashing->at(palabra);

            if (contador == nWords)
            {
                break;
            }
            contador++;
        }
    }
    timeAt = ((double)clock() - start) / CLOCKS_PER_SEC;
    printf("Tiempo At Hashing: %.10f\n\n", timeAt / (double)repeticiones);

    start = clock();
    for (int i = 0; i < repeticiones; i++)
    {
        contador = 0;
        while (f >> palabra)
        {

            if (palabra.length() > 5)
            {
                palabra = palabra.substr(0, 5); //tomar desde a hasta b en mi palabra que es de 0 hasta 7 em este caso
            }
            int dobleH = hashing->at(palabra);

            if (contador == nWords)
            {
                break;
            }
            contador++;
        }
    }
    timeAt = ((double)clock() - start) / CLOCKS_PER_SEC;
    printf("Tiempo At Hashing cuando no encuentra elementos: %.10f\n\n", timeAt / (double)repeticiones);

    f.clear();
    f.seekg(0, f.beg);

    //MIDIENDO TIEMPO TERCERA IMPLEMENTACION AVL-TREE METODO AT

    start = clock();
    for (int i = 0; i < repeticiones; i++)
    {
        contador = 0;
        while (f >> palabra)
        {

            if (palabra.length() > 5)
            {
                palabra = palabra.substr(0, 5); //tomar desde a hasta b en mi palabra que es de 0 hasta 7 em este caso
            }
            int atAvl = avltree->at(palabra);

            if (contador == nWords)
            {
                break;
            }
            contador++;
        }
    }
    timeAt = ((double)clock() - start) / CLOCKS_PER_SEC;
    printf("Tiempo At AVL-Tree: %.10f\n", timeAt / (double)repeticiones);

    start = clock();
    for (int i = 0; i < repeticiones; i++)
    {
        contador = 0;
        while (f >> palabra)
        {

            if (palabra.length() > 5)
            {
                palabra = palabra.substr(0, 5); //tomar desde a hasta b en mi palabra que es de 0 hasta 7 em este caso
            }
            int atAvl = avltree->at(palabra);

            if (contador == nWords)
            {
                break;
            }
            contador++;
        }
    }
    timeAt = ((double)clock() - start) / CLOCKS_PER_SEC;
    printf("Tiempo At AVL-Tree cuando no encuentra elemento: %.10f\n", timeAt / (double)repeticiones);
    cout << "----------------------------------------" << endl;

    return 0;
}