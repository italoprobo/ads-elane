#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#define TAM 10

int tamanho=0, lista[TAM];

void insere(int valor) {
	int i;

	if(tamanho==TAM-1) {	//verifica se a lista nao esta cheia
		printf("\n\tERRO: A lista esta cheia\n");
		return;
	}

	for(i=tamanho; i>0 && valor<lista[i-1]; i--) {// faz com que os elementos deem um passo para tras
		lista[i]=lista[i-1];
	}

	lista[i]=valor;//elemento é inserido na posição que o loop parou
	tamanho++;
	printf("\nElemento inserido com sucesso!\n\n");
}

void remover(int valor) {
	int i,j,cont=0;

	if(tamanho==0) {//verifica se a lista esta vazia
		printf("\n\tErro: Lista vazia!");
		return;
	}

	for(i=0; i<tamanho && valor>=lista[i] ;i++) {
		if(valor==lista[i]) {
			for(j=i;j<tamanho-1;j++) {
				lista[j]=lista[j+1];//faz os elementos darem um passo a frente
			}
			tamanho--;
			i--;//faz o i voltar para o caso de haver numero repetidos
			cont++;
		}
	}
	if(cont!=0)
		printf("\nElemento removido com sucesso!");
	else
		printf("\n\tERRO: valor nao esta na lista");
}

void exibir() {// Exibe a lista
	int i;

	if(tamanho==0){
		printf("\n\tErro: Lista vazia!");
		return;
	}

	for(i=0;i<=tamanho-1;i++) {
		printf("\nElemento[ %d ] - posi\207\706o na lista %d ", lista[i],i+1);
	}
}

void buscar(int valor) {
	int i,aux=0;
	if(tamanho==0) {
		printf("\n\tERRO: Lista vazia");
		return;
	}

	for(i=0;i<tamanho && valor>=lista[i];i++) {
		if(valor==lista[i]) {
			printf("\nValor [ %d ] esta na posicao [%d]", valor,i+1);
			aux++;
		}
	}
	if(aux==0)
		printf("\n\tERRO: valor nao esta na lista");
}