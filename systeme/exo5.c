#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv, char **env){
    int i;
    for(i=0; i<argc; i++){
        printf("%d : %s\n", i, argv[i]);
    }
    i=0;
    while(env[i]){
        printf("%d : %s\n", i, env[i]);
        i++;
    }
    return 0;

}