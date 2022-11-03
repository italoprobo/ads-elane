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


void exibir_inverso(Lista list) {
    if( list == NULL) return;
    exibir_inverso(list->prox);
    printf(fmt, list->item);
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


/* Item ultimo(Lista list){

    while(list != NULL){
        if(list->prox == NULL){
            return list->item;
            break;
        }
        list = list->prox;
    }
} */


int soma(Lista list){

    if (list != NULL) {
        return list->item + soma(list->prox);
    } 
    else {
        return 0;
    }

}


int lista_length(Lista list) {
    if( list == NULL ) {
        return 0;
    } else {
        return 1 + lista_length(list->prox);
    } 
}


int substitui(Item x, Item y, Lista list){

    if (list == NULL){
        return -1;
    }else {
        if(list->item == x){
            list->item = y;
        }
        return substitui(x,y,list);
    }
    return 0;
}


int igual(Lista a, Lista b){
    int count = 0;
    int length = lista_length(a);
    while(a != NULL && b != NULL){
        if( a->item == b->item){
            count++;
        }
        a = a->prox;
        b = b->prox;
    }

    if(count == length){
        return 1;
    }else{
        return 0;
    }
}


int enezimo (int n, Lista list){

    for (int i = 0; i < lista_length(list); i++)
    {
        if (i == n - 1) break;
        list = list -> prox;
    }
    return list->item;

}


void inserir_ordenado(Item x, Lista *list) {

    while( *list != NULL && (*list)->item < x) list = &(*list)->prox;
    *list = incluir(x, *list) ;
}


void inserir_ordenado_sr(Item x, Lista *list) {

    while( *list != NULL && (*list)->item < x) list = &(*list)->prox;
    if(*list == NULL || (*list)->item != x){
    *list = incluir(x, *list) ;
    }
}