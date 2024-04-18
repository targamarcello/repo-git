#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define NUM 10000
int arrayNum[NUM];
void search(int firstIndex, int lastIndex, int searchValue)
{
    for(int i=firstIndex; i<lastIndex;i++)
    {
        if(arrayNum[i]== searchValue)
        {
            printf("%d\n",i);
        }
    }
}
int main()
{
    int p;
    int numeroDaRicercare;
    for(int i=0; i<NUM; i++)
    {
        arrayNum[i]=rand()%5001;
    }
    printf("inserisci numero da ricercare da 0 a 5000");
    scanf("%d",&numeroDaRicercare);
    p=fork();
    if(p<0)
    exit(1);
    if(p>0)//padre
    {
        search(0,NUM/2,numeroDaRicercare);
    }else//figlio
    {
        search(NUM/2,NUM,numeroDaRicercare);
    }
}