#ifndef MYCLASS_H
#define MYCLASS_H

#include <iostream>
 
using namespace std;
 
class No {
 
	public:
 
		char valor;
		No* prox;
 
		No(char n){
			valor = n;
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
 
		void inserir(char n) {
			if(vazia()) {
                inicio = new No(n);
                fim = inicio;
			} else {
                No* novoNo = new No(n);
                fim->prox = novoNo;
                fim = novoNo;
			}
		}
 
		char remover() {
			if(!vazia()) {
                char valor = inicio->valor;
                No* aux = inicio;
                inicio = inicio->prox;
                free(aux);
                return valor;
			} else return '\0';
		}
 
		bool vazia() {
			return (inicio == NULL);
		}
 
		void destroi() {
			while(!vazia()) {
				remover();
			}
		}
};

#endif // MYCLASS_H
