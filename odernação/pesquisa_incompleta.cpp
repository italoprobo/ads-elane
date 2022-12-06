#include<stdio.h>
#include<iostream>
#include <string.h>

using namespace std;
int pesquisa_linear(int x,int v[], int n) {
   int p = 0;
    int u = n-1;
    while( p <= u ) {
        int m = (p+u)/2;
        if( x == v[m] ) return 1;
        if( x < v[m] ) u = m-1;
        else p = m+1;
    }
    return 0;
};
int pesquisa_binaria(int x,int v[], int n) {
   for(int i=0; i<n; i++)
        if( x == v[i] )
            return 1;
    return 0;
};

int main(){
   // A. Leia os valores atrav�s do teclado
   int value = 0;
   int values[20];
   int i = 0;
   
   int valor_procurado;
   scanf("%d", &valor_procurado);
   // B. Armazene os valores no vetor de dados
   while (value != -1) {
        scanf("%d", &value);
        values[i] = value;
        i++;
   }
   // C. leia o valor que deseja procurar
   int k =0;
   int valor_procurado2;
   printf("Valor Procurado: ")
   scanf("%d", &valor_procurado2);
   while(k <  20) {
      if(valor_procurado2 == values[k]){
         printf("%d", &values[k]);
      }
      k++;
   }
   // D. Aplique a pesquisa linear
   pesquisa_linear(valor_procurado, values, 19);
   // E. Apresente o resultado
   // F. Aplique a pesquisa bin�ria
   pesquisa_binaria(valor_procurado, values, 19);
   // G. Apresente o resultado
   


      
}

