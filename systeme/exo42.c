#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    char command[50];

    while (1) {
        printf(">> ");
        scanf("%s", command);

        pid_t pid = fork();

        if (pid < 0) {
            perror("Erreur lors du fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Processus enfant
            execlp(command, command, NULL);
            perror("Erreur lors de l'exécution de la commande");
            exit(EXIT_FAILURE);
        } else {
            // Processus parent
            wait(NULL); // Attendre la fin de l'exécution de la commande
        }
    }

    return 0;
}
