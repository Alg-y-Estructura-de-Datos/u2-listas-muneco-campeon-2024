#include <iostream>
#include "Lista/Lista.h"
#include <limits>

using namespace std;

Lista<int> encontrarRepetidos(Lista<int>& L1) {
    Lista<int> L2;
    Lista<int> yaVistos;
    Lista<int> repetidos;

    for (int i = 0; i < L1.getTamanio(); i++) {
        int valor = L1.getDato(i);
        bool yaVisto = false;
        bool esRepetido = false;

        for (int j = 0; j < yaVistos.getTamanio(); j++) {
            if (yaVistos.getDato(j) == valor) {
                yaVisto = true;
                break;
            }
        }

        if (yaVisto) {
            for (int j = 0; j < repetidos.getTamanio(); j++) {
                if (repetidos.getDato(j) == valor) {
                    esRepetido = true;
                    break;
                }
            }

            if (!esRepetido) {
                L2.insertarUltimo(valor);
                repetidos.insertarUltimo(valor);
            }
        } else {
            yaVistos.insertarUltimo(valor);
        }
    }

    return L2;
}

int main() {
    Lista<int> L1;
    int n, d;

    cout<<"Ingrese el tamanio de la Lista1: ";
    cin>>n;

    while(n<=0){ 
        cout << "El tamanio de la lista debe ser mayor a 0." << endl;
        cin>>n;
    }

    for (int i = 0; i < n; i++) {
        cout<<"Ingrese el valor de la lista en la posicion: "<<i+1<<endl;
        cin>>d;
        L1.insertarUltimo(d);
    }

    if (L1.esVacia()) {
        cout << "La lista está vacía. No se pueden encontrar elementos repetidos." << endl;
        return 0;
    }

    Lista<int> L2 = encontrarRepetidos(L1);

    cout << "Lista L1: ";
    L1.print();

    if (L2.esVacia()) {
        cout << "No hay elementos repetidos en L1." << endl;
    } else {
        cout << "Elementos repetidos: ";
        L2.print();
    }

    return 0;
}