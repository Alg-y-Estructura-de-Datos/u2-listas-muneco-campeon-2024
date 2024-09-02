#include <iostream>
#include <string>
#include "Lista.h"
#include <cctype> 

using namespace std;

bool esVocal(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int contarVocal(Lista<char>& lista, char vocal) {
    int contador = 0;
    for (int i = 0; i < lista.getTamanio(); i++) {
        if (tolower(lista.getDato(i)) == tolower(vocal)) {
            contador++;
        }
    }
    return contador;
}

int main() {
    Lista<char> lista;
    string frase;
    char vocal;

    cout << "Ingrese una palabra o frase: "<< endl;
    cin >> frase;

    for (int i = 0; i < (frase.length()); ++i) {
        lista.insertarUltimo(frase[i]);
        cout << lista.getDato(i)<< endl;
    }

    while (lista.esVacia()) {
        cout << "La lista esta vacia. No hay nada que contar." << endl;

        cout << "Ingrese una palabra o frase: "<< endl;
        cin >> frase;

        for (int i = 0; i < frase.length(); ++i) {
            lista.insertarUltimo(frase[i]);
            cout << lista.getDato(i)<< endl;
        }
    }

    cout << "Ingrese una vocal para contar en la frase: ";
    cin >> vocal;

    while (!esVocal(vocal))
    {
        cout << "El caracter ingresado no es una vocal." << endl;

        cout << "Ingrese una vocal para contar en la frase: ";
        cin >> vocal;
    }

    cout << "Lista: "<< endl;
    lista.print();

    int cantidad = contarVocal(lista, vocal);

    cout << "La '" << vocal << "' aparece " << cantidad << " veces ." << endl;

    return 0;
}