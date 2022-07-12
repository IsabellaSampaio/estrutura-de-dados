/*********************************
 atv8- Criando o TADPILHA.H
 by Isabella Sampaio

**********************************/


#ifndef TADFILA_H_
#define TADFILA_H_
#include "tadlista.h"

typedef lista Pilha;

Pilha criaPilha();
tdado empilha(Pilha pilha, tdado dado);
tdado desempilha(Pilha pilha);
tdado topoPilha(Pilha pilha);
int tamPilha(Pilha pilha);
int vaziaPilha(Pilha pilha);
lista pilha2lista(Pilha pilha);


#endif






