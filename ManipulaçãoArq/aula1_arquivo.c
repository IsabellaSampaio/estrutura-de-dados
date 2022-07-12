#include <stdio.h>
#include <stdlib.h>


/*cria um arquivo
int main(){
    FILE *pont_arq;

    pont_arq = fopen("arquivo.txt","a");

    fclose(pont_arq);

    printf("O arquivo foi criado com sucesso!\n");

    return 0;
} */

//Lendo de um arquivo
int main(){

    FILE *pont_arq;
    char texto_str[20];

    pont_arq = fopen("arquivo.txt", "r");

    while(fgets(texto_str,20,pont_arq)!= NULL)
        printf("%s",texto_str);

    fclose(pont_arq);


    return 0;
}