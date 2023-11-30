#include<stdio.h>
#include<stdlib.h>

char* tochain(int n){
    int nombre = n;
    int taille = 0;

    if (nombre == 0) {
        char* chaine = (char*)malloc(2 * sizeof(char)); // Allouer de la mémoire pour la chaîne "0\0"
        if (chaine == NULL) {
            printf("Allocation de mémoire échouée.\n");
            exit(EXIT_FAILURE);
        }
        chaine[0] = '0';
        chaine[1] = '\0';
        return chaine;
    }

    while (nombre > 0) {
        nombre = (nombre - (nombre % 10)) / 10;
        taille++;
    }

    char* chaine = (char*)malloc((taille + 1) * sizeof(char)); // +1 pour le caractère de fin de chaîne '\0'
    if (chaine == NULL) {
        printf("Allocation de mémoire échouée.\n");
        exit(EXIT_FAILURE);
    }

    nombre = n;
    for (int i = 0; i < taille; i++) {
        int chiffre = nombre % 10;
        chaine[taille - i - 1] = chiffre + '0';
        nombre = (nombre - (nombre % 10)) / 10;
    }
    chaine[taille] = '\0';

    return chaine;
}

int main(){
    char* ma_chaine = tochain(120);
    printf("La chaine est: %s \n", ma_chaine);
    free(ma_chaine); // Libérer la mémoire allouée pour la chaîne
    return 0;
}
