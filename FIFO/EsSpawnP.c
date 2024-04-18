#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define PROGRAM "./consumatore"
#define BLOCK_DIM 1024
int spawn(char program[], char* argument[])
{
    int p;
    p=fork();
    if(p<0)
    return -1;
    if(p>0)//padre
    return 0;//codice di successo restituito a produttore
    else{
        execv(program, argument);
        printf("ERRORE ESECUZIONE PROGRAMMA CONSUMATORE");
        abort();
    }
}
//padre
int main(int argc, char *argv[])
{
    FILE *file;
    int fifo;
    unsigned char buffer[BLOCK_DIM];//buffer per lettura e scrittura dei blocchi di dati
    int n;
    char *arg[3];
    //controllo errori riga di comando
    if (argc != 3)
    {
        printf("Uso: %s file-origine file-destinazione\r\n", argv[0]);
        return 0;
    }
    // creazione riga di comando
    arg[0] = (char *)malloc(strlen(PROGRAM) + 1);
    strcpy(arg[0], PROGRAM);
    arg[1] = (char *)mallon(strlen(argv[2]) + 1);
    strcpy(arg[1], argv[2]);
    arg[2] = NULL;
    // invocazione programma
    if (spawn(PROGRAM, arg) < 0)
    {
        printf("ERRORE CREAZIONE PROCESSO!!\r\n");
        free(arg[0]); //libera la memoria occupata
        free(arg[1]); //libera la memoria occupata
        return 0;
    }
    //apertura FIFO in scrittura
    fifo=open("my_fifo",O_WRONLY);
    if(fifo<0)
    {
        printf("ERRORE APERTURA FIFO!!!\r\n");
        free(arg[0]); //libera la memoria occupata
        free(arg[1]); //libera la memoria occupata
        return 0;
    }
    //apertura file di origine in lettura
    file=fopen(argv[1],"rb");
    if(file== NULL)
    {
        printf("ERRORE APERTURA FILE!!!\r\n");
        close(fifo); //chiusura FIFO
        free(arg[0]); //libera la memoria occupata
        free(arg[1]); //libera la memoria occupata
        return 0; 
    }
    //lettura da file di blocchi di dati e inserimento nella FIFO
    while((n=fread(buffer,1,sizeof(buffer),file))>0)
    {
        write(fifo,buffer,n);
    }
    fclose(file); //chiusura file origine
    close(fifo); //chiusura FIFO
    free(arg[0]); //libera la memoria occupata 
    free(arg[1]); //libera la memoria occupata
    return 1;
}