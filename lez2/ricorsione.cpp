#include <stdio.h>
#include <iostream>

using namespace std;

int fattoriale (int );



int main(){
int  n = 5;
int fatt = 1;
for(int i  = 1; i <= n; i ++ )
    fatt = fatt*i ;

    printf("modo iterativo %d\n",fatt);
    printf("modo ricorsivo %d\n",fattoriale(n)) ;





return 0;
}

int fattoriale (int n  ){
    if (n == 0){
            return 1;}
    else{
        return n*fattoriale(n-1);
    }



    }

int main(){
}





