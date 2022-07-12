/****************************
* atv5 - Criando o TADFILA.C
* by Isabella Sampaio
* 
****************************/

// Includes importantes
#include <stdlib.h>
#include "tadfila.h"

// Definindo que Fila é do tipo lista
typedef lista Fila;


// As funções 
Fila criaFila(){
    Fila fila = criaLista();
    return fila;
}

tdado enfileira(Fila fila, tdado dado){
    appendLista(fila, dado);
}

tdado desenfileira(Fila fila){
   tdado dado = dadoLista(fila, 0); 
   removeLista(fila, 0);
   return dado;
   
}
tdado cabecaFila(Fila fila){
    return primLista(fila);
}
tdado caudaFila(Fila fila){
    return ultLista(fila);
}

int tamFila(Fila fila){
    return lenLista(fila);
}
int vaziaFila(Fila fila){
    return (lenLista(fila)==0); 

}

lista fila2lista(Fila fila){
    lista lst = criaLista();
    int i;

    if(!vaziaFila(fila)){
        for(i = 0; i < lenLista(fila); i++){
            appendLista(lst, dadoLista(fila, i));
        }
    }

    return lst;
}