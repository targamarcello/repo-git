#include <stdio.h>
int main(int argc,char*agrv[]){
    
    int N;
    do{
        printf("Inserisci N\n");
        scanf("%d", &N);
    }while(N<1);
    
    printf("Numero intero successivo: %d",N+1);
    return 0;
}
