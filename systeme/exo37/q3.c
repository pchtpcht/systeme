#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Texte quelconque...\n");
    execlp("gcc", "gcc", "code_source.c", "-o", "nom_executable", NULL);
    return 0;
}
