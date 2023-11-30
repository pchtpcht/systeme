#include<stdio.h>
int conversioncar(char *c){
    int total=0;
    int i=0;
    if (c==NULL) return 0;
    while(c[i]!='\0' && c[i]>='0' && c[i]<='9'){
        total=total*10+c[i]-'0';
        i++;
    }
    return total;
}
 int main(){
    char c[]="3546";
    printf("la conversion: %d \n",conversioncar(c));
   
}