#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <string.h>
//bisogna far comunicare il padre e il figlio con delle pipe
#define BUFFER_DIM 1024
int main()
{
    //dichiarazione var
    int fd[2];
    int p;
    char buffer[BUFFER_DIM];
    if(pipe(fd)== -1) //generazione pipe
    {
        printf("errore nella generazione della pipe");
        exit(-1);
    }
    p=fork();
    if(p<0)
    {
        printf("ERRORE!!!!");
    }
    if(p>0)//padre
    {
        printf("Sono il padre con PID=%d, mio figlio ha PID=%d", getpid(), p);
        close(fd[0]);//padre chiude in lettura
        const char *messaggio ="BUONA FORTUNA";
        if(write(fd[1],messaggio, strlen(messaggio))==-1)
        {
            printf("ERRORE!!!");
            exit(-1);
        }
        close(fd[1]);
    }else //figlio
    {
        printf("\nSono il figlio con PID=%d, mio padre ha PID=%d",getpid(), getppid());
        close(fd[1]);//figlio chiude in scrittura
        n=read(fd[0], buffer, BUFFER_DIM);
        if(n==-1)
        {
            printf("ERRORE!!!");
            exit(-1);
        }else
        {
            buffer[n]='\0';
            printf("messaggio ricevuto: %s\n",buffer);
            close(fd[0]);
        }
    }

    return 0;
}