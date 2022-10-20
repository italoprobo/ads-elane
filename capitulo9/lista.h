#include <stdio.h>
#include <stdlib.h>


#define fmt "%d"
typedef int Item;
typedef struct no{
    Item item;
    struct no *prox;
    
} *Lista;

/* Lista no(Item x, Lista p) {
    Lista n = malloc(sizeof(struct no));
    n->item = x;
    n->prox = p;
    return n;
} */

void exibir(Lista L) {
    while( L != NULL ) {
        printf(fmt, L->item);
        L = L->prox;
    }
}


/* void tam(Lista L) {
    if( L == NULL ) return 0;
    return 1 + tam(L->prox);
} */


Lista incluir(Item x, Lista list) {
    Lista nova = (Lista)malloc(sizeof(Lista));
    nova->item = x;
    nova->prox = list;
    return nova;
}


int ocorrencia(Item x, Lista list){
    int count = 0;
    while (list != NULL) {
        if (list->item == x){
            count++;
        } 
        list = list->prox;
    }
    return count;
}


Item ultimo(Lista list){

    while(list != NULL){
        if(list->prox == NULL){
            return list->item;
        }
        list = list->prox;
    }

}


int soma(Lista list){

    if (list != NULL) {
        return list->item + soma(list->prox);
    } 
    else {
        return 0;
    }

}


bool substitui(Item x, Item y, Lista list){

    if (list == NULL){
        return -1;
    }else {
        if(list->item == x){
            list->item = y;
        }
        return substitui(x,y,list);
    }
    return false;
}