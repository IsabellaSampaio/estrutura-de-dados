/*********************************************************
 Fonte: tad_lista.c
 Versão:
 Autor:
 S.O.:
 Última alteração: 05/06/2022
********************************************************/

#include "tadlista.h"
#include <stdlib.h>

/********************************************************
 *
 * IMPLEMENTAÇÃO DO TAD LISTA
 *
 ********************************************************/

lista criaLista()
{

    lista lst = (lista)malloc(sizeof(tcabec));
    lst->tamanho = 0;
    lst->primeiro = NULL;
    lst->ultimo = NULL;

    return lst;
}

int lenLista(lista lst)
{
    return lst->tamanho;
}

tdado primLista(lista lst)
{
    return lst->primeiro->dado;
}

tdado ultLista(lista lst)
{
    return lst->ultimo->dado;
}

lista appendLista(lista lst, tdado dado)
{

    if (lst == NULL)
        return NULL;

    pnoh novo_no = (pnoh)malloc(sizeof(tnode));
    novo_no->proximo = NULL;
    novo_no->dado = dado;

    if (lenLista(lst) == 0)
    {
        lst->primeiro = novo_no;
        lst->ultimo = novo_no;
    }
    else
    {
        lst->ultimo->proximo = novo_no;
        lst->ultimo = novo_no;
    }

    lst->tamanho++;
}

tdado dadoLista(lista lst, int pos)
{
    int cont_pulos;
    pnoh no_corrente;

    if ((lst == NULL) || (pos < 0) || (pos >= lst->tamanho))
    {
        return NULL;
    }

    cont_pulos = 0;
    no_corrente = lst->primeiro;

    while (cont_pulos != pos)
    {
        cont_pulos++;
        no_corrente = no_corrente->proximo;
    }

    return no_corrente->dado;
}

int indexLista(lista lst, tdado dado)
{
    pnoh no_corrente;
    int index;

    index = 0;
    no_corrente = lst->primeiro;

    while (index < lst->tamanho)
    {
        if (*(int*)no_corrente->dado == *(int*)dado)
        {
            return index;
        }
        index++;
        no_corrente = no_corrente->proximo;
    };

    return -1;
}

lista insertLista(lista lst, int index, tdado dado)
{
    pnoh novo_no, no_corrente;
    int i = 0;

    novo_no = (pnoh)malloc(sizeof(tnode));
    novo_no->dado = dado;
    novo_no->proximo = NULL;
    int tamanho = lenLista(lst);

    if ((lst == NULL || (index < 0) || index > tamanho))
    {
        return NULL;
    }

    else if (index == 0)
    {
        novo_no->proximo = lst->primeiro;
        lst->primeiro = novo_no;
        lst->tamanho++;
    }

    else
    {
        no_corrente = lst->primeiro;

        while (--index)
        {
            no_corrente = no_corrente->proximo;
        }

        novo_no->proximo = no_corrente->proximo;
        no_corrente->proximo = novo_no;
        lst->tamanho++;
    }
}

lista removeLista(lista lst, int index)
{
    pnoh no_corrente, no_anterior;
    int tamanho = lenLista(lst);

    no_anterior = lst->primeiro;

    if ((lst == NULL || (index < 0) || index > tamanho))
    {
        return NULL;
    }

    else if (index == 0)
    {
        no_corrente = lst->primeiro;
        lst->primeiro = no_corrente->proximo;
    }

    else
    {

        while (--index)
        {
            no_anterior = no_anterior->proximo;
        }

        no_corrente = no_anterior->proximo;
        no_anterior->proximo = no_corrente->proximo;
    }

    lst->tamanho--;
    free(no_corrente);
}
