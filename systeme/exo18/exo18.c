#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <nom_fichier>\n", argv[0]);
        return 1;
    }

    char *fichier = argv[1];
    int fd = open(fichier, O_RDONLY);

    if (fd == -1) {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    off_t taille_fichier = lseek(fd, 0, SEEK_END);
    if (taille_fichier == -1) {
        perror("Erreur lors de la récupération de la taille du fichier");
        close(fd);
        return 1;
    }

    printf("Le nombre de caracteres dans %s est : %ld\n", fichier, (long)taille_fichier);

    close(fd);

    return 0;
}
