#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINES 1000
#define MAX_LINE_LENGTH 1024

void reject_lines(FILE *file, int num_lines) {
    if (file == NULL || num_lines <= 0) {
        printf("Paramètres invalides.\n");
        return;
    }

    char buffer[MAX_LINE_LENGTH]; // Taille du buffer pour stocker chaque ligne
    char* rejected_lines[MAX_LINES]; // Tableau pour stocker les lignes rejetées
    int count = 0;
    int rejected_count = 0;

    while (count < num_lines) {
        if (fgets(buffer, sizeof(buffer), file) == NULL) {
            printf("Le fichier contient moins de %d lignes.\n", num_lines);
            return;
        }
        rejected_lines[rejected_count] = malloc(strlen(buffer) + 1);
        strcpy(rejected_lines[rejected_count], buffer);
        rejected_count++;
        count++;
    }

    printf("Les %d premieres lignes ont ete rejetees.\n", num_lines);

    printf("Lignes rejetees :\n");
    for (int i = 0; i < rejected_count; i++) {
        printf("%s", rejected_lines[i]);
        free(rejected_lines[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <fichier> <nombre_de_lignes>\n", argv[0]);
        return 1;
    }

    char *file_name = argv[1];
    int num_lines = atoi(argv[2]);

    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    reject_lines(file, num_lines);

    fclose(file);
    return 0;
}
// to test: head fich.txt 2