#include <stdio.h>

typedef struct {
    int code;
    char nom[21];
    char dnais[9];
} etudiant;

int main() {
    etudiant tabetu[100] = {
        {20091234, "dupont", "19891231"},
        {20091235, "martin", "19891130"},
        {0, "", ""}
    };

    printf("Tableau des etudiants :\n");
    for (int i = 0; tabetu[i].code != 0; ++i) {
        printf("Code : %d, Nom : %s, Date de naissance : %s\n", tabetu[i].code, tabetu[i].nom, tabetu[i].dnais);
    }

    return 0;
}
