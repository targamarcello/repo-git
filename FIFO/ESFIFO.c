#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>//libreria per aprire una FIFO
int main ()
{
    //Dichiarazione delle variabili
    int fd;
    //int x=90;
    //Creazione FIFO
    if(mkfifo("FIFO1",0777)==-1)
    {
        if(errno!=EEXIST)
        {
        printf("\nERRORE FIFO!!!");
        return 1;
        }
    }
    //Apro la FIFO in scrittura
    fd=open("FIFO1", O_WRONLY); //fd=1 poichè ho aperto la FIFO in scrittura
    printf("\nHo aperto la FIFO");
    int x=90;
    if(write(fd, &x, sizeof(x)))
    {
        printf("\nerrore scrittura nella FIFO");
        return 2;
    }
    printf("\nSuccesso scrittura FIFO");
    close(fd);
    return 0;
}