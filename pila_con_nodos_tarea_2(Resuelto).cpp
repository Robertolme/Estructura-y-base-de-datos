#include <iostream>
using namespace std;

class Nodo
{
    public:
        Nodo(int dato, Nodo* siguiente = NULL);
        ~Nodo();
        void  muestraTusDatos(void);
        Nodo* dameTuSiguiente(void);
        int   dameTuDato(void);
        void  modificaTuDato(int dato);
        void  modificaTuSiguiente(Nodo* siguiente);

    private:
        int dato;
        Nodo* siguiente;
};

Nodo::Nodo(int dato, Nodo* siguiente)
{
	//constructor
    this->dato = dato;
    this->siguiente = siguiente;
}

Nodo::~Nodo()
{
    // destructor
}

void Nodo::muestraTusDatos()
{
    cout << this->dato << endl;
}

Nodo* Nodo::dameTuSiguiente()
{
    return this->siguiente;
}

int Nodo::dameTuDato()
{
    return this->dato;
}

void Nodo::modificaTuDato(int dato)
{
    this->dato = dato;
}

void Nodo::modificaTuSiguiente(Nodo* siguiente)
{
    this->siguiente = siguiente;
}

class Pila
{
    public:
        Pila();
        //~Pila();
        bool pilaVacia(void);
        void push(int dato);
        int  pop(void);
        int  cima(void);

    private:
        Nodo* tope;
};

Pila::Pila(){
	this->tope = new Nodo(0);
}


void Pila::push(int dato){
	this->tope = new Nodo(dato,this->tope);
}

int Pila::cima(){
	return this->tope->dameTuDato(); 
}

int Pila::pop(){
	int r = cima();
	if(pilaVacia()){
		this->tope = this->tope->dameTuSiguiente();
		return r;
	}	
	else{
		cout<<"La lista esta vacia"<<endl;
		exit(-1);
	}
	 
}

bool Pila::pilaVacia(void){
	if(this->tope->dameTuSiguiente() == NULL)
		return 0;
	else
		return 1;
}

int main()
{
	setlocale(LC_ALL, "");
    Pila pila;
    
	pila.push(1);
	cout << pila.cima() << endl;
	
	pila.push(2);
	cout << pila.cima() << endl;
	
	pila.push(3);
	cout << pila.cima() << endl;
	
	pila.push(4);
	cout << pila.cima() << endl;
	
	
	cout << pila.pop() << endl;
	cout << pila.pop() << endl;
	cout << pila.pop() << endl;
	cout << pila.pop() << endl;
	cout << pila.pop() << endl;

    return 0;
}

