#include <iostream>
#include "Lista.h"

using namespace std;

void cambiarlistas(Lista<int>& Lista1, Lista <int >& Lista2){
    Lista<int> aux1, aux2;
    int tamanio1= Lista1.getTamanio();
    int tamanio2= Lista2.getTamanio();

    for(int i=0; i<tamanio1; i++){
        int a=Lista1.getDato(i);
        aux1.insertarUltimo(a);
    }

    for(int i=0; i<tamanio2; i++){
        int a=Lista2.getDato(i);
        aux2.insertarUltimo(a);
    }

    Lista1.vaciar();
    Lista2.vaciar();

    for(int i=0; i<tamanio2; i++){
        int a=aux2.getDato(i);
        Lista1.insertarUltimo(a);
    }

    for(int i=0; i<tamanio1; i++){
        int a=aux1.getDato(i);
        Lista2.insertarUltimo(a);
    }    

}

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

int main(){
    Lista<int> Lista1;
    Lista<int> Lista2;
    
    int n, m, d, p;

    cout<<"Ingrese el tamanio de la Lista1: ";
    cin>>n;


    while(n<=0){ 
        cout << "El tamanio de la lista 1 debe ser mayor a 0." << endl;
        cin>>n;
    }
    

    for (int i = 0; i < n; i++) {
        cout<<"Ingrese el valor de la lista 1 en la posicion: "<<i+1<<endl;
        cin>>d;
        Lista1.insertarUltimo(d);
    }

    cout<<"Ingrese el tamanio de la Lista2: ";
    cin>>m;

    while(m<=0){ 
        cout << "El tamanio de la lista 2 debe ser mayor a 0." << endl;
        cin>>m;
    }

    for (int i = 0; i < m; i++) {
        cout<<"Ingrese el valor de la lista 2 en la posicion: "<<i+1<<endl;
        cin>>p;
        Lista2.insertarUltimo(p);
    }

    cout << "Lista 1:" << endl;
    printLista(Lista1);

    cout << "\nLista 2:" << endl;
    printLista(Lista2);

    cout << "\n-----------------" << endl;

    cout << "Lista cambiada:" << endl;
    
    cambiarlistas(Lista1, Lista2);

    cout << "Lista 1:" << endl;
    printLista(Lista1);

    cout << "\nLista 2:" << endl;
    printLista(Lista2);


    return 0;
}