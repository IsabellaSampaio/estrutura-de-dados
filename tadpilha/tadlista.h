
/********************************************************
* 
* ESTRUTURA DE DADOS DA LISTA
* 
********************************************************/ 
 
typedef void *tdado;
typedef struct tnoh
{
    tdado dado;
    struct tnoh *proximo;
} tnode;

typedef tnode* pnoh;

typedef struct{
    pnoh primeiro;
    pnoh ultimo;
    int tamanho;
} tcabec;

typedef tcabec* lista;



/********************************************************
* 
* INTERFACE DO TAD LISTA
* 
********************************************************/ 

lista criaLista();
lista appendLista(lista lst, tdado dado);
int lenLista(lista lst);
tdado primLista(lista lst);
tdado ultLista(lista lst);
int indexLista(lista lst, tdado dado);
lista insertLista(lista lst, int index, tdado dado);
lista removeLista(lista lst, int index);
tdado dadoLista(lista lst, int index);