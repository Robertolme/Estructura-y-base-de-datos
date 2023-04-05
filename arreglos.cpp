#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <locale>
#include <wchar.h> 

using namespace std;

typedef struct {
	int max;
	int n;
	int *a;
} arreglo;


void creaMapa(int n, int a[]) {
	for (int i = 0; i < n; i++)
		a[i] = 0; // i no esta
}

void agregaMapa(int a[], int x) {
	a[x] = 1; // esto puede fallar
}

void eliminaMapa(int n, int a[], int x) {
	a[x] = 0; // esto puede fallar
}

int enMapa(int a[], int x) {
	return a[x]; // esto puede fallar
}



arreglo creaArreglo(int max){
	arreglo s;
	s.a = (int *) malloc(max*sizeof(int));
	s.max = (s.a != NULL) ? max : 0;
	s.n = 0;
	return s;
}

void destruyeArreglo(arreglo *s){
	free(s->a);
	s->a = NULL; 
	s->max = 0;
	s->n = 0;
}

int enArrDes(arreglo s, int x){
	for (int i=0; i<s.n; i++){
		if (s.a[i] == x){
			return i;
		}
	}
	return -1;
}



int impArr(arreglo s){
	cout << "{";
	int i;
	for (i=0; i<s.n-1; i++){
		//cout << (s.a[i]).ToString(" 00,");
		cout << setfill(' ') << setw(3) << s.a[i] << ',';
	}
	cout << setfill(' ') << setw(3) << s.a[i];
	cout << " }\n";
}


bool agregaArrDes(arreglo *s, int x){
	if (enArrDes(*s, x) >= 0)
		return 1;
	if (s->n < s->max ){
		s->a[s->n] = x;
		s->n++;
		return 1;
	} else return 0;
}


bool eliminaArrDes(arreglo *s, int x){
	int i = enArrDes(*s, x);
	if(i >= 0){
		s->n--;
		s->a[i] = s -> a[s->n];
		return 1;
	} 
	else return 0;
}

bool subArrDes(arreglo s, arreglo t){
	for (int i = 0; i < s.n; i++){
		if(enArrDes(t, s.a[i]) < 0){
			return 0;
		}
	return 1;
	}
}


main (){
	
	setlocale(LC_ALL, "");
	

	
	return 0;
}
