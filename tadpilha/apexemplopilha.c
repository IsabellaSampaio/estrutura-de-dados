/***********************************
 atv9 - exerício de exemplo
 by Isabella Sampaio
  
************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tadpilha.h"


int main(){
  Pilha p = criaPilha();
  lista l;
  
  char *mes1 = (char *)malloc(30 * sizeof(char));
  char *mes2 = (char *)malloc(30 * sizeof(char));
  char *mes3 = (char *)malloc(30 * sizeof(char));

  strcpy(mes1, "Janeiro");
  strcpy(mes2, "Fevereiro");
  strcpy(mes3, "Marco");

  empilha(p, mes1); 
  empilha(p, mes2); 
  empilha(p, mes3); 

  l= pilha2lista(p);
  printf("Pilha: ");
  for(int i=0; i < lenLista(l); i++){
    printf("%s, ", (char*)dadoLista(l, i));
  }

  printf("\n");
  printf("Tamanho da pilha: %d\n", tamPilha(p));

  char *mes = topoPilha(p);
  printf("Topo da pilha: %s\n", mes);
  printf("\nDesempilhando ..\n");
  mes = desempilha(p);
  printf("Foi desempilhado o elemento %s\n\n", mes);

  l = pilha2lista(p);
  printf("Pilha: ");
  for(int i=0; i < lenLista(l); i++){
    printf("%s, ", (char *)dadoLista(l, i));
  }  

  printf("\n");

  mes = topoPilha(p);
  printf("Novo  topo da pilha: %s\n", mes);
  printf("Novo tamanho da pilha: %d\n", tamPilha(p));

  printf("\nDesempilhando ..\n");
  mes = desempilha(p);
  printf("Foi desempilhado o elemento %s\n\n", mes);

  l= pilha2lista(p);
  printf("Pilha: ");
  for(int i=0; i < lenLista(l); i++){
    printf("%s, ",(char*)dadoLista(l,i));
  }
  printf("\n");

  mes = topoPilha(p);
  printf("Novo topo da pilha: %s\n", mes);
  printf("Novo tamanho da pilha: %d\n", tamPilha(p));

  printf("\nDesempilhando ..\n");
  mes = desempilha(p);
  printf("Foi desempilhado o elemento %s\n", mes);

  l = pilha2lista(p);
  if(lenLista(l)==0){
    printf("\nPilha vazia!\n");
  }

   
  
  return 0;
}
