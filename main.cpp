#include <iostream>
#include <vector>
#include "MapDH.h"
#include <fstream>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));
    MapDH *dh = new MapDH(9973);

    int a;
    cout << "Ingresar numero de palabras: ";
    cin >> a;
    int contador = 0;

    ifstream f("randomWords.txt");
    //hola 
    string palabra;
    contador = 0;
    int aux;
    while (f >> palabra)
    {
        aux = rand() % 100;
        pair<string, int> tupla;
        tupla.first = palabra;
        if (palabra.length() > 5)
        {
            tupla.first = palabra.substr(0, 5); //tomar desde a hasta b en mi palabra que es de 0 hasta 5 em este caso
        }
        dh->insert(tupla);

        if (contador == a)
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
        int dobleH = dh->at(palabra);

        //cout << "bad: " << bad << " good: " << good << " DH: " << dobleH << endl;

        if (contador == a)
        {
            break;
        }
        contador++;
    }

    cout << "Colisiones MapDH" << endl;
    cout << "Metodo At: " << dh->colisionesAt() << " Metodo Insert: " << dh->colisionesInsert() << endl;
    //cout << "" << endl;

    return 0;
}