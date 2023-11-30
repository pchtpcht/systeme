#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <file> : <field_number> <value>\n", argv[0]);
        return 1;
    }

    char *file_name = argv[1];
    int field_number = atoi(argv[3]);
    char *value = argv[4];

    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file) != NULL) {
        char *token;
        int current_field = 0;

        // Séparer la ligne en articles en utilisant le séparateur ":"
        token = strtok(line, ":");
        while (token != NULL) {
            current_field++;

            // Vérifier si le champ correspond au champ spécifié dans les critères de sélection
            if (current_field == field_number && strcmp(token, value) == 0) {
                printf("%s", line); // Afficher la ligne complète
                break;
            }

            token = strtok(NULL, ":");
        }
    }

    fclose(file);
    return 0;
}
// to try: ./monselect "C:\Users\MOON\testfile.txt" : 3 45
