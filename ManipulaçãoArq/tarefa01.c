/*Aluna: Isabella Sampaio
   Matrícula: 20211bsi0208
   Exercício : Struct em C 
*/ 

#include <stdio.h>

struct consumidor {
    float totalR, totalC, totalI;
    int numConsumidor;
    char codTipoConsumidor; 
    int qntdKwh;
    float totalPagar;
};

int main() {
    float maiorConsumo, menorConsumo, mediaGeralConsumo;
    float precoKwh = 9.49;
    int aux = 0;
    float somaTotalPagar;
        
    struct consumidor consumidores;

    consumidores.totalR = 0;
    consumidores.totalC = 0;
    consumidores.totalI = 0;

    menorConsumo = 0;
    maiorConsumo = 0;
    
    printf("Numero do consumidor: ");
    scanf("%d", &consumidores.numConsumidor);

    while(consumidores.numConsumidor !=0){
        aux += 1;  
      
        printf("Codigo do tipo de consumidor --> r (residencial), c (comercial), i (industrial): ");
        scanf(" %c", &consumidores.codTipoConsumidor);

        printf("Quantidade de kWh consumidos no mes: ");
        scanf("%d", &consumidores.qntdKwh);  
      

        if(aux==1) {
          maiorConsumo = consumidores.qntdKwh;
          menorConsumo = consumidores.qntdKwh;
          
        } else{
          if (consumidores.qntdKwh > maiorConsumo){
            maiorConsumo =  consumidores.qntdKwh;
          } else if (consumidores.qntdKwh < menorConsumo){
            menorConsumo = consumidores.qntdKwh;
          }
        }

      
        if (consumidores.codTipoConsumidor == 'r') {
          consumidores.totalR += consumidores.qntdKwh; 
          
        } else if (consumidores.codTipoConsumidor == 'c' ) {
          consumidores.totalC += consumidores.qntdKwh;

        } else if (consumidores.codTipoConsumidor == 'i') {
          consumidores.totalI += consumidores.qntdKwh;

        }
        

        consumidores.totalPagar = (consumidores.qntdKwh * precoKwh);
        
        printf("\n------------//------------\n\n");
        printf("Numero do consumidor: %d\n", consumidores.numConsumidor);
        printf("Codigo do tipo de consumidor: %c\n", consumidores.codTipoConsumidor); 
        printf("Quantidade de kWh consumidos no mes: %d\n", consumidores.qntdKwh);
        printf("Total a pagar: R$ %.2f\n\n", consumidores.totalPagar);
        printf("------------//------------\n\n");

        printf("Numero do consumidor: ");
        scanf("%d", &consumidores.numConsumidor);            
                  
    }

   
    mediaGeralConsumo = (consumidores.totalR+consumidores.totalC+consumidores.totalI)/aux;
    printf("\nO maior consumo eh : %.2f\n", maiorConsumo);
    printf("O menor consumo eh: %.2f\n", menorConsumo);
    printf("A media geral de consumo eh: %.2f\n\n", mediaGeralConsumo);
        
    return 0;

    
}   