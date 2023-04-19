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

arreglo creaArreglo(int max){
	arreglo s;
	s.a = (int *) malloc(max*sizeof(int));
	s.max = (s.a != NULL) ? max : 0;
	s.n = 0;
	return s;
}

int enArrDes(arreglo s, int x){
	for (int i=0; i<s.n; i++){
		if (s.a[i] == x){
			return i;
		}
	}
	return -1;
}

int enArrOrd(arreglo s, int x){
	for (int i = 0; (i < s.n) && (s.a[i] <= x); i++){
		if(s.a[i] == x){
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

bool agregaArrOrd(arreglo *s, int x) {
	if (enArrOrd (*s, x) >= 0){
		return 1; // x ya estaba
	}
	if (s->n < s->max) { // si hay espacio
		int i = s->n;
		for (; i > 0 && s->a[i-1] > x; i--){
			s->a[i] = s->a[i-1]; // recorre los elementos
		}
	s->a[i] = x;
	s->n++;
	return 1;
	} else return 0;
}

bool agregaDescend(arreglo *s, int x) { //para resolver
/*	










*/
}

arreglo uneArrDes(arreglo s, arreglo t){
	arreglo u = creaArreglo(s.n + t.n);
	for (int i = 0; i < s.n; i++){
		agregaArrDes(&u, s.a[i]);
	}
	for (int i = 0; i < t.n; i++){
		agregaArrDes(&u, t.a[i]);
	}
	return u;
}

arreglo intersectaArrDes(arreglo s, arreglo t){
	arreglo u = creaArreglo((s.n < t.n) ? s.n : t.n);
	for (int i = 0; i < s.n; i++){
		if(enArrDes(t, s.a[i]) >= 0){
			u.a[u.n++] = s.a[i];
		}
	
	}
	return u;
}

arreglo diferenciaArrDes(arreglo s, arreglo t) {
/*    





*/
}

arreglo difsimArrDes(arreglo s, arreglo t) {
/*   










*/
}


main (){
	setlocale(LC_ALL, "");
	
	arreglo arrDes01 = creaArreglo(10);
	arreglo arrDes02 = creaArreglo(10);
	arreglo arrDes03 = creaArreglo(10);

	arreglo arrOrd01 = creaArreglo(10);
	arreglo arrOrd02 = creaArreglo(10);
	arreglo arrOrd03 = creaArreglo(10);

	agregaArrDes(&arrDes01, 6);
	agregaArrDes(&arrDes01, 3);
	agregaArrDes(&arrDes01, 9);
	agregaArrDes(&arrDes01, 2);
	
	agregaArrDes(&arrDes02, 4);
	agregaArrDes(&arrDes02, 5);
	agregaArrDes(&arrDes02, 8);
	agregaArrDes(&arrDes02, 1);
	
	agregaArrDes(&arrDes03, 0);
	agregaArrDes(&arrDes03, 9);
	agregaArrDes(&arrDes03, 2);
	agregaArrDes(&arrDes03, 7);

	agregaArrOrd(&arrOrd01, 6);
	agregaArrOrd(&arrOrd01, 3);
	agregaArrOrd(&arrOrd01, 9);
	agregaArrOrd(&arrOrd01, 2);
	
/*	DESCOMENTAR TRAS RESOLVER ------------------------------------------
	agregaDescend(&arrOrd02, 8);
	agregaDescend(&arrOrd02, 5);
	agregaDescend(&arrOrd02, 4);
	agregaDescend(&arrOrd02, 1);
*/
	cout << "Contenido del arreglo arrDes01:\n";
	impArr(arrDes01);
	
	cout << "Contenido del arreglo arrDes02:\n";
	impArr(arrDes02);
	
	cout << "Contenido del arreglo arrDes03:\n";
	impArr(arrDes03);

	cout << "Contenido del arreglo arrOrd01:\n";
	impArr(arrOrd01);
/*	DESCOMENTAR TRAS RESOLVER ------------------------------------------
	cout << "Contenido del arreglo arrOrd02 (Descend):\n";
	impArr(arrOrd02);
*/	
	arreglo unidos = uneArrDes(arrDes01, arrDes02);
	
	cout << "Contenido del arreglo unidos:\n";
	impArr(unidos);
	
	arreglo intersect = intersectaArrDes(arrDes01, arrDes03);
	cout << "Contenido de la intersección de arrDes01 y arrDes03:\n";
	impArr(intersect);
	
/*	DESCOMENTAR TRAS RESOLVER ------------------------------------------
	arreglo diff = diferenciaArrDes(arrDes01, arrDes03);
	cout << "Diferencia de los conjuntos arrDes01 \\ arrDes03:\n";
	impArr(diff);
*/
/* 	DESCOMENTAR TRAS RESOLVER ------------------------------------------
	arreglo diffsim = difsimArrDes(arrDes01, arrDes03);
	cout << "Diferencia simétrica de los conjuntos arrDes01 y arrDes03:\n";
	impArr(diffsim);
	*/
	
	return 0;
}
