#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <nom_fichier>\n", argv[0]);
        return 1;
    }

    char *fichier = argv[1];
    FILE *file = fopen(fichier, "r");

    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long taille_fichier = ftell(file);

    if (taille_fichier == -1) {
        perror("Erreur lors de la récupération de la taille du fichier");
        fclose(file);
        return 1;
    }

    printf("Le nombre de caracteres dans %s est : %ld\n", fichier, taille_fichier);

    fclose(file);

    return 0;
}
