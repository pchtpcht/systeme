#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reject_characters(FILE *file, int num_chars) {
    if (file == NULL || num_chars <= 0) {
        printf("Parametres invalides.\n");
        return;
    }

    char buffer[num_chars + 1]; // Taille du buffer pour stocker les caractères
    int read_chars = fread(buffer, sizeof(char), num_chars, file);
    buffer[read_chars] = '\0'; // Ajout du caractère de fin de chaîne

    printf("Les %d premiers caracteres ont ete rejetes :\n%s\n", num_chars, buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 3 || argv[2][0] != '-' || argv[2][1] != 'c') {
        printf("Usage: %s <fichier> -c<nombre_de_caracteres>\n", argv[0]);
        return 1;
    }

    char *file_name = argv[1];
    int num_chars = atoi(argv[2] + 2); // Ignorer les deux premiers caractères (-c)

    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    reject_characters(file, num_chars);

    fclose(file);
    return 0;
}
