#ifndef AVLMAP_H
#define AVLMAP_H

#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include "Map.h"

using namespace std;

class AVLMap : public Map{
private:
    Nodo* root;
    int mysize;

public:
    AVLMap();
    ~AVLMap();
    void insert(pair<string,int> par);
    void erase(string s);
    int at(string s);
    int size();
    bool empty();

    Nodo* erase(string s, Nodo* nodo);                  //erase recursivo
    Nodo* insert(pair<string,int> par, Nodo* nodo);     //insert recursivo 
    int at(Nodo* nodo, string s);                       //at recursivo


    Nodo* giroDerecha(Nodo *y);
    Nodo* giroIzquierda(Nodo *x);
    Nodo* crearNodo(pair<string,int> par);
    Nodo* getRoot();
    int calcularAltura(Nodo *nodo);
    int calcularBalance(Nodo *nodo);
    void printPreOrder(Nodo *root);
    
    
};
#endif