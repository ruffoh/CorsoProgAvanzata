#include <stdio.h>

int somma(int a,int b);
int moltiplicazione(int a,int b);
int divisione(int a,int b;
              int modulo(int a ,int b );

int main() {

	printf("%d",modulo(10,8));

	return 0;
}

int somma(int a,int b) {
	if (b == 0) return a;
	else return somma(a+1,b-1);
}
int moltiplicazione(int a,int b) {

	if (b == 0) return 0;
	else return a+moltiplicazione(a,b-1);
}
int divisione(int a,int b) {

	if (a == 0) return 0;
	else return  1+divisione(a-b,b);
}

int modulo(int a ,int b ) {

	if (a < b ) {
		return a ;
	} else return modulo(a-b,b);
}
