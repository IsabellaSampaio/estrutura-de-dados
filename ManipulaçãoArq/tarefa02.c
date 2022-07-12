/*Aluna: Isabella Sampaio
   Matrícula: 20211bsi0208
   Exercício : Arrays em C 
*/ 
 
#include <stdio.h>

int intercessao(int vetorA[], int tamVetorA,  int vetorB[], int tamVetorB, int vetorI[], int tamVetorI)
{

    int i = 0;
    int j = 0;
    int pos = 0;

    
    for (i < tamVetorA ; j < tamVetorB;){
        if(vetorA[i] < vetorB[j]){
            i++;
        }
        else if (vetorA[i] > vetorB[j]){
            j++;
        }
        else {
            vetorI[pos] = vetorA[i];
            i++;
            j++;
            pos++;
        }
                
    }

    return pos;
}


int main()
{
    
    int vetorA[10] = {0,2,4,6,8,10,12,14,16,18};
    int vetorB[10] = {1,2,3,4,5,6,7,8,9,10};
    int vetorI[10] = {0};
    
    int tamVetorA, tamVetorB, tamVetorI;

    tamVetorA = 10;
    tamVetorB = 10;
    tamVetorI= 10;

    int i = 0;
    int pos = 0;

    pos = intercessao(vetorA, tamVetorA, vetorB, tamVetorB,  vetorI, tamVetorI);

    printf("O conjunto intercessao eh:\n");
    for (i = 0; i < pos; i++)
        printf("%d\t", vetorI[i]);

    printf("\n");

    return 0;
}