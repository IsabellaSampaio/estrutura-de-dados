/***********************************
 atv8- Criando o TADPILHA.C
 by Isabella Sampaio

************************************/

#include <stdlib.h>
#include "tadpilha.h"

typedef lista Pilha;

Pilha criaPilha(){
    Pilha pilha = criaLista();
    return pilha;
}


tdado empilha(Pilha pilha, tdado dado){
    insertLista(pilha, 0, dado);

}   

tdado desempilha(Pilha pilha){
    tdado dado = dadoLista(pilha, 0);
    removeLista(pilha, 0);  
    return dado;


} 

tdado topoPilha(Pilha pilha){
    primLista(pilha);
    
}


int tamPilha(Pilha pilha){
    return lenLista(pilha);
}


int vaziaPilha(Pilha pilha){
    return (lenLista(pilha)==0);


}

lista pilha2lista(Pilha pilha){
    lista lst = criaLista();
    int i;

    if(!vaziaPilha(pilha)){
        for(i = 0; i < tamPilha(pilha); i++){
            appendLista(lst, dadoLista(pilha, i));
        }
    }

    return lst;
}

