/*********************************************************
 Exercício: Aplicação Lista Encadeada 2
 Aluna: Isabella Sampaio
 Matrícula: 20211BSI0208
 Data: 21/06/2022
 Ultima modificação: 21/06/2022
********************************************************/

#include "tadlista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct com informações dos proprietarios
typedef struct
{

  char cpf[20];
  char nome[100];
  char email[100];
  int tel;

} tproprietario;

// Struct com informações dos veiculos
typedef struct
{

  char placa[100];
  char modelo[100];
  char marca[100];
  int quilometragem;
  char cor[15];
  char cpfdono[20];

} tveiculo;

// Struct que relaciona proprietarios com seus respectivos veiculos
typedef struct
{
  char cpf[20];
  char nome[100];
  char email[100];
  char placa[100];
  char modelo[100];
  char marca[100];

} tdono;

// Função que le linha a linha do arquivo bdprorprietarios e armazena em tproprietario
lista salvaStructA(char arquivo[])
{

  FILE *arquivoEntrada = fopen(arquivo, "rt");
  char *tok, *pos;
  char *linha;
  const char a[2] = ",";
  tproprietario *aux;

  lista proprietarios = criaLista();

  while (!feof(arquivoEntrada))
  {

    linha = (char *)malloc(sizeof(char *) * 300);
    fgets(linha, 300, arquivoEntrada);
    aux = (tproprietario *)malloc(sizeof(tproprietario));

    if ((pos = strchr(linha, '\n')) != NULL)
    {
      *pos = '\0';
    }

    // strtok e strcpy - strtok utilizado para partir a string em um caracter e strcpy para pegar cada parte da string e armazenar na struct
    // atoi - para converter string para um inteiro
    tok = strtok(linha, a);

    strcpy(aux->cpf, tok);
    strcpy(aux->nome, strtok(NULL, a));
    strcpy(aux->email, strtok(NULL, a));
    aux->tel = atoi(strtok(NULL, a));

    appendLista(proprietarios, aux);
  }

  fclose(arquivoEntrada);
  return proprietarios;
}

// Função que le linha a linha do arquivo bdveiculos_donos e armazena em tveiculo
lista salvaStructB(char arquivo[])
{
  FILE *arquivoEntrada = fopen(arquivo, "rt");
  char *tok, *pos;
  char *linha;
  const char a[2] = ", ";
  tveiculo *aux;

  lista veiculos = criaLista();

  while (!feof(arquivoEntrada))
  {

    linha = (char *)malloc(sizeof(char *) * 300);
    fgets(linha, 300, arquivoEntrada);
    aux = (tveiculo *)malloc(sizeof(tveiculo));

    if ((pos = strchr(linha, '\n')) != NULL)
    {
      *pos = '\0';
    }

    // strtok e strcpy - strtok utilizado para partir a string em um caracter e strcpy para pegar cada parte da string e armazenar na struct
    // atoi - para converter string para um inteiro
    tok = strtok(linha, a);

    strcpy(aux->placa, tok);
    strcpy(aux->modelo, strtok(NULL, a));
    strcpy(aux->marca, strtok(NULL, a));
    aux->quilometragem = atoi(strtok(NULL, a));
    strcpy(aux->cor, strtok(NULL, a));
    strcpy(aux->cpfdono, strtok(NULL, a));

    appendLista(veiculos, aux);
  }

  fclose(arquivoEntrada);
  return veiculos;
}

// Função que a partir de dados recuperados das listas proprietarios e veiculos salva-os em tdono
lista salvaStrucsAB(lista proprietarios, lista veiculos)
{

  lista donos = criaLista();
  tdono *aux;
  tveiculo *veiculo;
  tproprietario *proprietario, *auxProp;
  int index, tamanhoVeiculos, tamanhoProprietarios;

  tamanhoVeiculos = lenLista(veiculos);
  tamanhoProprietarios = lenLista(proprietarios);
  proprietario = (tproprietario *)malloc(sizeof(tproprietario));
  veiculo = (tveiculo *)malloc(sizeof(tveiculo));

  // dois loop for que tratam de tamanhos diferentes (tamanho de lista veiculos e tamanho de lista proprietarios)
  for (index = 0; index < tamanhoVeiculos; index++)
  {
    aux = (tdono *)malloc(sizeof(tdono));
    veiculo = dadoLista(veiculos, index);

    for (int i = 0; i < tamanhoProprietarios; i++)
    {
      auxProp = dadoLista(proprietarios, i);

      // strcmp - utilizando o strcmp para fazer uma comparação entre cpf contido na struct veiculo e o cpf contido na struct proprietario
      if (strcmp(veiculo->cpfdono, auxProp->cpf) == 0)
      {
        proprietario = auxProp;
      }
    }

    // strcpy - novamente utilizado para copiar dados de string para outra, dessa vez de dados de proprietario e de veiculo para dados de dono
    strcpy(aux->cpf, proprietario->cpf);
    strcpy(aux->nome, proprietario->nome);
    strcpy(aux->email, proprietario->email);
    strcpy(aux->placa, veiculo->placa);
    strcpy(aux->modelo, veiculo->modelo);
    strcpy(aux->marca, veiculo->marca);

    appendLista(donos, aux);
  }

  return donos;
}

// Função que, a partir dos dados em tdado, cria um arquivo de saida contendo exatamente o contéudo de tdado
void donosVeiculos(char arquivo[], lista l)
{

  FILE *f_saida = fopen(arquivo, "wt");
  int index;
  tdono *dono = (tdono *)malloc(sizeof(tdono));

  for (index = 0; index < lenLista(l); index++)
  {
    dono = dadoLista(l, index);
    fprintf(f_saida, "%s, %s, %s, %s, %s, %s\n", dono->cpf, dono->nome, dono->email, dono->placa, dono->modelo, dono->marca);
  }

  fclose(f_saida);

  return;
}

// Programa principal com as chamadas das funções
int main()
{

  lista lstProprietarios;
  lista lstVeiculos;
  lista lstSalvaStructsab;

  lstProprietarios = salvaStructA("bdproprietarios.txt");
  lstVeiculos = salvaStructB("bdveiculos_donos.txt");
  lstSalvaStructsab = salvaStrucsAB(lstProprietarios, lstVeiculos);

  donosVeiculos("bdteste3.txt", lstSalvaStructsab);

  return 0;
}