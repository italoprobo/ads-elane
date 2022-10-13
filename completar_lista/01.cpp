#include <stdio.h>
#include <iostream>
#define MAX 30
using namespace std;

typedef struct aluno{
	int mat;
	string nome;	
}Aluno; 

Aluno lista[MAX];


void incluirDesordenado(Aluno e){
    int alunos = 0; int count;

    
    for(int i = 0; i < MAX; i++){
        printf("\n Matricula aluno: \n");
        scanf("%d", &lista[i].mat);
        printf("\n Nome aluno: \n");
        scanf("%s", &lista[i].nome);
        alunos++;
    }
}

//retorna a posicao do elemento procurado
int procura(int mat){	
}

//recebe a posicao e imprime o elemento na tela
void mostrar(int pos){
	
}

//procura o elemento e depois mostra o elemento encontrado (se nao for encontrado informa q ele nao existe)
void consultar(int mat){	
}

//estrat�gia 1: colocar o ultimo elemento da lista na posi��o do elemento removido
void remover00(){
	
}

//estrat�gia 2: mover TODOS os elementos que est�o AP�S  o elemento que deve ser removido UMA POSI��O A FRENTE.
void remover01(){
}

main(){
	
	
}
