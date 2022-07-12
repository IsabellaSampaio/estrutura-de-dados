/* Aula 2 de arquivos
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *pont_arq;
    char palavra[20];

    pont_arq = fopen("arquivo.txt","a");

    if(pont_arq == NULL){
        printf("Erro na abertura do arquivo!");
        return 1;
    }
    else{
        printf("Escreva algo para gravar no arquivo: ");
        scanf("%s", palavra);


        //ppra armazenar a string no arquivo
        fprintf(pont_arq, "%s ", palavra);

        fclose(pont_arq);

        printf("Dados gravados com sucesso!");

    }

    return 0;
}