#include <stdio.h>

int main() {
    float nombre, somme = 0.0;
    int i;

    // Saisie des 5 nombres et calcul de la somme
    for (i = 0; i < 5; ++i) {
        printf("Saisir le nombre %d : ", i + 1);
        scanf("%f", &nombre);
        somme += nombre;
    }

    // Calcul de la moyenne
    float moyenne = somme / 5;

    printf("La moyenne des nombres saisis est : %.2f\n", moyenne);

    return 0;
}
