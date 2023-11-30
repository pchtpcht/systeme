#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Syntaxe: %s <nombre1> <nombre2> ... <nombreN>\n", argv[0]);
        return 1;
    }

    int somme = 0;
    int nbParametres = argc - 1; // Nombre total de paramètres sauf le nom du programme

    // Calcul de la somme des paramètres passés
    for (int i = 1; i < argc; ++i) {
        somme += atoi(argv[i]);
    }

    // Calcul de la moyenne
    float moyenne = (float)somme / nbParametres;

    printf("La moyenne des nombres passés est : %.2f\n", moyenne);

    return 0;
}
