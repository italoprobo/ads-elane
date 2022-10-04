#include <stdlib.h>
#include <iostream>

using namespace std;

class No {
    public:
        char nome;
        No* prox;

        No(char n)
        {
            nome = n;
            prox = NULL;
        }
};

class Fila {
    public:
        No* inicio;
        No* fim;

        Fila() {
            inicio = NULL;
            fim = NULL;
        }

        void insereNaFila(char n) {
            No* novo = new No(n);
            if (inicio == NULL) {
                inicio = novo;
                fim = novo;
            } else {
                fim->prox = novo;
                fim = novo;
            }
        }

        char retiraDaFila() {
            No* el;
            char nome;
            if (inicio != NULL) {
                el = inicio;
                nome = el->nome;
                inicio = inicio->prox;
                free(el);
            }

            return nome;
        }

        int fila_vazia() {
            return (inicio == NULL);
        }

        void mostra() {
            No* atual;
            atual = inicio;

            while (atual != NULL) {
                printf("Nome: %c\n", atual->nome);

                atual = atual->prox;
            }
        }
};

int main() {
    Fila* f1 = new Fila();
    Fila* f2 = new Fila();
    int resp;
    char letra;

    do {
        cout << "\nDigite a letra: ";
        cin >> letra;

        if(f1->fila_vazia()) {
            f1->insereNaFila(letra);

            while(!f2->fila_vazia()) {
                f1->insereNaFila(f2->retiraDaFila());
            }
        } else {
            f2->insereNaFila(letra);

            while(!f1->fila_vazia()) {
                f2->insereNaFila(f1->retiraDaFila());
            }
        }

        cout << "\nComtimuar ?\n1 - Sim\n2 - Nao\n> ";
        cin >> resp;
    } while (resp == 1);

    while(!f2->fila_vazia()) {
        f1->insereNaFila(f2->retiraDaFila());
    }

    f1->mostra();

    return 0;
}
