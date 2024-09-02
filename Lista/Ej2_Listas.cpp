#include <iostream>
#include "Lista.h"

using namespace std;

void printLista(Lista<int>& lista) {
    int tamanio = lista.getTamanio();

    for (int i = 0; i < tamanio; i++) {
        if(i==tamanio-1){
            cout << lista.getDato(i) << ".";
            return;
        }
        cout << lista.getDato(i) << "->";
    }
}

void cambiarLista(Lista<int>& lista, int p) {
    int tamanio = lista.getTamanio();

    for (int i = 0; i < tamanio; i++) {
        if (lista.getDato(i)==p){
            lista.remover(i);
            tamanio=tamanio-1;
        }
    }
}

int main(){
    Lista<int> Lista1;
    int n, d, p;

    cout<<"Ingrese el tamanio de la Lista1: ";
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

    cout << "Ingrese el numero a borrar: " << endl;
    cin >> p;

    cout << "Lista original:" << endl;
    printLista(Lista1);

    cout << "\n-----------------" << endl;

    cout << "Lista cambiada:" << endl;
    cambiarLista(Lista1, p);
    printLista(Lista1);

    return 0;
}