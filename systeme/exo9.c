#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **strsplit(const char *s, const char sep) {
    int count = 1; // Compte le nombre de séparateurs pour allouer la taille du tableau
    int len = strlen(s);
    for (int i = 0; i < len; ++i) {
        if (s[i] == sep) {
            count++;
        }
    }

    char **result = (char **)malloc((count + 1) * sizeof(char *)); // +1 pour le NULL final
    if (result == NULL) {
        printf("Allocation de mémoire échouée.\n");
        exit(EXIT_FAILURE);
    }

    int idx = 0;
    const char *start = s;
    for (int i = 0; i <= len; ++i) {
        if (s[i] == sep || s[i] == '\0') {
            int length = &s[i] - start;
            result[idx] = (char *)malloc((length + 1) * sizeof(char));
            if (result[idx] == NULL) {
                printf("Allocation de mémoire échouée.\n");
                exit(EXIT_FAILURE);
            }
            strncpy(result[idx], start, length);
            result[idx][length] = '\0';
            start = &s[i + 1];
            idx++;
        }
    }
    result[count] = NULL; // NULL final pour marquer la fin du tableau

    return result;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Syntaxe: %s <chaine> <separateur>\n", argv[0]);
        return 1;
    }

    const char *chaine = argv[1];
    const char separateur = argv[2][0];

    char **resultat = strsplit(chaine, separateur);

    printf("Sous-chaines obtenues :\n");
    for (int i = 0; resultat[i] != NULL; ++i) {
        printf("%d --> %s\n", i, resultat[i]);
        free(resultat[i]); // Libération de la mémoire allouée pour chaque sous-chaîne
    }
    
    free(resultat); // Libération de la mémoire allouée pour le tableau de sous-chaînes

    return 0;
}

