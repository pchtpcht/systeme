#include <stdio.h>

typedef struct {
    int code;
    char nom[21];
    char dnais[9];
} etudiant;

int main() {
    FILE *fp = fopen("etudiants.bin", "wb");
    if (fp == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    etudiant tabetu[100] = {
        {20091234, "dupont", "19891231"},
        {20091235, "martin", "19891130"},
        {0, "", ""}
    };

    fwrite(tabetu, sizeof(etudiant), 100, fp);
    fclose(fp);

    return 0;
}
