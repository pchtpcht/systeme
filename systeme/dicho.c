#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
int rechercheDichotomique(int fileDescriptor, char c) {
    struct stat st;
    fstat(fileDescriptor, &st);
    int debut = 0;
    int fin = st.st_size - 1;

    while (debut <= fin) {
        int milieu = debut + (fin - debut) / 2;
        lseek(fileDescriptor, milieu, SEEK_SET);
        char charMilieu;
        read(fileDescriptor, &charMilieu, sizeof(char));

        if (charMilieu == c) {
            return milieu + 1;
        } else if (charMilieu < c) {
            debut = milieu + 1;
        } else {
            fin = milieu - 1;
        }
    }

    return -1;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Utilisation: %s fichier_caracteres caractere_recherche\n", argv[0]);
        return 1;
    }

    int fileDescriptor = open(argv[1], O_RDONLY);
    if (fileDescriptor == -1) {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    char caractere = argv[2][0];
    int position = rechercheDichotomique(fileDescriptor, caractere);

    if (position != -1) {
        printf("Le caractère '%c' est en position %d dans le fichier.\n", caractere, position-1);
    } else {
        printf("Le caractère '%c' n'a pas été trouvé dans le fichier.\n", caractere);
    }

    close(fileDescriptor);
    return 0;
}
