#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#define n 10 

int main(){
	int i = 0, k= 0, app = 0; 
	int zaino = 0 ;
	int p[n];
	int elementi[n];
		float rap[n];
	srand(time(NULL));
	int v[n];
	for(i = 0; i < n ; i++){
		p[i] = 1 + rand()%n-1;
		v[i] = 1 + rand()%n-1;
		rap[i] = v[i]*1.0/   p[i];
		elementi[i] = i ; 
	
	}
	

	for(i = 0; i < n ; i++){
	printf("\nelementi\t%d\tpeso\t%d\tvalore\t%d\trapporti\t%f\t\n",elementi [i],p[i],v[i],rap[i]);
	}
	printf("\nordinato\n");


for(i = 0; i< n-1; i++) {
 for(k = 0; k< n-1-i; k++) {
         if(rap[k] < rap[k+1]) {
          app = rap[k];
          rap[k] = rap[k+1];
          rap[k+1] = app;
         }
 }
}

			 
		 
	
	for(i = 0; i < n ; i++){
	printf("\nelementi\t%d\tpeso\t%d\tvalore\t%d\trapporti\t%f\t\n",elementi [i],p[i],v[i],rap[i]);
	}
	

}
