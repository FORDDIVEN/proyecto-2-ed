#include <iostream>
#include <vector>
#include "MapH.h"
#include <fstream>
#include <ctime>
#include "MapSV.h"
using namespace std;

int main()
{
    srand(time(NULL));
    MapH* hashing = new MapH(9973);
    MapSV* arreglo = new MapSV();
    AVLMap* avltree = new AVLMap();
    int nWords;
    cout << "Ingresar numero de palabras: ";
    cin >> nWords;

    int contador = 0;
    ifstream f("randomWords.txt");
    string palabra;
    contador = 0;
    int aux;
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
        arreglo->insert(tupla);
        avltree->insert(tupla);

        if (contador == nWords)
        {
            break;
        }
        contador++;
    }

    f.clear();
    f.seekg(0, f.beg);

    contador = 0;
    while (f >> palabra)
    {

        if (palabra.length() > 5)
        {
            palabra = palabra.substr(0, 5); //tomar desde a hasta b en mi palabra que es de 0 hasta 7 em este caso
        }
        int dobleH = hashing->at(palabra);
        int arreglin = arreglo->at(palabra);
        int atAvl = avltree->at(palabra);
        //cout << " DH: " << dobleH << endl;
        //cout << " arreglo at: " << arreglin << endl;

        if (contador == nWords)
        {
            break;
        }
        contador++;
    }



    //No es analisis de colisiones amigo, es de tiempo, el AVL ni siquiera puede tener colisiones


    /*
    cout << "At Hashing: " << hashing->colisionesAt() << endl;
    cout << "Insert Hashing: " << hashing->colisionesAt() << endl;

    cout << "At arreglo: " << arreglo->colisionesAt() << endl;
    cout << "Insert arreglo: " << arreglo->colisionesInsert() << endl;
    */

    return 0;
}