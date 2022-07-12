#include "tadlista.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

lista coloca_na_lista(lista l, int num)
{
    int *pnum = (int *)malloc(sizeof(int));
    *pnum = num;
    appendLista(l, pnum);

    return l;
}

lista insere_na_lista(lista l, int pos, int num)
{
    int *pnum = (int *)malloc(sizeof(int));
    *pnum = num;
    insertLista(l, pos, pnum);
}

lista index_da_lista(lista l, int num)
{
    int *pnum = (int *)malloc(sizeof(int));
    *pnum = num;
    indexLista(l, pnum);
}

void print_elem(lista l, int indice, char msg[])
{
    int *pnum;
    pnum = dadoLista(l, indice);
    printf("%s: %d\n", msg, *pnum);
}

int main()
{
    lista lst = criaLista();
    lst->primeiro = NULL;
    int num;

    coloca_na_lista(lst, 10);
    coloca_na_lista(lst, 20);
    coloca_na_lista(lst, 30);

    printf("Recuperando dados da lista!\n");

    print_elem(lst, 0, "Primeiro elemento");
    print_elem(lst, 1, "Segundo elemento");
    print_elem(lst, 2, "Terceiro elemento");

    insere_na_lista(lst, 1, 15);
    insere_na_lista(lst, 0, 25);
    insere_na_lista(lst, 2, 60);

    printf("\nRecuperando dados da lista depois do insert!\n");

    print_elem(lst, 0, "Primeiro elemento");
    print_elem(lst, 1, "Segundo elemento");
    print_elem(lst, 2, "Terceiro elemento");
    print_elem(lst, 3, "Quarto elemento");
    print_elem(lst, 4, "Quinto elemento");
    print_elem(lst, 5, "Sexto elemento");

    removeLista(lst, 0);

    printf("\nRecuperando dados da lista depois do remove!\n");

    print_elem(lst, 0, "Primeiro elemento");
    print_elem(lst, 1, "Segundo elemento");
    print_elem(lst, 2, "Terceiro elemento");
    print_elem(lst, 3, "Quarto elemento");
    print_elem(lst, 4, "Quinto elemento");

    printf("\nDigite um número da lista do qual deseja saber o index (posicao): ");
    scanf("%d", &num);
    printf("O index do número %d é %d\n", num, index_da_lista(lst, num));

    return 0;
}