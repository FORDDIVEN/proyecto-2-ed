#include <iostream>
#include <vector>
#include "MapH.h"
#include <fstream>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));
    MapDH *h = new MapH(9973);

    int a;
    cout << "Ingresar numero de palabras: ";
    cin >> a;
    int contador = 0;
<<<<<<< HEAD
    ifstream f("randomWords.txt");
=======
    int falsa;
    //hola D:
    ifstream f("randomWords.txt");
    //Parece que funciono
>>>>>>> 4ca45e1881cc41da85b8c0dd88c3c35806ae0339
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

        //cout << " DH: " << dobleH << endl;

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