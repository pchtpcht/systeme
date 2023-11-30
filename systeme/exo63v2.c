#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

void printPermission(mode_t mode) {
    printf((mode & 0400) ? "r" : "-");
    printf((mode & 0200) ? "w" : "-");
    printf((mode & 0100) ? "x" : "-");
    printf((mode & 0040) ? "r" : "-");
    printf((mode & 0020) ? "w" : "-");
    printf((mode & 0010) ? "x" : "-");
    printf((mode & 0004) ? "r" : "-");
    printf((mode & 0002) ? "w" : "-");
    printf((mode & 0001) ? "x" : "-");
}

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

    printf((S_ISDIR(fileInfo.st_mode)) ? "d" : "-");
    printPermission(fileInfo.st_mode);
    printf("\n");

    return 0;
}
