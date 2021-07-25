#include "AVLMap.h"

AVLMap::AVLMap(){
    root = NULL;
	mysize = 0;
}
AVLMap::~AVLMap(){
    //delete[] arreglo;
}


void AVLMap::insert(pair<string,int> par){
	//cout<<"AAA"<<endl;
	root = insert(par, root);
}

Nodo* AVLMap::insert(pair<string,int> par, Nodo* nodo){
	if(nodo == NULL){
		return crearNodo(par);
	}
	if(par.first < nodo->par.first){			//insertar en el hijo de la izquierda;
		nodo->leftChild = insert(par, nodo->leftChild);
	}else if(par.first > nodo->par.first){		//insertar en el hijo de la derecha;
		nodo->rightChild = insert(par, nodo->rightChild);
	}else{
		//cout<<"no se admiten claves repetidas"<<endl;
		return nodo;
	}
	
	nodo->altura = max(calcularAltura(nodo->leftChild), calcularAltura(nodo->rightChild)) + 1;
	int balance = calcularBalance(nodo);
	
	if(balance>1){																//giros izq + ...
		if(par.first < nodo->leftChild->par.first) return giroDerecha(nodo);	//... izq
		if(par.first > nodo->leftChild->par.first){								//... der
			nodo->leftChild = giroIzquierda(nodo->leftChild);
			return giroDerecha(nodo);
		}
	}
	if(balance<-1){																//giros der + ...
		if(par.first > nodo->rightChild->par.first) return giroIzquierda(nodo);	//... der
		if(par.first < nodo->rightChild->par.first){							//... izq
			nodo->rightChild = giroDerecha(nodo->rightChild);
			return giroIzquierda(nodo);
		}
	}
	mysize++;
	return nodo;	
}


void AVLMap::erase(string s){
	root = erase(s, root);
}

Nodo* AVLMap::erase(string s, Nodo* nodo){
	cout<<"F"<<endl;
}

void AVLMap::printPreOrder(Nodo *root){
	if(root != NULL){
		cout << root->par.first<< ":"<< root->par.second<<" ";
		printPreOrder(root->leftChild);
		printPreOrder(root->rightChild);
	}
}

int AVLMap::at(string s){
	int ret = at(root, s);
	return ret;
}

int AVLMap::at(Nodo* root, string s){
	if(root != NULL){
		if(root->par.first == s) return root->par.second;
		else if(root->par.first > s){
			return at(root->leftChild,s);
		}else if(root->par.first < s){
			return at(root->rightChild,s);
		}
	}
	return -1;
}

int AVLMap::calcularAltura(Nodo *N){
	if (N == NULL)
		return 0;
	return N->altura;
}


Nodo* AVLMap::crearNodo(pair<string,int> par){
	Nodo* nodo = new Nodo();
	nodo->par = par;
	nodo->leftChild = NULL;
	nodo->rightChild = NULL;
	nodo->altura = 1;
	return(nodo);
}


Nodo* AVLMap::giroDerecha(Nodo *upper){
	Nodo *mid = upper->leftChild;
	Nodo *lower = mid->rightChild;
	mid->rightChild = upper;
	upper->leftChild = lower;
	upper->altura = max(calcularAltura(upper->leftChild), calcularAltura(upper->rightChild)) + 1;
	mid->altura = max(calcularAltura(mid->leftChild), calcularAltura(mid->rightChild)) + 1;
	
	return mid;
}

Nodo* AVLMap::giroIzquierda(Nodo *upper){
	Nodo* mid = upper->rightChild;
	Nodo* lower = mid->leftChild;
	mid->leftChild = upper;
	upper->rightChild = lower;
	upper->altura = max(calcularAltura(upper->leftChild), calcularAltura(upper->rightChild)) + 1;
	mid->altura = max(calcularAltura(mid->leftChild), calcularAltura(mid->rightChild)) + 1;

	return mid;
}


int AVLMap::calcularBalance(Nodo *nodo){
	if (nodo == NULL){
		return 0;
    }
	return calcularAltura(nodo->leftChild) - calcularAltura(nodo->rightChild);
}


Nodo* AVLMap::getRoot(){
	return root;
}

int AVLMap::size(){
	return mysize;
}
bool AVLMap::empty(){
	if(mysize==0)return true;
	else return false;
}