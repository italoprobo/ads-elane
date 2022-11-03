#include "lista.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main(){

    Lista lista = NULL;
    
    int x = 0;

    while(x != -1){
        scanf("%d", &x);
        inserir_ordenado(x, &lista);
    }  
    
    exibir_inverso(lista);
    return 0;
}