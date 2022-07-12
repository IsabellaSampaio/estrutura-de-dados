/***********************************
 atv7 - exerício 
 by Isabella Sampaio
  
************************************/



// Includes necessários
#include "tadfila.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h> 

typedef struct{
    char cep[1000];
    char nome[3000];
    char email[3000];
    char tel[1000];

} tPessoas; 

typedef struct{
    char cepvax[1000];
    char nomevax[3000]; 
    char emailvax[3000];
    char telvax[1000];

} tVacinados;


// Funçao que salva as pessoas do arquivo pessoasvac.txt em uma fila
Fila salvaPessoas(char file[]){
    FILE *filePessoas;
    Fila f; 
    char *linha, *pos, *tok;
    const char c[2] = ";";
    tPessoas *aux;

    filePessoas = fopen(file, "rt");
    f = criaFila();

    while(!feof(filePessoas)){
        linha = (char*)malloc(1000 * (sizeof(char)));
        fgets(linha, 1000, filePessoas);        
        aux = (tPessoas*)malloc(sizeof(tPessoas));

        // Tirando os espaços que o fgets deixa 
        if ((pos = strchr(linha, '\n')) != NULL){
            *pos = '\0';
        }

        tok = strtok(linha, c);
        strcpy(aux->cep, tok);
        strcpy(aux->nome, strtok(NULL, c));
        strcpy(aux->email, strtok(NULL, c));
        strcpy(aux->tel, strtok(NULL, c));

        enfileira(f, aux);    

    }


    fclose(filePessoas);
    return f; 
        
}

int main(){    

    int mesa1, mesa2, mesa3, mesa4, randm;
    int countm1, countm2, countm3, countm4;
    Fila fpessoas;
    lista l, l1, l2, l3, l4;
    tPessoas *pessoa1, *pessoa2, *pessoa3, *pessoa4;
    tVacinados *aux;

    fpessoas = salvaPessoas("pessoasvac.txt");  
    l1 = criaLista();

    // alocando espaço na memória para struct
    pessoa1 = (tPessoas*)malloc(sizeof(tPessoas));
    pessoa2 = (tPessoas*)malloc(sizeof(tPessoas));
    pessoa3 = (tPessoas*)malloc(sizeof(tPessoas));
    pessoa4 = (tPessoas*)malloc(sizeof(tPessoas));

    // Os counts vao contar a quantidade de vezes que uma mesma mesa foi acessada 
    countm1 = 0;
    countm2 = 0;
    countm3 = 0;
    countm4 = 0;
        

    // Criando listas para armazenar o nome dos vacinados 
    l1 = criaLista();
    l2 = criaLista();
    l3 = criaLista();
    l4 = criaLista();
    
    l = fila2lista(fpessoas);
    for(int i = 0; i<lenLista(l); i++){

        srand(time(NULL)*i); // Para que sempre sejam gerados numeros aleatorios 
    
        randm = (rand() % 4); // gera numeros aleatorios entre 0 e 3; 

        aux = (tVacinados *)malloc(sizeof(tVacinados));

        // Condições: 
        // Tira da fila e aloca em uma lista
        // Conta a quantidade de pessoas vacinadas na mesa
        if(randm == 0){
            pessoa1 = desenfileira(fpessoas);
            strcpy(aux->nomevax, pessoa1->nome);
            appendLista(l1, aux->nomevax); 
            countm1++;
        }
        if(randm == 1){
            pessoa2 = desenfileira(fpessoas);
            strcpy(aux->nomevax, pessoa2->nome);
            appendLista(l2, aux->nomevax); 
            countm2++;                  
        }  
        
        if(randm == 2){
            pessoa3 = desenfileira(fpessoas);
            strcpy(aux->nomevax, pessoa3->nome);
            appendLista(l3, aux->nomevax);           
            countm3++;
        }
        if(randm == 3){
            pessoa4 = desenfileira(fpessoas);
            strcpy(aux->nomevax, pessoa4->nome);
            appendLista(l4, aux->nomevax);           
            countm4++;
            
        }

    }

    // Imprime na tela a quantidade de pessoas vacinadas por mesa
    printf("\nForam vacinadas %d pessoas na mesa 1\n", countm1);
    printf("Foram vacinadas %d pessoas na mesa 2\n", countm2);
    printf("Foram vacinadas %d pessoas na mesa 3\n", countm3);
    printf("Foram vacinadas %d pessoas na mesa 4\n", countm4);

    // Imprime na tela o nome das pessoas vacinadas e em qual mesa elas foram vacinadas
    printf("\nPessoas vacinadas em cada mesa:\n\n");    
    printf("Mesa 1:\n\n");    
    for(int j=0; j < lenLista(l1); j++){
        printf("%s\n", (char*)dadoLista(l1, j));
    } 
    printf("\nMesa 2:\n\n");  
    for(int k=0; k < lenLista(l2); k++){
        printf("%s\n", (char*)dadoLista(l2, k));

    }
    printf("\nMesa 3:\n\n");  
    for(int l=0; l < lenLista(l3); l++){
        printf("%s\n", (char*)dadoLista(l3, l));

    }
    printf("\nMesa 4:\n\n");  
    for(int m=0; m < lenLista(l4); m++){
        printf("%s\n", (char*)dadoLista(l4, m));  

    }

    // Checkpoint (verifica se nao esta dando nenhum erro, se chegou até aqui é pq rodou ok!)
    printf("\nCONCLUÍDO!!\n");
    return 0;
}