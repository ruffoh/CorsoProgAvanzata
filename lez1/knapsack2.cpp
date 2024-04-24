#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#define n 10
int pesi [n];
int valori[n];
float rapporti[n];
int inserisci[n];
int zaino = 20 ; 
void riempiArray();
void ordinaPerRapporto();
void inserisciNelloZaino();
void stampa ();





int main(){
 	srand(time(NULL));
riempiArray();
stampa();
ordinaPerRapporto();
stampa();
inserisciNelloZaino();



return 0; 
}

void riempiArray(){
	for(int i = 0; i < n; i ++){
		pesi[i] =  rand()%9+1;
		valori[i] =  rand()%9+1;
		rapporti[i] = valori[i]*1.0/   pesi[i];
		inserisci[i] = 0; 
	}
}
void stampa (){
	printf("\n");
	for (int i = 0; i < n; i++){
		printf("\tpeso\t%d\tvalore\t%d\trapporti\t%f\t\n",pesi[i],valori[i],rapporti[i]);
		//cout<< "peso" << pesi[i]<< "\tvalore:" << valori[i]<<"\trapporto"<< rapporti[i];
	}
}
void ordinaPerRapporto(){
	bool flag = false;
	int i = 0; 
	do{
		for (int j = 0; j < n -i -1;j++){
			if (rapporti[j] < rapporti[j+1]){
				int app = rapporti[j];
				rapporti[j] = rapporti[j+1]; 
				rapporti[j +1] = app; 
				
				int t  = valori[j];
				valori[j] = valori[j+1]; 
				valori[j +1] = t; 
				
				 t  = pesi[j];
				pesi[j] = pesi[j+1]; 
				pesi[j +1] = t;
				 
			
			
			
				flag = false; 
			}
		}
		i++;
	}while(flag && i < n );
	
}


void inserisciNelloZaino(){
	int spazioDisponibile = zaino;
	int valore = 0; 
	for (int i = 0; i < n ; i++)
		if(spazioDisponibile >= pesi[i]){
			printf("\tpeso\t%d\tvalore\t%d\trapporti\t%f\t\n",pesi[i],valori[i],rapporti[i]);
			spazioDisponibile -= pesi[i];
			valore += valori[i];
		}
}
