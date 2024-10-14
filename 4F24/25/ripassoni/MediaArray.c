#include <stdio.h>
#include <stdlib.h>

float calcolaMedia(int* array, int dimensione) {
    int somma = 0;
    for (int i = 0; i < dimensione; i++) {
        somma += array[i];
    }
    return (float)somma / dimensione;
}

void inserisciValori(int* array, int dimensione) {
    for (int i = 0; i < dimensione; i++) {
        printf("Inserisci il valore %d: ", i + 1);
        scanf("%d", &array[i]);
    }
}

int main() {
    int dimensione;

    printf("Inserisci la dimensione dell'array: ");
    scanf("%d", &dimensione);

    int* array = (int)malloc(dimensione sizeof(int));
    if (array == NULL) {
        printf("Errore nell'allocazione della memoria.\n");
        return 1;
    }

    inserisciValori(array, dimensione);

    float media = calcolaMedia(array, dimensione);
    printf("La media dei valori inseriti è: %.2f\n", media);

    return 0;
}
