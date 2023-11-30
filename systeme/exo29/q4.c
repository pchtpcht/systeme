#include <stdio.h>

typedef struct {
    int code;
    char nom[21];
    char dnais[9];
} etudiant;

int main() {
    FILE *fp = fopen("etudiants.bin", "rb");
    if (fp == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    etudiant tabetu[100];
    fread(tabetu, sizeof(etudiant), 100, fp);

    fclose(fp);

    for (int i = 0; tabetu[i].code != 0; ++i) {
        printf("Code: %d, Nom: %s, Date de naissance: %s\n", tabetu[i].code, tabetu[i].nom, tabetu[i].dnais);
    }

    return 0;
}
