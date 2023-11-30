#include <stdio.h>

// Recherche dichotomique du caractère dans le fichier
int rechercheDichotomique(FILE *file, char c) {
    int debut = 0;
    fseek(file, 0, SEEK_END);
    int fin = ftell(file) - 1;

    while (debut <= fin) {
        int milieu = debut + (fin - debut) / 2;
        fseek(file, milieu, SEEK_SET);
        char charMilieu = fgetc(file);

        if (charMilieu == c) {
            return milieu + 1; // Position du caractère dans le fichier (à partir de 1)
        } else if (charMilieu < c) {
            debut = milieu + 1;
        } else {
            fin = milieu - 1;
        }
    }

    return -1; // Caractère non trouvé
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Utilisation: %s fichier_caracteres caractere_recherche\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    char caractere = argv[2][0];
    int position = rechercheDichotomique(file, caractere);

    if (position != -1) {
        printf("Le caractere '%c' est en position %d dans le fichier.\n", caractere, position-1);
    } else {
        printf("Le caractere '%c' n'a pas ete trouve dans le fichier.\n", caractere);
    }

    fclose(file);
    return 0;
}
