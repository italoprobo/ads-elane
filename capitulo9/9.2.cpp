#include "lista.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    Lista lista;
    lista = incluir(4, incluir(4, incluir(4, incluir(7, NULL))));

/*     for(Lista i = lista; i != NULL; i = i->prox){
    cout<< i->item << endl;
    } */

/*     while(lista != NULL){
        cout<< lista->item << endl;
        lista = lista->prox;
    } */

    cout<< ocorrencia(7, lista); 
}