#include <stdio.h>
#include <time.h>
#define N 10
int max  (int,int);
int lunghezze[N+1] = {-1,1,2,3,4,5,6,7,8,9,10};
int prezzi[N+1] = {-1,1,5,8,9,10,17,17,20,24,30};
int rc(int n){

if (n == 0) return 0 ;

else {
    int massimo  = -1;
    for(int i = 1 ; i <= n ; i++){
    massimo = max(massimo,prezzi[i]+ rc(n -lunghezze[i]));}
    return massimo;
}
}






int main(){
clock_t start_t, end_t;
   double total_t;
   clock_t start,end;
start_t = clock();
printf("\n %d \n", rc(lunghezze[N]));
end_t = clock();


printf("TEMPO DI ESECUZIONE : %d",end_t - start_t);




    return 0; }

int max (int a , int b ){
return (a > b ? a : b );
}
