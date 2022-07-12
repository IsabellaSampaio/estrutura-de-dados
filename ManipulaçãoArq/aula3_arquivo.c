/*Aula 3 de arquivos, sobre fprintf
*/
#include <stdio.h>
#include <stdlib.h>

//Escreve em arquivos utilizando fprintf
void escrever(char f[]){
    FILE *file = fopen(f,"a");
    char nome[100];
    int opcao, idade;
    float altura; 

    if(file){
        do{
            printf("Digite seu primeiro nome, idade e altura: ");
            scanf("%100[^\n]%d%f", nome, &idade, &altura);
            fprintf(file,"%s %d %.2f\n", nome, idade, altura);
            printf("\nDigite 1 para inserir outro registro. ");
            scanf("%d", &opcao);
            gets();
        }while(opcao == 1);
        
        fclose(file);

    }else{
        printf("\nErro ao abrir arquivo!\n");
    }


}

// Lê dados do arquivo utilizando fscanf
void ler(char f[]){
    FILE *file = fopen(f,"r");
    char nome[1000];
    int idade;
    float altura; 

    if(file){
        printf("\tDados lidos do arquivo:\n");
        while(fscanf(file,"%s %d %f", nome, &idade, &altura) != -1)
            printf("\n\tNome: %s \n\tIdade: %d\n\tAltura: %.2f\n", nome, idade, altura);
        fclose(file);
    }else{
        printf("\nErro ao abrir arquivo!\n");
    } 
}

int main(){
    char nome[] = {"arquivo.txt"};

    escrever(nome);
    ler(nome);

    return 0;
}    