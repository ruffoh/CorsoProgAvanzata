#include <stdio.h>

int main (){

int costo = 50;
int i = 0;
int pago = 113;
float soldi[9]= {500,200,100,50,20,10,5,2,1};
int resto = pago - costo;

while(resto > 0){

    if(resto >= soldi[i]){
        resto -= soldi[i];
        printf("soldi usati valgono %f\n",soldi[i]);

    }
i++;
}
















}
