/****************************
* atv6 - exerício de exemplo
* aplicação do tadfila 
****************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tadfila.h"


int main(){
  Fila f = criaFila();
  lista l;
  
  printf("Testando o TAD fila\n\n");

  /* Cria strings dinâmicas (array de 30 chars) */
  char *mes1 = (char*)malloc(30 * sizeof(char));
  char *mes2 = (char*)malloc(30 * sizeof(char));
  char *mes3 = (char*)malloc(30 * sizeof(char));

  strcpy(mes1, "Janeiro");
  strcpy(mes2, "Fevereiro");
  strcpy(mes3, "Marco");

  enfileira(f, mes1);
  enfileira(f, mes2);
  enfileira(f, mes3);

  l = fila2lista(f);
  printf("Fila: ");
  for(int i=0; i < lenLista(l); i++){
    printf("%s, ", (char*)dadoLista(l,i));
  }
  
  printf("\n");
  printf("Tamanho da fila: %d\n", tamFila(f));
  char *mes = cabecaFila(f);
  printf("Cabeca da fila: %s\n", mes);
  mes= caudaFila(f);
  printf("Cauda da fila: %s\n\n", mes);

  printf("Desenfileirando ..\n");
  mes = desenfileira(f);
  printf("Foi desenfileirado o elemento %s\n\n", mes);

  l=fila2lista(f);
  printf("Fila atualizada\n");
  for(int i =0; i < lenLista(l); i++){
    printf("%s, ", (char*)dadoLista(l, i));
  }
  printf("\n");
  printf("Novo tamanho da fila: %d\n", tamFila(f));

  mes = cabecaFila(f);
  printf("Nova cabeca da fila: %s\n", mes);
  mes = caudaFila(f);
  printf("Cauda da fila: %s\n", mes);

  l=fila2lista(f);
  if(lenLista(l) == 0){
    printf("\nfila vazia!\n");
  }


  
   
  
  return 0;
}

