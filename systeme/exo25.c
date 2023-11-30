#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

void reject_characters(FILE *file, int num_chars) {
    if (file == NULL || num_chars <= 0) {
        fprintf(stderr, "Paramètres invalides.\n");
        return;
    }

    char buffer[MAX_BUFFER_SIZE];
    int read_chars = fread(buffer, sizeof(char), num_chars, file);
    buffer[read_chars] = '\0'; // Ajout du caractère de fin de chaîne

    printf("%s", buffer);
}

void reject_lines(FILE *file, int num_lines) {
    if (file == NULL || num_lines <= 0) {
        fprintf(stderr, "Paramètres invalides.\n");
        return;
    }

    char buffer[MAX_BUFFER_SIZE];
    for (int i = 0; i < num_lines; ++i) {
        if (fgets(buffer, sizeof(buffer), file) == NULL) {
            fprintf(stderr, "Le fichier contient moins de %d lignes.\n", num_lines);
            return;
        }
        printf("%s", buffer);
    }
}

int main(int argc, char *argv[]) {
    int num;
    char option;
    FILE *file;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s -c<number_of_chars>/-l<number_of_lines> [file1 file2 ...]\n", argv[0]);
        return 1;
    }

    if (sscanf(argv[1], "-c%d", &num) == 1) {
        option = 'c';
    } else if (sscanf(argv[1], "-l%d", &num) == 1) {
        option = 'l';
    } else {
        fprintf(stderr, "Option invalide. Utilisez -c<number_of_chars> ou -l<number_of_lines>.\n");
        return 1;
    }

    if (argc == 2) {
        if (option == 'c') {
            reject_characters(stdin, num);
        } else if (option == 'l') {
            reject_lines(stdin, num);
        }
    } else {
        for (int i = 2; i < argc; ++i) {
            file = fopen(argv[i], "r");
            if (file == NULL) {
                perror("Erreur lors de l'ouverture du fichier");
                return 1;
            }

            if (option == 'c') {
                reject_characters(file, num);
            } else if (option == 'l') {
                reject_lines(file, num);
            }

            fclose(file);
        }
    }

    return 0;
}
