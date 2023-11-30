#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <nom_fichier>\n", argv[0]);
        return 1;
    }

    struct stat fileInfo;
    if (stat(argv[1], &fileInfo) == -1) {
        perror("Erreur lors de la lecture des informations sur le fichier");
        return 1;
    }

    if (S_ISREG(fileInfo.st_mode)) {
        printf("%s est un fichier régulier.\n", argv[1]);
    } else if (S_ISDIR(fileInfo.st_mode)) {
        printf("%s est un répertoire.\n", argv[1]);
    } else if (S_ISLNK(fileInfo.st_mode)) {
        printf("%s est un lien symbolique.\n", argv[1]);
    } else {
        printf("%s est d'un type différent.\n", argv[1]);
    }

    return 0;
}
