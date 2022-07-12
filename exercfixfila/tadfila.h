/*******************
* atv5- Criando o TADFILA.H
* by Isabella Sampaio
*
********************/

#ifndef TADFILA_H_
#define TADFILA_H_
#include "tadlista.h"

typedef lista Fila;

Fila criaFila();
tdado enfileira(Fila fila, tdado dado);
tdado desenfileira(Fila fila);
tdado cabecaFila(Fila fila);
tdado caudaFila(Fila fila);
int tamFila(Fila fila);
int vaziaFila(Fila fila);
lista fila2lista(Fila fila);

#endif