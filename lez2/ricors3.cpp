#include <stdio.h>
int manhattan(int,int);

int main(){
	int n = 4;
	int m = 4; 
	printf("%d modi possibili\n",manhattan(n,m));
	
	
	
	
	return 0; 
}


int manhattan(int n,int m){
	if (n==1 || m == 1) return 1 ; 
	else return manhattan(n-1,m) + manhattan(n,m-1);
}
