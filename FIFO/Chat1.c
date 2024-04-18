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
    mkfifo("fifo1",0777);
    leggi = open("fifo1", O_RDONLY);
    if (leggi == -1)
    {
        perror("Errore apertura");
        exit(-1);
    }
    printf("Shell1 aperta\n");
    while (1)
    {
        printf("Shell 1: ");
        fgets(messaggio, sizeof(messaggio), stdin);
        scrivi = open("fifo2", O_WRONLY);
        printf("Shell2 aperta\n");
        write(scrivi, messaggio, strlen(messaggio) + 1);
        close(scrivi);

        read(leggi, messaggio, sizeof(messaggio));
        printf("Shell 2: %s", messaggio);
    }

    return 0;
}