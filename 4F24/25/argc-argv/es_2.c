#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int esponenziale;
    if(argc!=3){
        printf("ERRORE DEGLI ARGOMENTI!!");
        return 0;
    }
    int num = atoi(argv[1]);
    int pot = atoi(argv[2]);
    scanf("%d\n", &pot);
    if(num<=0 || pot <0){
        printf("NUMERI NON VALIDI!!");
        return 0;
    }
    esponenziale= pow(num,pot);
    printf("La potenza di %d ^ %d è %d",num, pot, esponenziale);
    
    

    return 0;
}
