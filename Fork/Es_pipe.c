#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#define MAX 5
int main()
{
    int p, fd[2], status;
    if(pipe(fd)==-1)
    {
        printf("Errore creasion pipe\n");
        exit(-1);
    }
    p=fork();
    if (p==-1)
    {
        printf("Errore creasion figlio\n");
        exit(-1);
    }
    if(p==0)//figlio
    {
        //printf("\nSono il figlio, il mio PID è: %d",getpid());
        close(fd[0]);
        int numeri[MAX];
        printf("\nInserisci 5 numeri interi");
        for(int i=0; i<MAX; i++)
        {
            printf("\nNumero %d: \n",i+1);
            scanf("%d",&numeri[i]);
        }
        write(fd[1],numeri,sizeof(numeri));
        close(fd[1]);
    }
    else//padre
    {
        //printf("\nSono il padre, il mio PID è: %d",getpid());
        close(fd[1]);
        wait(&status);
        int numeriAvuti[MAX];
        int moltiplicatore;
        printf("\nInserisci un numero moltiplicatore: ");
        scanf("%d",moltiplicatore);
        read(fd[0],numeriAvuti,sizeof(numeriAvuti));
        printf("\nNumeri moltiplicati per %d:\n",moltiplicatore);
        for(int i=0; i<MAX; i++)
        {
            printf("%d",numeriAvuti[i]*moltiplicatore);
        }
        close(fd[0]);
    }
    return 0;
}