#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Texte quelconque...\n");
    fflush(stdout); // Pour vider le buffer de sortie avant de changer le programme

    execl("/bin/ls", "ls", "-l", "/bin", NULL);
    return 0;
}
