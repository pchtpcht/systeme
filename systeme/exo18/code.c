#include<stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[], char*env[]){
    if (argc!=2){
        printf("Syntaxe: %s fichier \n",argv[0]);
        return 1;
    }
    int f=open(argv[1],O_RDONLY);
    if (f==-1){
        printf("can't open the file: %s\n",argv[1]);
        return 2;
    }
    char c;
    int n=0;
    while(read(f,&c,1)) n++;
    close(f);
    printf("there are : %d characters\n",n);

}
