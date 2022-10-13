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
    int alunos = 0;

    
    for(int i = 0; i < MAX; i++){
        if(alunos < MAX){
        printf("\n Matricula aluno: \n");
        scanf("%d", &lista[i].mat);
        printf("\n Nome aluno: \n");
        scanf("%s", &lista[i].nome);
        alunos++;
        }
        else{
            printf("\n Cheia!");
        }
    }
}

//retorna a posicao do elemento procurado
int procura(int mat){
    for (int i = 0; i < MAX; i++){
        if(lista[i].mat == mat){
            return i;
            break;
        }else{
            return -1;
        }
    }
    
}

//recebe a posicao e imprime o elemento na tela
void mostrar(int pos){
	printf("%d", &lista[pos].mat);
	printf("%s", &lista[pos].nome);
}

//procura o elemento e depois mostra o elemento encontrado (se nao for encontrado informa q ele nao existe)
void consultar(int mat){
        for (int i = 0; i < MAX; i++){
        if(lista[i].mat == mat){
            mostrar(i);
            break;
        }else if(lista[i].mat == NULL){
            printf("\n Não existe!");
            break;
        }
    }
}

//estrat�gia 1: colocar o ultimo elemento da lista na posi��o do elemento removido
void remover00(){
	int mat,cont,achou,conrem,resp;
	int i = -1;
	do{
		printf("\nRemover aluno\n\n");printf("\nMatricula: ");
		scanf("%d", &mat);
		achou=procura(mat);
		if(achou != -1){
			mostrar(achou);
			printf("\nDeseja remover: 1-SIM 2-NAO: ");
			scanf("%d",&resp);
			if(resp == 1){

				while(lista[i].mat != NULL){
					i++;
					printf("\n%d", i);
				}

				lista[achou] = lista[i];

				printf("\nAluno removido");
		} else {
			printf("\nAluno nao foi removido");
			break;
		} 
		} else {
			printf("\nAluno nao encontrado");
		}

		printf("\nRemover outro aluno: 1-SIM, 2-NAO: ");
		scanf("%d", &cont);
	} while(cont == 1);
}

//estrat�gia 2: mover TODOS os elementos que est�o AP�S  o elemento que deve ser removido UMA POSI��O A FRENTE.
void remover01(){
	int mat,cont,achou,conrem,resp;
	int i = -1;
	do{
		printf("\nRemover aluno\n\n");printf("\nMatricula: ");
		scanf("%d", &mat);
		achou=procura(mat);
		if(achou != -1){
			mostrar(achou);
			printf("\nDeseja remover: 1-SIM 2-NAO: ");
			scanf("%d",&resp);
			if(resp == 1){

				while (i < achou){
					i++;
				}

				while(i < MAX-1){
					lista[i].mat = lista[i + 1].mat;
					lista[i].nome = lista[i + 1].nome;
				}
				

				printf("\nAluno removido");
		} else {
			printf("\nAluno nao foi removido");
			break;
		} 
		} else {
			printf("\nAluno nao encontrado");
		}

		printf("\nRemover outro aluno: 1-SIM, 2-NAO: ");
		scanf("%d", &cont);
	} while(cont == 1);
}

main(){
	aluno *al = new aluno();
    
	
}
