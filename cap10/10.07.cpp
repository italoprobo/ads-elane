#include <stdio.h>
#include <stdlib.h>

typedef struct polinomio {
    float coef;
    int expo;
    struct polinomio *prox;
} *Polinomio;

Polinomio term(float c, int e, Polinomio p) {
    Polinomio n = (Polinomio)malloc(sizeof(struct polinomio));
    n->coef = c;
    n->expo = e;
    n->prox = p;
    return n;
} 

void mostrar(Polinomio P) {
    if( P == NULL ) return;
    printf("%+1.f", P->coef);
    if( P->expo!=0 ) printf("*xˆ%d", P->expo);
    mostrar(P->prox);
}


void inserir(float c, int e, Polinomio *P) {
    if ( *P == NULL || (*P)->expo<e )
        *P = term(c, e, *P);
    else if( (*P)->expo==e ) {
        (*P)->coef += c;
        if( (*P)->coef==0 ) {
            Polinomio n = *P;
            *P = n->prox;
            free(n);
        }
    }
    else inserir(c,e,&(*P)->prox);
}

Polinomio soma(Polinomio P, Polinomio Q) {
    while (P != NULL) {
        inserir(P->coef, P->expo, &Q);
        P = P->prox;
    }

    return Q;
}