/*********************************************************
 Exercício: Aplicação Lista Encadeada
 Aluna: Isabella Sampaio
 Matrícula: 20211BSI0208
 Data: 03/06/2022
 Ultima modificação: 05/06/2022
********************************************************/

#include "tadlista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{

  char nome[300];
  char cpf[300];
  int idade;
  float altura;

} tpessoa;

lista armazenaNomes(char arquivo[])
{
  lista lst = criaLista();
  FILE *arquivoEntrada = fopen(arquivo, "r");
  char *pos;

  while (!feof(arquivoEntrada))
  {
    char *pstr = (char *)malloc(sizeof(char *) * 300);
    fgets(pstr, 300, arquivoEntrada);

    // Solução para retirar as linhas que são saltadas pelo fgets
    if ((pos = strchr(pstr, '\n')) != NULL)
    {
      *pos = '\0';
    }
    appendLista(lst, pstr);
  }

  fclose(arquivoEntrada);
  return lst;
}

lista armazenaCpfs(char arquivo[])
{
  lista lst = criaLista();
  FILE *arquivoEntrada = fopen(arquivo, "r");
  char *pos;

  while (!feof(arquivoEntrada))
  {
    char *pstr = (char *)malloc(sizeof(char *) * 300);
    fgets(pstr, 300, arquivoEntrada);

    // Solução para retirar as linhas que são saltadas pelo fgets
    if ((pos = strchr(pstr, '\n')) != NULL)
    {
      *pos = '\0';
    }
    appendLista(lst, pstr);
  }

  fclose(arquivoEntrada);
  return lst;
}

lista armazenaIdades(char arquivo[])
{
  lista lst = criaLista();
  FILE *arquivoEntrada = fopen(arquivo, "r");

  while (!feof(arquivoEntrada))
  {
    int *pint = (int *)malloc(sizeof(int));
    fscanf(arquivoEntrada, "%d", pint);
    appendLista(lst, pint);
  }

  fclose(arquivoEntrada);
  return lst;
}

lista armazenaAlturas(char arquivo[])
{
  lista lst = criaLista();
  FILE *arquivoEntrada = fopen(arquivo, "r");

  while (!feof(arquivoEntrada))
  {
    float *pfloat = (float *)malloc(sizeof(float));
    fscanf(arquivoEntrada, "%f", pfloat);
    appendLista(lst, pfloat);
  }

  fclose(arquivoEntrada);
  return lst;
}

lista armazenaPessoas(lista nomes, lista cpfs, lista idades, lista alturas)
{

  lista pessoas = criaLista();
  tpessoa *aux;
  int index;
  int tamanhoNome = lenLista(nomes);
  int tamanhoCpf = lenLista(cpfs);
  int tamanhoIdade = lenLista(idades);
  int tamanhoAltura = lenLista(alturas);

  if (tamanhoNome == tamanhoCpf || tamanhoIdade == tamanhoAltura)
  {
    for (index = 0; index < tamanhoCpf; index++)
    {
      aux = (tpessoa *)malloc(sizeof(tpessoa));
      tpessoa pessoa;

      strcpy(pessoa.nome, dadoLista(nomes, index));
      strcpy(pessoa.cpf, dadoLista(cpfs, index));
      pessoa.idade = *(int *)dadoLista(idades, index);
      pessoa.altura = *(float *)dadoLista(alturas, index);

      *aux = pessoa;
      appendLista(pessoas, aux);
    }
  }
  return pessoas;
}

void salvaPessoas(lista lst, char arquivo[])
{
  FILE *arquivoSaida = fopen(arquivo, "w");
  int tamanhoLista = lenLista(lst);
  tpessoa *aux;

  fprintf(arquivoSaida, "DADOS RECUPERADOS ABAIXO:");
  fprintf(arquivoSaida, "\n-------------------------\n");

  for (int i = 0; i < tamanhoLista; i++)
  {
    aux = (tpessoa *)(dadoLista(lst, i));
    fprintf(arquivoSaida, "Nome: %s | CPF: %s | Idade: %d | Altura:%.2f\n", aux->nome, aux->cpf, aux->idade, aux->altura);
  }

  fclose(arquivoSaida);

  return;
}

int main()
{

  lista lstNomes;
  lista lstCpfs;
  lista lstIdades;
  lista lstAlturas;
  lista lstPessoas;

  lstNomes = armazenaNomes("bdnomes.txt");
  lstCpfs = armazenaCpfs("bdcpfs.txt");
  lstIdades = armazenaIdades("bdidades.txt");
  lstAlturas = armazenaAlturas("bdalturas.txt");

  lstPessoas = armazenaPessoas(lstNomes, lstCpfs, lstIdades, lstAlturas);
  salvaPessoas(lstPessoas, "bdpessoas.txt");

  return 0;
}