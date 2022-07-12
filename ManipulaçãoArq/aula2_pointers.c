/* Aula 2 de ponteiros
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//indireção multipla - um ponteiro que aponta para outro 
//encadeamento de ponteiros
// quanto mais * maior o nivel do encadeamento dos ponteiros
int main(){

    int a = 40;
    int *pont1;
    int **pont2;

    pont1 = &a;
    pont2 = &pont1;   

    printf("Endereço da variavel a eh: %p\n", &a);
    printf("O endereço do ponteiro pont1: %p\n", &pont1);
    printf("O endereço do ponteiro pont2: %p\n", &pont2);
    printf("O endereço apontado por pont1: %p\n", pont1);
    printf("O endereço apontado por pont2: %p\n", pont2);
    printf("O valor armazenado em a eh: %d\n", **pont2);


    return 0;
}