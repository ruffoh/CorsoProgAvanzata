#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define dim 3
int main(){
	srand(time(NULL));
	int p[dim]; // peso 
	int v[dim]; // valore
	float f[dim]; //rapp
	int i = 0;
	
	for( i = 0; i < dim ;i++){

		p[i] = rand()%5+1;
		v[i] = rand()%5+1;
		f[i] = (float)v[i]/p[i];
	}
	




return 0 ;
}

