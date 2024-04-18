#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char *argv[])
{
    printf("Dati dello studente:\n");
    printf("Nome: %s\n", argv[1]);
    printf("Cognome: %s\n", argv[2]);
    printf("Età: %s\n", argv[3]);

    return 0;
}