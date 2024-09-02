#include <iostream>
#include "Lista.h"

using namespace std;

void printLista(Lista<int>& lista, int p) {
    int tamanio = lista.getTamanio();

    if (p >= tamanio || p < 0) {
        cout << "La posicion " << p << " esta fuera de los limites de la lista." << endl;
        return;
    }

    for (int i = p; i < tamanio; i++) {
        cout << lista.getDato(i) << "->";
    }
    cout << "NULL" << endl;
}


int main() {
    Lista<int> Lista1;
    int n, d, p;

    cout<<"Ingrese el tamano de la Lista1: ";
    cin>>n;

    while(n<=0){ 
        cout << "El tamanio de la lista debe ser mayor a 0." << endl;
        cin>>n;
    }

    for (int i = 0; i < n; i++) {
        cout<<"Ingrese el valor de la lista en la posicion: "<<i+1<<endl;
        cin>>d;
        Lista1.insertarUltimo(d);
    }

    cout<<"Ingrese la posicion desde donde desea imprimir la Lista1: "<<endl;
    cin>>p;

    printLista(Lista1, p);

    return 0;
}