/*Aula de structs em c
*/

// Pergunta ao usuário a respeito de nota e outras infos do aluno
typedef struct {
    int num;
    float nota;
    char nome[40];

} alunos;

int main(){

    alunos dadosAluno;
    printf("Digite o numero de matricula do aluno: ");
    scanf("%d", &dadosAluno.num);
    
    printf("Digite a nota do aluno: ");
    scanf("%f", &dadosAluno.nota);

    printf("Digite o nome do aluno: ");
    scanf("%s", &dadosAluno.nome);
   
    printf("Nome do aluno: %s\n", dadosAluno.nome);
    printf("Numero da matricula: %d\n", dadosAluno.num);
    printf("Nota do aluno: %.2f\n", dadosAluno.nota);


    return 0;
}



//Pergunta ao usuario a respeito de um livro 
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {

    char nome[30];
    char autor[50];
    int paginas;
    float preco;
} livro; 


int main(){

    livro livro1;

    setlocale(LC_ALL, "");
    printf("Cdastrando livro\n");
    printf("\nDigite o nome do livro:\n");
    gets(livro1.nome);
    printf("\nDigite o nome do autor:\n");
    gets(livro1.autor);
    printf("\nDigite o número de páginas do livro:\n");
    scanf("%d",&livro1.paginas);
    printf("\nEntre com o preço do livro:\n");
    scanf("%f",&livro1.preco);

    printf("\nO livro \"%s\" possui %d páginas e custa R$ %4.2f\n", livro1.nome, livro1.paginas,livro1.preco);

    return 0;

}



 
