#include <stdio.h>
#include <stdlib.h>
#include "pair.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Utilisation: %s <entier>\n", argv[0]);
        return 1;
    }

    unsigned int n = atoi(argv[1]);

    if (pair(n)) {
        printf("%u est pair !\n", n);
    } else {
        printf("%u est impair !\n", n);
    }

    return 0;
}

/* TO TEST IT
gcc -c pair.c
gcc -c impair.c
gcc -c spair.c
gcc -o spair spair.o pair.o impair.o*/