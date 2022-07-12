/*Aula 4 de arquivos
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *f;
    char str[100];

    f = fopen("arquivo.txt", "w");

    if (!f) {
        printf("Erro ao abrir o arquivo");
        return 1;
    }

    

    fprintf(f, "Esse é o meu texto %d\n", 2022);
    printf("Salvo no arquivo com sucesso!\n");

    fclose(f);

    f = fopen("arquivo.txt", "r");

    fscanf(f, "%[^\n]\n", str);

    printf("O conteudo do arquivo: %s\n", str);

   fclose(f);


    return 0;
}