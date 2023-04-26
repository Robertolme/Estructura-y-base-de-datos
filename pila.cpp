#include<iostream>

using namespace std;

class Pila{
	public:
		Pila();
		~Pila();
		bool pilaVacia(void);
		void push(int dato);
		int pop(void);
		int cima(void);
	private:
		//Nodo* tope;
};

int main(){
    cout<<"hola mundo";
    return 0;
}
