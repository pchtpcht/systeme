#include <stdio.h>
#include <unistd.h>

int main() {
    int value = 42;
    pid_t pid = fork();

    if (pid == -1) {
        perror("Erreur lors du fork");
        return 1;
    }

    if (pid == 0) {
        // Code exécuté par le processus enfant
        printf("Processus enfant - Valeur : %d\n", value); // Affiche la valeur de la variable dans le processus enfant
        value = 10; // Modifie la valeur dans le processus enfant
    } else {
        // Code exécuté par le processus parent
        printf("Processus parent - Valeur : %d\n", value); // Affiche la valeur de la variable dans le processus parent
        value = 99; // Modifie la valeur dans le processus parent
    }

    printf("Valeur après la modification : %d\n", value); // Affiche la valeur après la modification dans chaque processus
    return 0;
}
