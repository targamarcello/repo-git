#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_DIM 1024

typedef struct {
    FILE *origine;
    FILE *destinazione;
} ThreadData;

void *copy_file(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    char buffer[BUFFER_DIM];
    int letturaByte;
    while ((letturaByte = fread(buffer, 1, BUFFER_DIM, data->origine)) > 0) {
        fwrite(buffer, 1, letturaByte, data->destinazione);
    }
    pthread_exit(NULL);
}
int main() {
    char fileOrigine[100];
    char fileDestinazione[100];
    printf("Inserisci il nome del file sorgente: ");
    scanf("%s", fileOrigine);
    printf("Inserisci il nome del file destinazione: ");
    scanf("%s", fileDestinazione);
    FILE *origine = fopen(fileOrigine, "r");
    if (origine == NULL) {
        printf("Impossibile aprire il file sorgente.\n");
        return 1;
    }

    FILE *destinazione = fopen(fileDestinazione, "w");
    if (fileDestinazione == NULL) {
        printf("Impossibile creare o aprire il file destinazione.\n");
        fclose(origine);
        return 1;
    }
    ThreadData data = {origine, destinazione};
    pthread_t lettura, scrittura;
    pthread_create(&lettura, NULL, copy_file, (void *)&data);
    pthread_create(&scrittura, NULL, copy_file, (void *)&data);
    pthread_join(lettura, NULL);
    pthread_join(scrittura, NULL);
    fclose(origine);
    fclose(destinazione);
    printf("Copia completata con successo.\n");
}