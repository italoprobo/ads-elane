#include<stdio.h>
#include<iostream>
using namespace std;
#include "../lista3/8.8.cpp"

int mainT(){
   int vetor[6] = {7, 9, 4, 3,6,1};
   int i;   
   quick_sort(vetor, 0, 5);
   printf("\n2.Vetor ordenado:\n");
   for(i = 0; i <= 5; i++){
      printf("%d ", vetor[i]);
   }
   printf("\n");   
}