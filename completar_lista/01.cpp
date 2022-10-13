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

