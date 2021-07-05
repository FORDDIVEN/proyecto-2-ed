#include "MapH.h"

MapH::MapH(int n)
{
    this->n = n / 2;
    _size = 0;
    hashTable = new vector<pair<string, int>>(n, make_pair(string(), int()));
    this->colisionAt = 0;
    this->colisionInsert = 0;
}

MapH::~MapH()
{
    delete[] hashTable;
}

void MapH::insert(pair<string, int> entrada)
{
    int hashing = polinomialHash(entrada.first);

    int hashingComprimido = comprimir(hashing);

    int inicioHashing = hashingComprimido;
    int rehashing = superPolinomialHash(hashing);

    int vuelta = 0;

    float factorCarga = _size / n;
    if (factorCarga > 0.5 || hashingComprimido > n) //REVISA QUE ESTE HASTA LA MITAD LLENA LA TABLA SI NO RE-SIZE
    {
        agrandar();
    }
    while (hashingComprimido < n)
    {
        if (hashTable->at(hashingComprimido).first == entrada.first)
        {
            break;
        }
        if (hashTable->at(hashingComprimido).first == string() || hashTable->at(hashingComprimido).first == "#")
        {
            hashTable->at(hashingComprimido).first = entrada.first;
            hashTable->at(hashingComprimido).second = entrada.second;
            _size++;
            break;
        }
        else
        {
            if (hashingComprimido + rehashing > n - 1)
            {
                hashingComprimido = (hashingComprimido + rehashing) - n;
                vuelta++;
                colisionInsert++;
            }
            else
            {
                hashingComprimido += rehashing;
                colisionInsert++;
            }
        }
        if (vuelta != 0 && hashingComprimido == inicioHashing)
        {
            break;
        }
    }
}

void MapH::erase(string palabra)
{
    int revisar = pos(palabra);
    if (revisar != -1)
    {
        _size--;
        hashTable->at(revisar).first = "#"; //dejo un caracter cualquiera para hacer un borrado simbolico
        hashTable->at(revisar).second = -2;
    }
    else
    {
        cout << "No se puede borrar elemento inexistente" << endl;
    }
}

int MapH::at(string palabra) //RETORNA VALOR GUARDADO NO LA POSICION!!
{

    int hashing = polinomialHash(palabra);

    int hashingComprimido = comprimir(hashing);

    int inicioHashing = hashingComprimido;
    int rehashing = superPolinomialHash(hashing);

    int retorno = -1;
    int vuelta = 0;

    while (hashingComprimido < n)
    {
        if (hashTable->at(hashingComprimido).first == palabra)
        {
            return hashTable->at(hashingComprimido).second;
            break;
        }
        else
        {
            if (hashingComprimido + rehashing > n - 1)
            {
                hashingComprimido = (hashingComprimido + rehashing) - n;
                vuelta++;
                colisionAt++;
            }
            else
            {
                hashingComprimido += rehashing;
                colisionAt++;
            }
        }
        if (vuelta != 0 && hashingComprimido == inicioHashing)
        {
            break;
        }
    }

    return retorno;
}

int MapH::size()
{
    return _size;
}

bool MapH::empty()
{
    if (_size == 0)
        return true;
    else
        return false;
}

int MapH::pos(string palabrota) //RETORNA LA POSICION!!
{
    int hashing = polinomialHash(palabrota);

    int hashingComprimido = comprimir(hashing);

    int inicioHashing = hashingComprimido;
    int rehashing = superPolinomialHash(hashing);

    string probar;

    int retorno = -1;
    int vuelta = 0;

    while (hashingComprimido < n)
    {
        if (hashTable->at(hashingComprimido).first == palabrota)
        {
            return hashingComprimido;
            break;
        }
        else
        {
            if (hashingComprimido + rehashing > n - 1)
            {
                hashingComprimido = (hashingComprimido + rehashing) - n;
                vuelta++;
            }
            else
            {
                hashingComprimido += rehashing;
            }
        }
        if (vuelta != 0 && hashingComprimido == inicioHashing)
        {
            break;
        }
    }

    return retorno;
}
int MapH::polinomialHash(string palabra)
{
    int sizeWord = palabra.length();
    int sumHash = 0;
    //int Z = 33; numero muy grande se desborda y dara numeros negativos
    int Z = 7;
    for (int i = 0; i < sizeWord; i++)
    {
        sumHash += (int)palabra[i] * pow(Z, i);
    }
    return sumHash;
}

void MapH::agrandar()
{
    n = 2 * n;
    vector<pair<string, int>> *newHash;
    newHash = new vector<pair<string, int>>(n, make_pair(string(), int()));
    int hashing;
    // int inicioHashing = hashing;

    for (int i = 0; i < n / 2; i++)
    {
        if (hashTable->at(i).first != string() && hashTable->at(i).first != "#")
        {
            hashing = polinomialHash(hashTable->at(i).first); //posicion donde insetar dato
            if (newHash->at(hashing).first == string())
            {
                newHash->at(hashing).first = hashTable->at(i).first;
                newHash->at(hashing).second = hashTable->at(i).second;
            }
            else
            {
                for (int j = hashing + 1; j < n; j++)
                {
                    if (newHash->at(j).first == string())
                    {
                        newHash->at(j).first = hashTable->at(i).first;
                        newHash->at(j).second = hashTable->at(i).second;
                        break;
                    }
                    if (j == n - 1)
                    {
                        j = 0;
                    }
                    if (j + 1 == hashing)
                    {
                        break;
                    }
                }
            }
        }
    }
    delete hashTable;
    hashTable = newHash;
}

int MapH::superPolinomialHash(int n)
{
    int retorno = 7 - (n % 7);
    return retorno;
}

int MapH::colisionesInsert()
{
    return colisionInsert;
}

int MapH::colisionesAt()
{
    return colisionAt;
}

int MapH::comprimir(int hash)
{
    return hash % n;
}