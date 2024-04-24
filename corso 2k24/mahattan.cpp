#include <stdio.h>

int manhattan(int n,int m);

int main(){
	
	manhattan(2,2);
	
	return 0;
}

int manhattan(int n,int m){
	if (n == 0 || m ==0 )return 1;
	else return manhattan( n-1, m) + manhattan( n, m-1);
}


