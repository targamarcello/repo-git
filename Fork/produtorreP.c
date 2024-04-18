#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define PROGRAM "./consumatore"
#define BUFFER_DIM 2048
int spawn(char *program[], char *argument[])
{
    int p;
    printf("sono il padre spawn");
    p = fork();
    if (p < 0)
    {
        perror("ERRORE CREAZIONE FIGLIO!!");
        exit(-1);
    }
    else if (p > 0) // padre
    {
        printf("sono di nuovo il padre con PID %d", p);
        return 0;
    }
    else // figlio
    {
        printf("sono figlio con PID %d", getpid());
        execv(program, argument);

        // se si arriva qua allora execv non ha funzionato
        printf("errore esecuzione processo 2");
        abort();
    }
}

int main(int argc, char *argv[])
{
    FILE *file;
    int fifo;
    unsigned char buffer[BUFFER_DIM];
    int n, a;
    char *arg[3];
    printf("sono padre main ossia il processo produttore, il mio PID è %d", getpid());
    if (argc != 3)
    {
        printf("ERRORE!!");
        return 0;
    }
    arg[0] = (char *)malloc(strlen(PROGRAM) + 1);
    strcpy(arg[0], PROGRAM);
    arg[1] = (char *)malloc(strlen(argv[2]) + 1);
    strcpy(arg[1], argv[2]);
    arg[2] = NULL;

    if (spawn (PROGRAM,arg)<0)
    {
        printf("errore creazione processo figlio");
        free(arg[0]);
        free(arg[1]);
        return 0;
    }
    file=fopen(argv[1],"rb");
    
        return 0;
}