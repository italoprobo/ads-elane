#include "lista.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    Lista lista;
    lista = incluir(4, incluir(4, incluir(4, incluir(7, NULL))));

    cout << ultimo(lista);
}