#include <stdio.h>
#include <stdlib.h>
int impair(unsigned int i);
int pair(int i){
if (i==0)
return 1;
else
return impair(i-1);
 }
int impair(unsigned int i){
if (i==0)
return 0;
else
return pair(i-1);
}
int main(int argc, char *argv[], char *env[]) {
if (argc!=2){
printf("Syntaxe : %s fichier\n",argv[0]);
return 1;
/* syntaxe */
}
int n=atoi(argv[1]);
if (pair(n))
printf("%i est pair !\n",n);
else
printf("%i est impair !\n",n);
return 0;
/* OK */
}
