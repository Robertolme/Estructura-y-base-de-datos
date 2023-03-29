#include <iostream>

using namespace std;

int minimo(int n, int a[]){
    int m = 0;
    for(int i=1; i<n; i++)
        if(a[i]<a[m])
            m=i;
    return m;
}

int main(){
    int a[10] = {2,60,7,8,0,5,20,6,1,31};

    cout<<"minimo: "<<a[minimo(10,a)]<<" en la posicion "<<minimo(10,a);

    return 0;
}
