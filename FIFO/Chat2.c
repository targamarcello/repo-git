#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#define BUFFER_DIM 2048
int main(int argc, char *argv[])
{
    int scrivi, leggi;
    char messaggio[BUFFER_DIM];
    mkfifo("fifo2",0777);
    leggi = open("fifo2", O_RDONLY);
    if (leggi == -1)
    {
        perror("Errore apertuta\n");
        exit(-1);
    }
    printf("Shell1 aperta\n");
    while (1)
    {
        read(leggi, messaggio, sizeof(messaggio));
        printf("Shell 1: %s", messaggio);
        printf("Shell 2: ");
        fgets(messaggio, sizeof(messaggio), stdin);
        scrivi = open("fifo1", O_WRONLY);
        printf("Shell2 aperta\n");

        write(scrivi, messaggio, strlen(messaggio) + 1);
        close(scrivi);
    }

    return 0;
}