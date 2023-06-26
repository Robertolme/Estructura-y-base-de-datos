#include <iostream>
#include <iomanip>

using namespace std;


class grafica{
    public:
        grafica(int n);
        void crearMatriz();
      	~grafica();
        void  muestraGrafica();
        void agregarAristas(int , int);
        void eliminarAristas(int, int);
        bool sonVecinos(int, int);
        int grado(int);
    private:
        int n;
    	bool **a; //mapa de bits
};

grafica::grafica(int n){
	this->n = n;
	crearMatriz();
}

grafica::~grafica(){
	for (int i = 0; i < this->n; i++) {
        delete[] a[i];
    }
    delete[] a;
}

void grafica::crearMatriz(){
	a = new bool*[this->n];
	for (int i = 0; i < this->n; i++) {
        a[i] = new bool[this->n];
    }

    for (int i = 0; i < this->n; i++)
        for (int j = 0; j < this->n; j++) 
			a[i][j] = 0;            
}

void grafica::muestraGrafica(){
	cout << "-----";
    for (int j = 0; j < this->n; j++)
        cout << setw(4) << j + 1 << " ";
    cout << endl;

    for (int i = 0; i < this->n; i++) {
        cout << "-----";
        for (int j = 0; j < this->n; j++)
            cout << "-----";
        cout << "-" << endl;

        cout << "| " << setw(2) << i + 1 << " "; 
        for (int j = 0; j < this->n; j++) 
            cout << "| " << setw(2) << a[i][j] << " ";
        cout << "|" << endl;
    }

    cout << "-----"; 
    for (int j = 0; j < this->n; j++) 
        cout << "-----";
    cout << "-\n\n";

}

void grafica::agregarAristas(int u, int v){
	if(0 <= u && u < this->n && 0 <= v && v < this->n && u!=v)
		a[u][v] = a[v][u] = 1;
}

void grafica::eliminarAristas(int u, int v){
	if(0 <= u && u < this->n && 0 <= v && v < this->n)
		a[u][v] = a[v][u] = 0;
}

bool grafica::sonVecinos(int u, int v){
	return this->a[u][v];
}

int grafica::grado(int u){
	int v, d = 0;

	for(v=0;v<this->n;v++)
		d+=a[u][v];
	return d;
}

int main(){
	grafica obj1(3);  //crea la grafica
	obj1.muestraGrafica(); 

	obj1.agregarAristas(0,1);
	obj1.muestraGrafica();

	cout<<"Son vecinos :"<<obj1.sonVecinos(1,0)<<endl;
	cout<<"Grado :"<<obj1.grado(1)<<endl<<endl;

	obj1.eliminarAristas(0,1);
	obj1.muestraGrafica();

	return 0;
}
