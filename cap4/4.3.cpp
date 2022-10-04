#include <stdio.h>
#include <ctype.h>
#include "../pilha2.h"
#include "./fila.h"

int main(void) {
    char s[100];
    Fila* F = new Fila();
    Pilha* P = create_stack();
    printf("\nFrase ? ");
    scanf("%255[^\n]", s);

    for(int i = 0; s[i]; i++) {
        if(isalpha(s[i])) {
            F->inserir(s[i]);
            push(s[i], P);
        }
    }

    while(!F->vazia() && toupper(F->remover()) == toupper(pop(P)));

    if(F->vazia()) puts("Palindromo");
    else puts("Nao eh palindroma");

    F->destroi();
    free(F);
    destroy(P);
    return 0;
}
