
#include <stdio.h>
int f(int n);
int main (){

printf("%d",f(5));

return 0; 

}


int f(int n){
	if(n==0){               // caso base
		return 1;
	}
	else					// caso ricorsivo 
		return n*f(n-1);
	
}
