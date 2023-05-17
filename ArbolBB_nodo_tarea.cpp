//tarea
#include <iostream>

using namespace std;

class Nodo
{
    public:
    	int dato;
    	Nodo* izq;
    	Nodo* der;

    	Nodo(int dato, Nodo* izq = NULL, Nodo* der = NULL);
    	~Nodo();
};

Nodo::Nodo(int dato, Nodo* izq, Nodo* der)
{
	//constructor
	this->dato = dato;
	this->izq = NULL;
    this->der = NULL;
}

Nodo::~Nodo()
{
    // destructor
}


class ArbolBB
{
    public:
        ArbolBB();
        ~ArbolBB();
    	void insertaABB(int dato);
    	bool buscaDato(int dato);
    	void borrarDato(int dato);


	private:
	    Nodo* root;
	    void acomodarABB(Nodo* nodo, int dato);
	    bool buscaABB(Nodo* nodo, int dato);
	    void borrarABB(Nodo* nodo, int dato);
	    Nodo* buscaMin(Nodo* nodo);

};

ArbolBB::ArbolBB() {
    this->root = NULL;
}

ArbolBB::~ArbolBB() {
    //destructor
}

void ArbolBB::insertaABB(int dato) {
    if (this->root == NULL ){
        root = new Nodo(dato);
        cout << "Se agregó el " << dato << endl;
    } else {
        acomodarABB(root, dato);
    }
}

void ArbolBB::acomodarABB(Nodo* nodo, int dato) {
    if (dato < nodo->dato) {
        if (nodo->izq == NULL) {
            nodo->izq = new Nodo(dato);
            cout << "Se agregó el " << dato << endl;
        } else {
            acomodarABB(nodo->izq, dato);
        }
    } else if (dato > nodo->dato) {
        if (nodo->der == NULL) {
            nodo->der = new Nodo(dato);
            cout << "Se agregó el " << dato << endl;
        } else {
            acomodarABB(nodo->der, dato);
        }
    } else{
    	cout << "Ya existe el " << dato << endl;
	}
}


bool ArbolBB::buscaDato(int dato) {
	cout << "Busca el " << dato << endl;
	if(buscaABB(root, dato)){
		cout << "Sí está el " << dato << endl;
		return true;
	}
	else{
		cout << "No está el " << dato << endl;
		return false;
	}
}

bool ArbolBB::buscaABB(Nodo* nodo, int dato) {
    if (nodo == NULL) {
    	return false;
	}
    if (nodo->dato == dato){
    	return true;
	}
    if (dato < nodo->dato){
    	cout << "izq" << endl;
    	return buscaABB(nodo->izq, dato);
	}
    else {
    	cout << "der" << endl;
    	return buscaABB(nodo->der, dato);
	}		
}

Nodo* ArbolBB::buscaMin(Nodo* nodo) {
        while (nodo->izq != NULL) {
            nodo = nodo->izq;
        }
        return nodo;
    }

void ArbolBB::borrarDato(int dato) {
	cout << "Se borró el " << dato << endl;
    borrarABB(root, dato);
}

void ArbolBB::borrarABB(Nodo* nodo, int dato) {
    if (nodo == NULL) 
		return;
    if (dato < nodo->dato) {
        borrarABB(nodo->izq, dato);
    } else if (dato > nodo->dato) {
        borrarABB(nodo->der, dato);
    } else {
        if (nodo->izq == NULL && nodo->der == NULL) {
// ¡Completar!
//
        } else if (nodo->izq != NULL && nodo->der == NULL) {
// ¡Completar!
//
//
        } else if (nodo->izq == NULL && nodo->der != NULL) {
// ¡Completar!
//
//
        } else {
// ¡Completar!
// tip, usar la función buscaMin(nodo->der) para reacomodar los nodos cuando 
// se borre un nodo con dos subsecuentes
        }
    }
}




int main()
{
	setlocale(LC_ALL, "");
	char opt;
	int num;
	ArbolBB arbolBB;
	
	do{
		system("cls");
		cout << "Arbol binario de búsqueda; 'i' para insertar, 'e' para eliminar, 'b' para buscar (s para salir):" << endl;
		cin >> opt;
		switch(opt){
			case 'i':
				cout << "Ingresa el número a insertar:" << endl;
				cin >> num;
				arbolBB.insertaABB(num);
				system("pause");
				break;
			case 'e':
				cout << "Ingresa el número a eliminar:" << endl;
				cin >> num;
				arbolBB.borrarDato(num);
				system("pause");
				break;
			case 'b':
				cout << "Qué número deseas buscar:" << endl;
				cin >> num;
				arbolBB.buscaDato(num);
				system("pause");
				break;

		}
		

	}
	while(opt != 's');

    
    return 0;
}

