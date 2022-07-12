/* Aula 1 de ponteiros
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){

    // o tipo apontado pelo ponteiro é int, nao o ponteiro em si
    // & - endereço de memória
    // * - indica que é ponteiro que estamos tratando
    setlocale(LC_ALL, "");

    int *x, valor, y;
    valor = 35;
    x = &valor;
    y = x; 
    
    printf("Endereço da variavel comum valor: %p\n", &valor);
    printf("Lendo o conteúdo do ponteiro x: %p\n", x);
    printf("Endereço da variavel ponteiro x: %p\n", &x);
    printf("Conteudo da variavel apontada por x: %d\n", *x);
    printf("Conteudo da variavel comum y: %d\n", y);


    return 0;
}