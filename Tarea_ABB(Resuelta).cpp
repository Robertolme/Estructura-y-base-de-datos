#include <iostream>

using namespace std;

typedef struct nodoABB
{
	int a;
	struct nodoABB *izq;
	struct nodoABB *der;
} nodoABB;

typedef nodoABB *abb;

nodoABB *creaNodoABB(int x){
	nodoABB *t = (nodoABB *)malloc(sizeof(nodoABB));

	if(t == NULL){
		cout<<"Error al crear nodoABB\n";
		exit(0);
	}

	t->a = x;
	t->izq =NULL;
	t->der = NULL;

	return t;
}



bool buscaABB(abb s, int x){
	while(s != NULL){
		if(s->a > x)
			s = s->izq;
		else if(s->a < x)
			s = s->der;
		else return 1;
	}
	return 0;
}

abb *buscarABB(abb *s, int x){
	while(*s != NULL){
		if( (*s)->a > x)
			s = &((*s)->izq);
		else if((*s)->a < x)
			s = &((*s)->der);
		else return s;
	}
	return s;
}

void procesa(abb s){
	cout<<s->a<<endl;
}

void ordenarABB(abb s){
	if(s != NULL){
		ordenarABB(s->izq);
		procesa(s);
		ordenarABB(s->der);
	}
}



void insertaABB(abb *p, int x){
    p = buscarABB(p, x);
    if (*p == NULL) {
        *p = creaNodoABB(x);
    }
}

int main(int argc, char const *argv[])
{
	nodoABB *p = creaNodoABB(5);
	insertaABB(&p,3);
	insertaABB(&p,4);
	insertaABB(&p,5);
	insertaABB(&p,7);
	insertaABB(&p,9);
	insertaABB(&p,1);
	insertaABB(&p,6);
	insertaABB(&p,8);
    ordenarABB(p);
	return 0;
}
