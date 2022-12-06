#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef struct aluno {
	int matricula;
	char nome[20];
} Aluno;

void insertionSort(Aluno v[], int n) {
    int i, j;
	Aluno x;

    for (i = 1; i < n; i++) {
        x = v[i];
        j = i - 1;
  
        while (j >= 0 && v[j].matricula > x.matricula) {
            v[j + 1] = v[j];
            j = j - 1;
        }

        v[j + 1] = x;
    }
}

void troca(Aluno *a, Aluno *b) {
	Aluno temp = *a;
	*a = *b;
	*b = temp;
}

void selectionSort(Aluno v[], int n) {
	for (int k = 0; k < n - 1; k++) {
		int menor = k;
		for (int i = k + 1; i < n; i++) {
			if (strcmp(v[i].nome, v[menor].nome) < 0)
				menor = i;
		}

		troca(&v[menor], &v[k]);
	}
}

void bubbleSort(Aluno v[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (v[j].matricula > v[j + 1].matricula)
                troca(&v[j], &v[j + 1]);
}

Aluno* ler_dados() {
	Aluno* alunos = (Aluno*) malloc(5*sizeof(Aluno));

	for (int i = 0; i < 5; i++) {
		int mat;
		char nome[20];

		printf("nome do aluno: ");
		scanf("\n%s", nome);
		printf("matrícula do aluno: ");
		scanf("\n%d", &mat);

		strcpy(alunos[i].nome, nome);
		alunos[i].matricula = mat;
	}

	return alunos;
}

void exibirDados(Aluno v[], int n) {
	printf("\nDados Ordenados: \n\n");

	for (int i = 0; i < 5; i++) {
		printf("Aluno: %s\n", v[i].nome);
		printf("Matrícula: %d\n\n", v[i].matricula);
	}
}

int main() {
	Aluno* alunos1 = ler_dados();
	Aluno* alunos2 = (Aluno*) malloc(5*sizeof(Aluno));
	Aluno* alunos3 = (Aluno*) malloc(5*sizeof(Aluno));

	for (int i = 0; i < 5; i++) {
		alunos2[i] = alunos1[i];
		alunos3[i] = alunos1[i];
	}

	insertionSort(alunos1, 5);
	exibirDados(alunos1, 5);
	
	selectionSort(alunos2, 5);
	exibirDados(alunos2, 5);
	
	bubbleSort(alunos3, 5);
	exibirDados(alunos3, 5);

	return 0;
}