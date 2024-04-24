#include <stdio.h>


int somma(int,int);
int sott(int,int);

int mult(int,int);
int div(int,int);

int main(){
    int x = 5,y = 3;
    printf("LA SOMMA DI %d e %d vale %d\n",x,y,somma(x,y));
	    printf("LA differenza DI %d e %d vale %d\n",x,y,sott(x,y));
	    printf("LA molti DI %d e %d vale %d\n",x,y,mult(x,y));
	    printf("LA dibvi DI %d e %d vale %d\n",x,y,div(x,y));








 return 0;
}
 
 
 
 
    int somma(int x ,int y ){
    if ( y == 0){
        return x;
    }
    else {
        return somma(x+1,y-1);
    }
}
    
        int sott(int x ,int y ){
    if ( y == 0){
        return x;
    }
    else {
        return sott(x-1,y-1);
    }
}
    
         int mult(int x ,int y ){
    if ( y == 0){
        return 0;
    }
    else {
        return x+mult(x,y-1);
    }
}
            int div(int x ,int y ){
    if ( y > x){
        return 0;
    }
    else {
        return 1+div(x-y,y);
    }
}
    

